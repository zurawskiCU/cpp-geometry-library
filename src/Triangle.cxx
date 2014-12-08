/** @file Triangle.cxx
 *  @brief File containing the implementation of the Triangle class
 *	@details Classes allow the user to represent triangles in 3-dimensional cartesian space
 */

#include "Triangle.h"
#include "LinePoint.h"
#include <vector>
#include <iostream>

using namespace std;

/**
* @brief Default Triangle Constructor
* @details Creates 'Triangle' with all 3 points at (0,0,0)
*/
Triangle::Triangle() {
	for (int i = 0; i < 3; i++) {
		Points.push_back(Point());
	}	
}

 /**
* @brief Triangle constructor with specified points
* @details Creates a triangle with the user-specified points
* @param p1 the first point of the triangle
* @param p2 the second point of the triangle
* @param p3 the third point of the triangle
*/
Triangle::Triangle(Point p1, Point p2, Point p3) {
	Points.push_back(p1);
	Points.push_back(p2);
	Points.push_back(p3);		
}

 /**
* @brief Returns the specified point of the triangle
* @details The user specifies if they would like the 1st, 2nd, or 3rd point of the triangle. The function returns that point.
* @param point_number The point that the user would like to know; is either 1, 2, or 3
* @return The point the user specified
*/
Point Triangle::getPoint(int point_number){
	if (point_number > 3) {
		cout << "point_number must be 1-3" << endl;
		return Point();
	}
	else {
		return Points.at(point_number - 1);	
	}
}

 /**
* @brief Returns the 3 corner points of the triangle
* @details Returns the vector storing the points of the triangle
* @return Returns all points of the triangle
*/
vector<Point> Triangle::getPoints() {
	return Points;	
}

 /**
* @brief Allows the user to change one of the triangle's corners
* @details Allows the user to change one of the triangle's corner points using a Point object
* @param point_number Which point of the triangle is being changed. Will be 1, 2, or 3
* @param new_point The new triangle point
*/
void Triangle::setPoint(int point_number, Point new_point) {
	if (point_number > 3) {
		cout << "point_number must be 1-3" << endl;
	}
	else {
		Points.at(point_number - 1) = new_point;
	}
}

 /**
* @brief Allows the user to change one of the triangle's corners
* @details Allows the user to change one of the triangle's corne points by specifying x- and y- coordinates of the new point
* @param point_number Which point of the triangle is being changed. Will be 1, 2, or 3
* @param xCoord The x-coordinate of the new point
* @param yCoord The y-coordinate of the new point
*/
void Triangle::setPoint(int point_number, double xCoord, double yCoord){
	if (point_number > 3) {
		cout << "point_number must be 1-3" << endl;
	}
	else {
		Points.at(point_number -1).setXCoord(xCoord);
		Points.at(point_number -1).setYCoord(yCoord);	
	}
}

int main() {

	Triangle test = Triangle();	
	test.setPoint(3, 50.2, 234.2);

	cout << test.getPoint(3).getXCoord() << endl;	
	
}
