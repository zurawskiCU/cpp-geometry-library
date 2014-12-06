#ifndef CIRCLE_H
#define CIRCLE_H

#include "LinePoint.h"
#include <vector>

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