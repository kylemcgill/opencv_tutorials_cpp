/*
 * CoreFunctionality4.cpp
 *
 * This tutorial does blending of 2 images
 *
 *  Created on: Jul 19, 2019
 *      Author: kmcgill
 */

#include "CoreFunctionality4.h"

int CoreFunctionality4::run(std::string& filename){
	printf("Starting Core Funtionality 4 tutorial...\n");

	std::string filename2 = "/home/kmcgill/git-repo/sample-work/opencv_tutorials/res/amg-gt-mars-red.jpg";

	double alpha = 0.5;
	double beta;

	cv::Mat src1, src2, dst;

	src1 = cv::imread(filename);
	src2 = cv::imread(filename2);

	if(src1.empty()){
		printf("Unable to read %s\n", filename.c_str());
		return -1;
	}

	if(src2.empty()){
		printf("Unable to read %s\n", filename2.c_str());
		return -1;
	}

	//want the lesser of the rows and lesser of the cols and copy pixels
	printf("src1 cols=%i, src2 cols=%i\n", src1.cols, src2.cols);
	printf("src1 rows=%i, src2 rows=%i\n", src1.rows, src2.rows);

	int inRows = src1.rows < src2.rows ? src1.rows : src2.rows;
	int inCols = src1.cols < src2.cols ? src1.cols : src2.cols;

	//use the region of interest to copy the pixels
	cv::Mat in1(src1, cv::Rect(0, 0, inCols, inRows)); //copies the header of the underlying Mat but not the pixels themselves
	cv::Mat in2(src2, cv::Rect(0, 0, inCols, inRows));

	beta = 1.0 - alpha;
	cv::addWeighted(in1, alpha, in2, beta, 0.0, dst);
	cv::imshow("Linear Weighted", dst);
	cv::waitKey(0);

	return 0;
}


