/*
 * CoreFunctionality3.cpp
 *
 *  Created on: Apr 6, 2019
 *      Author: kmcgill
 */

#include "CoreFunctionality3.h"

/**
 * Main purpose of this tutorial is to teach how
 * to use masks on images. Things like sharpeners and softeners
 * would fall into this category.
 */
int CoreFunctionality3::run(std::string filename){
	printf("Starting Core Functionality 3 tutorial...\n");
	int times = 100; //according to the tutorial, this is a good number
	int millisPerSec = 1000;


	cv::Mat src, dst0, dst1;
	src = cv::imread(filename.c_str(), cv::IMREAD_COLOR);

	if(src.empty()){
		printf("Unable to read %s\n", filename.c_str());
		return -1;
	}

	//Create the windows for the images
	cv::namedWindow("Input", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Output Custom", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Output Lib", cv::WINDOW_AUTOSIZE);

	cv::imshow("Input", src);
	double t = (double)cv::getTickCount();

	sharpen(src, dst0);

	t = millisPerSec * ((double)cv::getTickCount() - t) / cv::getTickFrequency(); //total run time
	t /= times;
	printf("Completed sharpening using custom method in %.3f millis\n", t);


	cv::imshow("Output Custom", dst0);

	t = (double)cv::getTickCount();

	sharpen_using_kernel(src, dst1);

	t = millisPerSec * ((double)cv::getTickCount() - t) / cv::getTickFrequency(); //total run time
	t /= times;
	printf("Completed sharpening kernel + lib in %.3f millis\n", t);
	cv::imshow("Output Lib", dst1);

	cv::waitKey(0);

	printf("Done with Core Functionality 3.\n");
	return 0;
}

void CoreFunctionality3::sharpen(const cv::Mat& src, cv::Mat& dst){

	CV_Assert(src.depth() == CV_8U);

	const int nChannels = src.channels();
	dst.create(src.size(), src.type());

	for(int j = 1; j < src.rows-1; ++j){
		const uint8_t* previous = src.ptr<uint8_t>(j-1);
		const uint8_t* current = src.ptr<uint8_t>(j);
		const uint8_t* next = src.ptr<uint8_t>(j+1);

		uint8_t* output = dst.ptr<uint8_t>(j);
		for(int i = nChannels; i < (nChannels * (src.cols-1)); ++i){
			/*
			 * Applies the matrix M = [[ 0 -1  0]
			 * 						   [-1  5 -1]
			 * 						   [ 0 -1  0]]
			 */
			*output++ = cv::saturate_cast<uint8_t>(5*current[i] - current[i-nChannels] - current[i+nChannels] - previous[i] - next[i]);
		}
	}

	// want to set the borders to 0 for undefined
	dst.row(0).setTo(cv::Scalar(0));
	dst.row(dst.rows-1).setTo(cv::Scalar(0));
	dst.col(0).setTo(cv::Scalar(0));
	dst.col(dst.cols-1).setTo(cv::Scalar(0));
}

void CoreFunctionality3::sharpen_using_kernel(const cv::Mat& src, cv::Mat& dst){
	cv::Mat kernel = (cv::Mat_<char>(3,3) << 0, -1, 0,
											-1,  5, -1,
											 0, -1,  0);

	cv::filter2D(src, dst, src.depth(), kernel);
}
