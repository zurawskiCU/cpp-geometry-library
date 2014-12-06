/** CSCI 3308
 * C++ Library Class File
 * Authors: Daniel Zurawski, Jay LeCavalier, Ryan Goss, Heather Witte
 */
 
#include "Square.h"
#include <iostream>
#include <math.h>

using namespace std;

Square::Square() {
	for (int i = 0; i < 4; i++) {
		point.push_back(Point());
	}	
}

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

	if (l1.getXDist(p1, mP) == l2.getXDist(p2, mP) == l3.getXDist(p3, mP) == l4.getXDist(p4, mP) && l1.getYDist(p1, mP) == l2.getYDist(p2, mP) == l3.getYDist(p3, mP) == l4.getYDist(p4, mP)) {
		point.push_back(p1);
		point.push_back(p2);
		point.push_back(p3);
		point.push_back(p4);
	}
	else {
		cout << "Not valid point inputs to create square." << endl;
	}
}

	
Point Square::getPoint(int point_number) {
	if (point_number > 4) {
		cout << "point_number must be 1-4" << endl;
		return point.at(0);
	}
	else {
		return point.at(point_number - 1);	
	}
}

vector<Point> Square::getPoints() {
	return point;
}



double Square::getArea() {
    double dist = Point::distanceBetweenPoints(point[0], point[1]);
    return pow(dist, 2);
}

double Square::getPerimeter() {
    double dist1 = Point::distanceBetweenPoints(point[0], point[1]);
    double dist2 = Point::distanceBetweenPoints(point[1], point[2]);
    double dist3 = Point::distanceBetweenPoints(point[2], point[3]);
    double dist4 = Point::distanceBetweenPoints(point[3], point[0]);
    
    return dist1 + dist2 + dist3 + dist4;
}

Point Square::getMiddlePoint() {
    point.at(0);
	double newX = (point[0].getXCoord() + point[1].getXCoord() + point[2].getXCoord() + point[3].getXCoord()) / 4;
	double newY = ((point[0].getYCoord() + point[1].getYCoord() + point[2].getYCoord() + point[3].getYCoord()) / 4);
	return Point(newX, newY);
}


void Square::setPoint(int point_number, Point new_point) {
	if (point_number > 4) {
		cout << "point_number must be 1-4" << endl;
	}
	else {
		point.at(point_number - 1) = new_point;
	}
}

void Square::setPoint(int point_number, double xCoord, double yCoord) {
	if (point_number > 4) {
		cout << "point_number must be 1-4" << endl;
	}
	else {
		point.at(point_number -1).setXCoord(xCoord);
		point.at(point_number -1).setYCoord(yCoord);	
	}
}
