/** @file LinePoint.cxx
 *  @brief File containing the implementation of the Line and Point classes
 *	@details Classes allow the user to represent lines and points in 3-dimensional cartesian space
 *	@author Daniel Zurawski, Jay LeCavalier, Ryan Goss, Heather Witte
 */
#include <iostream>
#include <cmath>
#include "LinePoint.h"


using namespace std;

 
 /**
* @brief Default Point Constructor
* @details Creates Point at coordinates (0,0,0)
*/
 Point::Point() {
	 x = 0;
	 y = 0;
	 z = 0;
 };
 
 /**
* @brief Point Constuctor with x- and y-coordinates defined
* @details Creates a point with the specified x- and y-coordinates; z-coordinate is set to zero
* @param xCoord x-coordinate of point
* @param yCoord y-coordinate of point
*/
 Point::Point(double xCoord, double yCoord) {
	x = xCoord;
	y = yCoord;
	z = 0;
	 
 };
 
  /**
* @brief Point Constuctor with x-, y-, and z-coordinates defined
* @details Creates a point with the specified x-, y-, and z-coordinates
* @param xCoord x-coordinate of point
* @param yCoord y-coordinate of point
* @param zCoord z-coordinate of point
*/
 Point::Point(double xCoord, double yCoord, double zCoord) {
	x = xCoord;
	y = yCoord;
	z = zCoord;
	 
 };
 
 /**
* @brief Returns x-coordinate of point
* @return Returns value of x-coordinate
*/
double Point::getXCoord() const{
	return x;	
};

 /**
* @brief Returns y-coordinate of point
* @return Returns value of y-coordinate
*/
double Point::getYCoord() const{
	return y;	
};

 /**
* @brief Returns z-coordinate of point
* @return Returns value of z-coordinate
*/
double Point::getZCoord() const{
	return z;	
};

 /**
* @brief Sets x- and y-coordinates of a point
* @details Sets the x- and y-coordinates of a point; the z-coordinate will remain unchanged
* @param xCoord The new x-coordinate
* @param yCoord The new y-coordinate
*/
void Point::setCoords(double xCoord, double yCoord){
	x = xCoord;
	y = yCoord;	
};

 /**
* @brief Sets x-, y-, and z-coordinates of a point
* @param xCoord The new x-coordinate
* @param yCoord The new y-coordinate
* @param zCoord The new z-coordinate
*/
void Point::setCoords(double xCoord, double yCoord, double zCoord){
	x = xCoord;
	y = yCoord;	
	z = zCoord;
};

 /**
* @brief Sets the x-coordinate of a point
* @param xCoord The new x-coordinate
*/
void Point::setXCoord(double xCoord) {
	x = xCoord;	
};

 /**
* @brief Sets the y-coordinate of a point
* @param yCoord The new y-coordinate
*/
void Point::setYCoord(double yCoord) {
	y = yCoord;
};

 /**
* @brief Sets the z-coordinate of a point
* @param zCoord The new z-coordinate
*/
void Point::setZCoord(double zCoord) {
	z = zCoord;
};

//Geometric Functions

 /**
* @brief Determines if two points are equivalent
* @param a The first point to be tested for equivalence
* @param b The second point to be tested for equivalence
* @return Will return true if Points a and b are the same point, otherwise will return false
*/
bool Point::pointsEqual(Point a, Point b) {
	return a.getXCoord()==b.getXCoord()&&a.getYCoord()==b.getYCoord()&&a.getZCoord()==b.getZCoord();
};

 /**
* @brief Calculates the distance between two points
* @param a The first point 
* @param b The second point
* @return Returns the euclidean distance between Points a and b
*/
double Point::distanceBetweenPoints(Point a, Point b) {
	return sqrt(((a.getXCoord()-b.getXCoord())*(a.getXCoord()-b.getXCoord()))+
	((a.getYCoord()-b.getYCoord())*(a.getYCoord()-b.getYCoord()))+
	((a.getZCoord()-b.getZCoord())*(a.getZCoord()-b.getZCoord())));
};

 /**
* @brief Shifts a point in the x-direction
* @details Shifts a point in the x-direction by the distance specified by the user
* @param n The distance the point is to be shifted in the x-direction
*/
void Point::pointXShift(double n) {
	double m = n+this->getXCoord();
	this->setXCoord(m);
};

 /**
* @brief Shifts a point in the y-direction
* @details Shifts a point in the y-direction by the distance specified by the user
* @param n The distance the point is to be shifted in the y-direction
*/
void Point::pointYShift(double n) {
	double m = n+this->getYCoord();
	this->setYCoord(m);
};

 /**
* @brief Shifts a point in the z-direction
* @details Shifts a point in the z-direction by the distance specified by the user
* @param n The distance the point is to be shifted in the z-direction
*/
void Point::pointZShift(double n) {
	double m = n+this->getZCoord();
	this->setZCoord(m);
};

 /**
* @brief Calculates the x-distance between two points
* @param p1 The first point
* @param p2 The second point
* @return Returns the positive difference between the x-coordinates of two points
*/
double Point::getXDist(Point p1, Point p2) {
	return abs(p1.getXCoord() - p2.getXCoord());
}

 /**
* @brief Calculates the y-distance between two points
* @param p1 The first point
* @param p2 The second point
* @return Returns the positive difference between the y-coordinates of two points
*/
double Point::getYDist(Point p1, Point p2) {
	return abs(p1.getYCoord() - p2.getYCoord());
}

 /**
* @brief Calculates the z-distance between two points
* @param p1 The first point
* @param p2 The second point
* @return Returns the positive difference between the z-coordinates of two points
*/
double Point::getZDist(Point p1, Point p2){
	return abs(p1.getZCoord() - p2.getZCoord());
}

 /**
* @brief Rotates a Point around the Point (0,0,0) by the specified angle
* @details Rotates a point around the origin; this rotation can only be done on the x-y plane
* @param angle The angle that the Point is to be rotated
*/
void Point::rotateOrigin(double angle) {
	double radians =  angle * M_PI / 180;

	double newXCoord = x*cos(radians) - y*sin(radians);
	double newYCoord = x*sin(radians) + y*cos(radians);

	x = newXCoord;
	y = newYCoord;
}

 /**
* @brief Rotates a Point around another Point by the specified angle
* @details Rotates a point around another point; this rotation can only be done on the x-y plane
* @param center The Point that is the center of rotation
* @param angle The angle that the Point is to be rotated
*/
void Point::rotateAround(Point center, double angle) {
	double radians = angle * M_PI / 180;

	double xOffset = (x - center.getXCoord());
	double yOffset = (y - center.getYCoord());

	double newXCoord = xOffset*cos(radians) - yOffset*sin(radians) + center.getXCoord();
	double newYCoord = xOffset*sin(radians) + yOffset*cos(radians) + center.getYCoord();

	x = newXCoord;
	y = newYCoord;
}



//Operators
bool operator==(const Point& a, const Point& b){
	return Point::pointsEqual(a,b);
};

Point& Point::operator=(const Point& anotherPoint){
	if (this == &anotherPoint)  
		return *this;
	
	else{
		x = anotherPoint.getXCoord()
;		y = anotherPoint.getYCoord();
		z = anotherPoint.getZCoord();
		return *this;}
};
 
/**
* @brief Default Line Constructor
* @details Creates Line with endpoints (0,0,0) and (1,0,0)
*/
 Line::Line() {
	 p1 = Point(0,0);
	 p2 = Point(1,0);
 };
 
 /**
* @brief  Line Constructor
* @details Creates Line with the endpoints specified by the user
* @param point1 The first endpoint of the line
* @param point2 The second endpoint of the line
*/
 Line::Line(Point point1, Point point2) {
	p1 = point1;
	p2 = point2; 
	//The following conditional branch makes sure the user has entered two unique points.
	if(p1.getXCoord()==p2.getXCoord()&&p1.getYCoord()==p2.getYCoord()&&p1.getZCoord()==p2.getZCoord()){
		cout<<"Points are equal. There are infinitely many lines through a single point.\nInstead, the line through (0, 0), (1, 0) was made.";
		p1 = Point(0, 0);
		p2 = Point(1, 0);
	}
 };

 /**
* @brief Calculates the x-distance between the endpoints of a line
* @param my_line The line for which the x-distance between the endpoints is to be calculated
* @return Returns the positive difference between the x-coordinates of the line's endpoints
*/
double Line::getXDist(Line my_line) {
	return Point::getXDist(my_line.getPoint(1), my_line.getPoint(2));
}

/**
* @brief Calculates the y-distance between the endpoints of a line
* @param my_line The line for which the y-distance between the endpoints is to be calculated
* @return Returns the positive difference between the y-coordinates of the line's endpoints
*/
double Line::getYDist(Line my_line) {
	return Point::getYDist(my_line.getPoint(1), my_line.getPoint(2));
}

/**
* @brief Calculates the z-distance between the endpoints of a line
* @param my_line The line for which the z-distance between the endpoints is to be calculated
* @return Returns the positive difference between the z-coordinates of the line's endpoints
*/
double Line::getZDist(Line my_line){
	return Point::getXDist(my_line.getPoint(1), my_line.getPoint(2));
}
 
 /**
* @brief Returns one of the endpoints of the line
* @details Returns one of the endpoints of the line; if an invalid point number is used as a paramter, it will return the Point (0,0,0)
* @param pointNumber Is either 1 or 2
* @return Returns either p1 (the first endpoint) or p2 (the second endpoint) of the line
*/
 Point Line::getPoint(int pointNumber) const{
	if (pointNumber == 1)
		return p1;
	else if (pointNumber == 2)
		return p2;
	else
		cout<<"Invalid pointNumber"<<endl;
		return Point(0,0);
 };
 
 /**
* @brief Resets one of the endpoints
* @details Will update one of the endpoints of the line; if an invalid pointNumber is used, no updates are made to the line
* @param newPoint The new endpoint of the line
* @param pointNumber Specifies which endpoint (either p1 or p2) is to be replaced
*/
 void Line::setPoint(Point newPoint, int pointNumber) {
	if (pointNumber == 1)
		p1.setCoords(newPoint.getXCoord(), newPoint.getYCoord(), newPoint.getZCoord());
	else if (pointNumber == 2)
		p2.setCoords(newPoint.getXCoord(), newPoint.getYCoord(), newPoint.getZCoord());
	else
		cout<<"Invalid pointNumber"<<endl;
 };
 
 /**
* @brief Tests whether two lines are equal
* @details Tests for the equivalence of two lines; Two lines are considered equal if both endpoints of both lines are the same (pointNumber is ignored)
* @param a The first line to be tested
* @param b the second line to be tested
* @return Returns true if the two lines are equal, otherwise false
*/
bool Line::linesEqual(Line a, Line b){
	return (Point::pointsEqual(a.getPoint(1), b.getPoint(1)) && Point::pointsEqual(a.getPoint(2), b.getPoint(2))) 
	|| (Point::pointsEqual(a.getPoint(1), b.getPoint(2)) && Point::pointsEqual(a.getPoint(2), b.getPoint(1))) ;
};

/**
* @brief Calculates the length of line
* @param my_line The line the user wants to know the length of
* @return The length of the line
*/
double Line::lineLength(Line my_line){
	return Point::distanceBetweenPoints(my_line.getPoint(1), my_line.getPoint(2));
};

 /**
* @brief Shifts a line in the x-direction
* @details Shifts a line in the x-direction by the distance specified by the user
* @param n The distance the line is to be shifted in the x-direction
*/
void Line::lineXShift(double n){
	Point my_p1 = this->getPoint(1);
	Point my_p2 = this->getPoint(2);
	my_p1.Point::pointXShift(n);
	my_p2.Point::pointXShift(n);
	this -> setPoint(my_p1, 1);
	this -> setPoint(my_p2, 2);
};

/**
* @brief Shifts a line in the y-direction
* @details Shifts a line in the y-direction by the distance specified by the user
* @param n The distance the line is to be shifted in the y-direction
*/		
void Line::lineYShift(double n){
	Point my_p1 = this->getPoint(1);
	Point my_p2 = this->getPoint(2);
	my_p1.Point::pointYShift(n);
	my_p2.Point::pointYShift(n);
	this -> setPoint(my_p1, 1);
	this -> setPoint(my_p2, 2);
};

/**
* @brief Shifts a line in the z-direction
* @details Shifts a line in the z-direction by the distance specified by the user
* @param n The distance the line is to be shifted in the z-direction
*/
void Line::lineZShift(double n){
	Point my_p1 = this->getPoint(1);
	Point my_p2 = this->getPoint(2);
	my_p1.Point::pointZShift(n);
	my_p2.Point::pointZShift(n);
	this -> setPoint(my_p1, 1);
	this -> setPoint(my_p2, 2);
};

/**
* @brief Tests whether a Point is on a Line
* @param p The Point being tested for inclusion on the Line
* @return Returns true if Point p is on the line; otherwise false
*/
bool Line::pointOnLine(Point p){
	double x1 = this->getPoint(1).getXCoord();
	double y1 = this->getPoint(1).getYCoord();
	double z1 = this->getPoint(1).getZCoord();
	double x2 = this->getPoint(2).getXCoord();
	double y2 = this->getPoint(2).getYCoord();
	double z2 = this->getPoint(2).getZCoord();
	double a = x2 - x1;
	double b = y2 - y1;
	double c = z2 - z1;
	double t = p.getXCoord()-x1;
	t = t*a;
	return ((p.getYCoord() == (y1+(t*b))) && (p.getZCoord() == (z1+(t*c))));
};

//Operators
bool operator==(const Line&a, const Line&b){
	return Line::linesEqual(a,b);
};

Line& Line::operator=(const Line& anotherLine){
	if (this == &anotherLine)
		return *this;
	
	else{
		p1 = anotherLine.getPoint(1);
		p2 = anotherLine.getPoint(2);
		return *this; 
	}	
		
};
