/*
 * CoreFunctionality6.cpp
 *
 * The purpose of this tutorial is to learn about
 * DFT and its use in image processing
 *
 *  Created on: Jul 19, 2019
 *      Author: kmcgill
 */

#include "CoreFunctionality6.h"

int CoreFunctionality6::run(std::string filename){
	printf("Starting Core Functionality 6...\n");

	cv::Mat src = cv::imread(filename, cv::IMREAD_GRAYSCALE);
	if(src.empty()){
		printf("Unable to read %s\n", filename.c_str());
		return -1;
	}

	//Doing DFT is faster if the row and col are a multiple of 2,3, or 5
	cv::Mat padded;
	int m = cv::getOptimalDFTSize(src.rows);
	int n = cv::getOptimalDFTSize(src.cols);

	//the function copies the source image into the middle of the destination image.
	cv::copyMakeBorder(src, padded, 0, m - src.rows, 0, n - src.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));

	cv::Mat planes[] = {cv::Mat_<float>(padded), cv::Mat::zeros(padded.size(), CV_32F)};
	cv::Mat complex;
	cv::merge(planes, 2, complex); //merge() = Creates one multi-channel array out of several single-channel ones.
	cv::dft(complex, complex); //the result will now fit in the src matrix

	// compute the magnitude and switch to logarithmic scale
	// => log(1 + sqrt(Re(DFT(I))^2 + Im(DFT(I))^2))
	cv::split(complex, planes);
	cv::magnitude(planes[0], planes[1], planes[0]);
	cv::Mat magSrc = planes[0];

	//switch to log scale
	magSrc += cv::Scalar::all(1);
	cv::log(magSrc, magSrc);

	//crop the spectrum in the case of an odd number of rows or cols
	magSrc = magSrc(cv::Rect(0, 0, magSrc.cols & -2, magSrc.rows & -2));

	//rearrange the quadrants of the Fourier Image so that the origin is at the center of the picture
	int cx = magSrc.cols/2;
	int cy = magSrc.rows/2;

	//get the quadrants so we can swap them around
	cv::Mat q0(magSrc, cv::Rect(0, 0, cx, cy)); //Top Left
	cv::Mat q1(magSrc, cv::Rect(cx, 0, cx, cy)); //Top Right
	cv::Mat q2(magSrc, cv::Rect(0, cy, cx, cy)); //Bot Left
	cv::Mat q3(magSrc, cv::Rect(cx, cy, cx, cy)); //Bot Right

	cv::Mat tmp;
	q0.copyTo(tmp);
	q3.copyTo(q0);
	tmp.copyTo(q3);

	q1.copyTo(tmp);
	q2.copyTo(q1);
	tmp.copyTo(q2);

	cv::normalize(magSrc, magSrc, 0, 1, cv::NORM_MINMAX); //makes the transform matrix in the form of grey between [0,1]
	cv::imshow("Input Imange", src);
	cv::imshow("DFT Imange",  magSrc);
	cv::waitKey(0);




	return 0;
}


