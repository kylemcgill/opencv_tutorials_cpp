/*
 * CoreFunctionality7.cpp
 *
 *  Created on: Jul 20, 2019
 *      Author: kmcgill
 */

#include "CoreFunctionality7.h"

int CoreFunctionality7::run(std::string filename){

	cv::Mat mandelbrotImg(1200, 1920, CV_8U);
	float x1 = -2.1f, x2 = 0.6f;
	float y1 = -1.2f, y2 = 1.2f;
	float scaleX = mandelbrotImg.cols / (x2 - x1);
	float scaleY = mandelbrotImg.rows / (y2 - y1);
	printf("Starting parallel mandelbrot...\n");
	double t1 = (double) cv::getTickCount();

	cv::parallel_for_(cv::Range(0, mandelbrotImg.rows*mandelbrotImg.cols), [&](const cv::Range& range){
		for(int r = range.start; r < range.end; ++r){
			int i = r / mandelbrotImg.cols;
			int j = r % mandelbrotImg.cols;

			float x0 = j / scaleX + x1;
			float y0 = i / scaleY + y1;

			std::complex<float> z0(x0, y0);
			uint8_t value = (uint8_t) mandelbrotFormula(z0);
			mandelbrotImg.ptr<uint8_t>(i)[j] = value;
		}
	});

	t1 = ((double) cv::getTickCount() - t1) / cv::getTickFrequency();
	std::cout << "Parallel Mandelbrot: " << t1 << " s" << std::endl;

	printf("Starting sequential mandebrot..\n");
	cv::Mat mandelbrotImgSequential(1200, 1920, CV_8U);
	double t2 = (double) cv::getTickCount();
	sequentialMandelbrot(mandelbrotImgSequential, x1, y1, scaleX, scaleY);
	t2 = ((double) cv::getTickCount() - t2) / cv::getTickFrequency();
	std::cout << "Sequential Mandelbrot: " << t2 << " s" << std::endl;
	std::cout << "Speed-up: " << t2/t1 << " X" << std::endl;

	cv::imshow("Mandelbrot IMG", mandelbrotImg);
	cv::waitKey(0);

	return 0;
}


int CoreFunctionality7::mandelbrot(const std::complex<float>& z0, const int max){
	std::complex<float> z = z0;
	for(int t = 0; t < max; ++t){
		if(z.real()*z.real() + z.imag()*z.imag() > 4.0f) return t;
		z = z*z + z0;
	}
	return max;
}

void CoreFunctionality7::sequentialMandelbrot(cv::Mat& img, const float x1, const float y1, const float scaleX, const float scaleY){
	//iterate over every pixel
	for (int i = 0; i < img.rows; ++i){
		for(int j = 0; j < img.cols; ++j){
			float x0 = j / scaleX + x1;
			float y0 = i / scaleY + y1;

			std::complex<float> z0(x0, y0);
			uchar value = (uchar) mandelbrotFormula(z0);
			img.ptr<uchar>(i)[j] = value;
		}
//		printf("Finished col %i\n", i);
	}
}

int CoreFunctionality7::mandelbrotFormula(const std::complex<float>& z0, const int maxIter){
	int value = mandelbrot(z0, maxIter);
	if((maxIter - value) == 0) return 0;
	return cvRound(sqrt(value / (float)maxIter) * 255);
}

