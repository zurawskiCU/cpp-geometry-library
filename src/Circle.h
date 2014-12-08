#ifndef CIRCLE_H
#define CIRCLE_H

#include "LinePoint.h"
#include <vector>

/**
* @brief Circle class
* @details A class to represent squares in 2-dimensional cartesian space.
*/
class Circle {
	private:
		Point center;
        double distFromCenter;

	public:
		//Constructors
		Circle();
		Circle(Point centerP, double distFromCenterD);

		//Getters
		Point getCenterPoint();
		double getArea();
		double getPerimeter();

		//Setters
		void setCenterPoint(Point new_point);
		void setCircleSize(double distFromCenterD);


};

#endif
