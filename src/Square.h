#ifndef SQUARE_H
#define SQUARE_H

#include "LinePoint.h"
#include <vector>


/**
* @brief Square class
* @details A class to represent squares in 3-dimensional cartesian space.
*/
class Square {
	private:
		std::vector<Point> point;

	public:
		//Constructors
		Square();
		Square(Point p1, Point p2, Point p3, Point p4);
		Square(Point middle, double size);

		//Getters
		Point getPoint(int point_number);
		std::vector<Point> getPoints();
		double getArea();
		double getPerimeter();
		Point getMiddlePoint();

		//Setters
		void setPoint(int point_number, Point new_point);
		void setPoint(int point_number, double xCoord, double yCoord);


};

#endif
