/** @file Square.cxx
 *  @brief File containing the implementation of the Square class
 *	@details Classes allow the user to represent squares in 3-dimensional cartesian space
 */
 
#include "Square.h"
#include <iostream>
#include <math.h>

using namespace std;

/**
* @brief Default Square Constructor
* @details Creates 'Square' with all 4 points at (0,0,0)
*/
Square::Square() {
	for (int i = 0; i < 4; i++) {
		point.push_back(Point());
	}	
}

 /**
* @brief Square constructor with specified points
* @details Creates a square with the user-specified points; includes a check to make sure that the 4 points do indeed make a square
* @param p1 the first point of the square
* @param p2 the second point of the square
* @param p3 the third point of the square
* @param p4 the fourth point of the square
*/
Square::Square(Point p1, Point p2, Point p3, Point p4) {
	//This section is to test that the points entered indeed create a square. This was the best/simplest method I could come up with but if you have any other ideas, let me know.
	double xmid = (p1.getXCoord() + p2.getXCoord() + p3.getXCoord() + p4.getXCoord()) / 4;
	double ymid = (p1.getYCoord() + p2.getYCoord() + p3.getYCoord() + p4.getYCoord()) / 4;
	Point mP(xmid, ymid);
	Line l1(p1, mP);
	Line l2(p2, mP);
	Line l3(p3, mP);
	Line l4(p4, mP);
    mP.getXCoord();

	if (Point::getXDist(p1, mP) == Point::getXDist(p2, mP) == Point::getXDist(p3, mP) == Point::getXDist(p4, mP) && Point::getYDist(p1, mP) == Point::getYDist(p2, mP) == Point::getYDist(p3, mP) == Point::getYDist(p4, mP)) {
		point.push_back(p1);
		point.push_back(p2);
		point.push_back(p3);
		point.push_back(p4);
	}
	else {
		cout << "Not valid point inputs to create square." << endl;
	}
}

 /**
* @brief Returns the specified point of the square
* @details The user specifies if they would like the 1st, 2nd, 3rd, or 4th point of the square. The function returns that point.
* @param point_number The point that the user would like to know; is either 1, 2, 3, or 4
* @return The point the user specified
*/	
Point Square::getPoint(int point_number) {
	if (point_number > 4) {
		cout << "point_number must be 1-4" << endl;
		return point.at(0);
	}
	else {
		return point.at(point_number - 1);	
	}
}

 /**
* @brief Returns the 4 corner points of the square
* @details Returns the vector storing the points of the square
* @return Returns all points of the square
*/
vector<Point> Square::getPoints() {
	return point;
}

/**
* @brief Calculates the area of the square
* @return Returns the computed area of the square
*/
double Square::getArea() {
    double dist = Point::distanceBetweenPoints(point[0], point[1]);
    return pow(dist, 2);
}

/**
* @brief Calculates the perimeter of the square
* @return Returns the computed perimeter of the square
*/
double Square::getPerimeter() {
    double dist1 = Point::distanceBetweenPoints(point[0], point[1]);
    double dist2 = Point::distanceBetweenPoints(point[1], point[2]);
    double dist3 = Point::distanceBetweenPoints(point[2], point[3]);
    double dist4 = Point::distanceBetweenPoints(point[3], point[0]);
    
    return dist1 + dist2 + dist3 + dist4;
}

/**
* @brief Finds the mid-point of the square
* @return Returns the point at the center of the square
*/
Point Square::getMiddlePoint() {
    point.at(0);
	double newX = (point[0].getXCoord() + point[1].getXCoord() + point[2].getXCoord() + point[3].getXCoord()) / 4;
	double newY = ((point[0].getYCoord() + point[1].getYCoord() + point[2].getYCoord() + point[3].getYCoord()) / 4);
	return Point(newX, newY);
}

//note: this next method will create a polygon that is not a square
/**
* @brief Allows the user to change one of the square's corners
* @details Allows the user to change one of the square's corner points using a Point object
* @param point_number Which point of the square is being changed. Will be 1, 2, 3, or 4
* @param new_point The new square point
*/
void Square::setPoint(int point_number, Point new_point) {
	if (point_number > 4) {
		cout << "point_number must be 1-4" << endl;
	}
	else {
		point.at(point_number - 1) = new_point;
	}
}

//note: this next method will create a polygon that is no longer a square
 /**
* @brief Allows the user to change one of the square's corners
* @details Allows the user to change one of the square's corne points by specifying x- and y- coordinates of the new point
* @param point_number Which point of the square is being changed. Will be 1, 2, 3, or 4
* @param xCoord The x-coordinate of the new point
* @param yCoord The y-coordinate of the new point
*/
void Square::setPoint(int point_number, double xCoord, double yCoord) {
	if (point_number > 4) {
		cout << "point_number must be 1-4" << endl;
	}
	else {
		point.at(point_number -1).setXCoord(xCoord);
		point.at(point_number -1).setYCoord(yCoord);	
	}
}
