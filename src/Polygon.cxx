/** @file Polygon.cxx
 *  @brief Generic Polygon class
 *	@details Class of Polygon which user can create any shape
 *
 */

#include <vector>
#include "Polygon.h"
#include <algorithm>
#include <iostream>

Point findPoint(Point toFind) {

	return Point();
}


/**
* @brief Default Polygon Constructor
* @details Creates 3 sided Polygon with points (0,0), (0,1), (1,0)
*/
Polygon::Polygon() {
	Point initialPoints[3] = {Point(0,0), Point(0,1), Point(1,0)};

	for (int i = 0; i < 3; i++) {
		points.push_back(initialPoints[i]);
	}
}

/**
* @brief Polygon Constuctor using existing std::list of points
* @details User constructs instance of a polygon using an existing std::list of points
* @param inputPoints std::list of points
*/
Polygon::Polygon(std::list<Point> inputPoints) {

	points = inputPoints;
	sides = inputPoints.size();
}

/**
* @brief Returns a Point object
* @details User enters coordinates of point to be returned if there exists a point with those coordinates in the Polygon.
*		   If user coordinates are on in the Polygon returns a (0,0) Point
* @param xCoord, yCoord Coordinates of Point to be returned
* @return Returns Point
*/
Point Polygon::getPoint(double xCoord, double yCoord) {

	for (std::list<Point>::iterator i=points.begin(); i != points.end(); i++) {
		Point p = *i;
		if ((p.getXCoord() == xCoord) && (p.getYCoord() == yCoord)) {

			return p;
		}
	}

	std::cout << "Point not found returning (0,0)" << std::endl;	
	return Point();
}


/**
* @brief Returns std::list of all Points in the Polygon
* 
* 
*/
std::list<Point> Polygon::getPoints() {
	return points;
}

/**
* @brief Returns number of sides in Polygon
* 
* 
*/
int Polygon::getNumberSides(){
	return sides;
}

/**
* @brief Sets Point to new coordinates for 2D Polygon
* @detail User enters coordinates of Point in 2D Polygon to be replaced and coordinates of new Point
* 
* @param xCoord, yCoord Coordinates of Point to be replaced
* @param NewXCoord, NewYCoord Coordinates of new Point
*/
void Polygon::setPoint(double xCoord, double yCoord, double NewXCoord, double NewYCoord) {
	
	for (std::list<Point>::iterator i=points.begin(); i != points.end(); i++) {
		Point p = *i;
		if ((p.getXCoord() == xCoord) && (p.getYCoord() == yCoord)) {

			p.setCoords(NewXCoord, NewYCoord);
			
		}
	}
}

/**
* @brief Sets Point to new coordinates for 3D Polygon
* @detail User enters coordinates of Point in 3D Polygon to be replaced and coordinates of new Point
* 
* @param xCoord, yCoord, zCoord Coordinates of Point to be replaced
* @param NewXCoord, NewYCoord, NewZCoord Coordinates of new Point
*/
void Polygon::setPoint(double xCoord, double yCoord, double zCoord, double NewXCoord, double NewYCoord, double NewZCoord) {

	for (std::list<Point>::iterator i = points.begin(); i != points.end(); i++) {
		Point p = *i;
		if ((p.getXCoord() == xCoord) && (p.getYCoord() == yCoord) && (p.getZCoord() == zCoord)) {

			p.setCoords(NewXCoord, NewYCoord, NewZCoord);
		}
	}
}

/**
* @brief Adds new Point to 2D Polygon
* @detail Pushes new Point from user entered coordinates to the end of the Point list
* 
* @param xCoord, yCoord Coordinates of new Point
* 
*/
void Polygon::addPoint(double xCoord, double yCoord) {
	points.push_back(Point(xCoord, yCoord));
	sides++;
}

/**
* @brief Adds new Point to 3D Polygon
* @detail Pushes new Point from user entered coordinates to the end of the Point list
* 
* @param xCoord, yCoord, zCoord Coordinates of new Point
* 
*/
void Polygon::addPoint(double xCoord, double yCoord, double zCoord) {
	points.push_back(Point(xCoord, yCoord, zCoord));
	sides++;
}

/**
* @brief Adds new Point to Polygon
* @detail Pushes new Point from user entered Point to the end of the Point list
* 
* @param newPoint Point object of new Point to be added to Polygon
* 
*/
void Polygon::addPoint(Point newPoint) {
	points.push_back(newPoint);
	sides++;
}

/**
* @brief Rotates Polygon around origin
* 
* 
* @param angle		Degrees to rotate point around origin (postive is counter clockwise)
* 
*/
void Polygon::rotateOrigin(double angle) {
	for (std::list<Point>::iterator i = points.begin(); i != points.end(); i++) {
		Point p = *i;
		p.rotateOrigin(angle);
	}
}
