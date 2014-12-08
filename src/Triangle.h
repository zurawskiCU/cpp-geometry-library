#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "LinePoint.h"
#include <vector>

using namespace std;


/**
* @brief Triangle class
* @details A class to represent triangles in 3-dimensional cartesian space.
*/
class Triangle {
	private:
		vector<Point> Points;
		
	public:
	//Constructors
		Triangle();
		Triangle(Point p1, Point p2, Point p3);
			
	//Getters
		Point getPoint(int point_number);
		vector<Point> getPoints();
		
	//Setters
		void setPoint(int point_number, Point new_point);
		void setPoint(int point_number, double xCoord, double yCoord);
};



#endif
