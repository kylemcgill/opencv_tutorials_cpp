/*
 * BasicDrawing.h
 *
 *  Created on: Jul 20, 2019
 *      Author: kmcgill
 */

#ifndef SRC_IMAGE_PROCESSING_BASICDRAWING_H_
#define SRC_IMAGE_PROCESSING_BASICDRAWING_H_

#include "../StandardHeaders.h"

class BasicDrawing{
public:
	static int run(std::string filename);
	static void drawEllipse(cv::Mat src, double angle);
	static void drawFilledCircle(cv::Mat src, cv::Point center);
	static void drawPolygon(cv::Mat src);
	static void drawLine(cv::Mat src, cv::Point start, cv::Point end);

	static const int w = 800;
};



#endif /* SRC_IMAGE_PROCESSING_BASICDRAWING_H_ */
