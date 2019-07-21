/*
 * BasicDrawing.cpp
 *
 * This tutorial is how to draw
 *  - lines
 *  - circles
 *  - ellipses
 *  - rectangles
 *  - filled polygon
 *
 *  Created on: Jul 20, 2019
 *      Author: kmcgill
 */

#include "BasicDrawing.h"

int BasicDrawing::run(std::string filename){
	printf("Starting Basic Drawing...\n");

	// Start with a point
	cv::Point p;
	p.x = 10;
	p.y = 8;

	//or...
	cv::Point p1(10, 8);

	//cv::Scalar is a 4-vector which holds integers
	cv::Scalar pix(128,128,128); // Dont need to fill in all vectors if not used

	std::string atomWindowName = "Atom Window";
	std::string rookWindowName = "Rook Window";

	cv::Mat atom = cv::Mat::zeros(w,w, CV_8UC3);
	cv::Mat rook = cv::Mat::zeros(w,w, CV_8UC3);

	// The angle is in degrees
	drawEllipse(atom, 90); //perp
	drawEllipse(atom, 0); // flat
	drawEllipse(atom, 45); //y=x
	drawEllipse(atom, -45); //y=-x

	drawFilledCircle(atom, cv::Point(w/2, w/2)); //center window

	cv::imshow(atomWindowName, atom);

	//now to draw the rook
	drawPolygon(rook);

	//draw the background first
	cv::rectangle(rook, //canvas
			cv::Point(0, 7*w/8), //vertex
			cv::Point(w,w),      //point opposite vertex
			cv::Scalar(0, 255, 255), //color (YELLOW)
			cv::FILLED, //fill the space
			cv::LINE_8); //solid line

	//draw details second on top
	drawLine( rook, cv::Point( 0, 15*w/16 ), cv::Point( w, 15*w/16 ) );
	drawLine( rook, cv::Point( w/4, 7*w/8 ), cv::Point( w/4, w ) );
	drawLine( rook, cv::Point( w/2, 7*w/8 ), cv::Point( w/2, w ) );
	drawLine( rook, cv::Point( 3*w/4, 7*w/8 ), cv::Point( 3*w/4, w ) );

	cv::imshow(rookWindowName, rook);

	cv::waitKey(0);
	return 0;
}

void BasicDrawing::drawEllipse(cv::Mat src, double angle){
	int thickness = 2;
	int lineType = 8;

	cv::ellipse(src, //canvas
			cv::Point(w/2, w/2), //center
			cv::Size(w/4, w/16), //rect to fit in
			angle, //rotate rect
			0, //angle to start the draw
			360, //angle to finish the draw
			cv::Scalar(255, 0, 0), //color (BLUE)
			thickness,
			lineType); //solid
}

void BasicDrawing::drawFilledCircle(cv::Mat src, cv::Point center){
	cv::circle(src, //canvas
			center, //center
			w/32, //rad
			cv::Scalar(0,0,255),//color (RED)
			cv::FILLED, //filled
			cv::LINE_8); //solid line
}

void BasicDrawing::drawLine(cv::Mat src, cv::Point start, cv::Point end){
	int thickness = 2;
	int linetype = 8;

	cv::line(src, //canvas
			start, //p1
			end,  //p2
			cv::Scalar(0, 0, 0), //color (BLACK)
			thickness, //weight
			linetype);//solid line
}

void BasicDrawing::drawPolygon(cv::Mat src){
	int lineType = cv::LINE_8;
	cv::Point rook_points[1][20];
	rook_points[0][0]  = cv::Point(    w/4,   7*w/8 );
	rook_points[0][1]  = cv::Point(  3*w/4,   7*w/8 );
	rook_points[0][2]  = cv::Point(  3*w/4,  13*w/16 );
	rook_points[0][3]  = cv::Point( 11*w/16, 13*w/16 );
	rook_points[0][4]  = cv::Point( 19*w/32,  3*w/8 );
	rook_points[0][5]  = cv::Point(  3*w/4,   3*w/8 );
	rook_points[0][6]  = cv::Point(  3*w/4,     w/8 );
	rook_points[0][7]  = cv::Point( 26*w/40,    w/8 );
	rook_points[0][8]  = cv::Point( 26*w/40,    w/4 );
	rook_points[0][9]  = cv::Point( 22*w/40,    w/4 );
	rook_points[0][10] = cv::Point( 22*w/40,    w/8 );
	rook_points[0][11] = cv::Point( 18*w/40,    w/8 );
	rook_points[0][12] = cv::Point( 18*w/40,    w/4 );
	rook_points[0][13] = cv::Point( 14*w/40,    w/4 );
	rook_points[0][14] = cv::Point( 14*w/40,    w/8 );
	rook_points[0][15] = cv::Point(    w/4,     w/8 );
	rook_points[0][16] = cv::Point(    w/4,   3*w/8 );
	rook_points[0][17] = cv::Point( 13*w/32,  3*w/8 );
	rook_points[0][18] = cv::Point(  5*w/16, 13*w/16 );
	rook_points[0][19] = cv::Point(    w/4,  13*w/16 );

	const cv::Point* ppt[1] = {rook_points[0]};
	int npt[] = {20};

	cv::fillPoly(src, //canvas
			ppt, //points in order
			npt, //number of points to connect
			1, // contours
			cv::Scalar(255, 255, 255), //color (WHITE)
			lineType); //solid line
}

