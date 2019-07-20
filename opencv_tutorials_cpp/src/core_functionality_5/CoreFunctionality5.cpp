/*
 * CoreFunctionality5.cpp
 *
 * This teaches brightness and contrast of images.
 *
 *  Created on: Jul 19, 2019
 *      Author: kmcgill
 */

#include "CoreFunctionality5.h"


int CoreFunctionality5::run(std::string filename){
	printf("Starting Core Functionality 5...\n");

	cv::Mat src, dst;
	src = cv::imread(filename, cv::IMREAD_COLOR);
	if(src.empty()){
		printf("Unable to read %s\n", filename.c_str());
		return -1;
	}

	dst = cv::Mat::zeros(src.size(), src.type());

	// Using the formula g(x) = alpha * f(x) + beta
	double alpha = 0.6;
	int beta = 200;

	for(int i = 0; i < src.rows; ++i){
		for(int j = 0; j < src.cols; ++j){
			for(int c = 0; c < src.channels(); ++c){
																	// here is our formula
				dst.at<cv::Vec3b>(i,j)[c] = cv::saturate_cast<uchar>(alpha * src.at<cv::Vec3b>(i,j)[c] + beta);
			}
		}
	}

	cv::imshow("Original", src);
	cv::imshow("New Image", dst);
	cv::waitKey(0);
	return 0;
}
