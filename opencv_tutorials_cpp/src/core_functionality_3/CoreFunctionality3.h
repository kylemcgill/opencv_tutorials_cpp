/*
 * CoreFuncitonality3.h
 *
 *  Created on: Apr 6, 2019
 *      Author: kmcgill
 */

#ifndef CORE_FUNCTIONALITY_3_COREFUNCTIONALITY3_H_
#define CORE_FUNCTIONALITY_3_COREFUNCTIONALITY3_H_

#include "../StandardHeaders.h"
#include <opencv2/opencv.hpp>

class CoreFunctionality3{
public:
	static int run(std::string filename);
	static void sharpen(const cv::Mat& src, cv::Mat& dst);
	static void sharpen_using_kernel(const cv::Mat& src, cv::Mat& dst);
};




#endif /* CORE_FUNCTIONALITY_3_COREFUNCTIONALITY3_H_ */
