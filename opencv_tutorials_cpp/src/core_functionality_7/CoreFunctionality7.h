/*
 * CoreFunctionality7.h
 *
 *  Created on: Jul 20, 2019
 *      Author: kmcgill
 */

#ifndef CORE_FUNCTIONALITY_7_COREFUNCTIONALITY7_H_
#define CORE_FUNCTIONALITY_7_COREFUNCTIONALITY7_H_


#include "../StandardHeaders.h"
#include <opencv2/opencv.hpp>

class CoreFunctionality7{
public:
	CoreFunctionality7(){};
	~CoreFunctionality7(){};

	int run(std::string filename);
	int mandelbrot(const std::complex<float>& z0, const int max);
	void sequentialMandelbrot(cv::Mat& img, const float x1, const float y1, const float scaleX, const float scaleY);
	int mandelbrotFormula(const std::complex<float>& z0, const int maxIter=500);
};


#endif /* CORE_FUNCTIONALITY_7_COREFUNCTIONALITY7_H_ */
