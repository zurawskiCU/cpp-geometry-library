/** @file Circle.cxx
 *  @brief File containing the implementation of the Circle class
 *	@details Classes allow the user to represent circles in 3-dimensional cartesian space
 */
 
#include "Circle.h"
#include <iostream>
#include <math.h>

using namespace std;

/**
* @brief Default Circle Constructor
* @details Creates Circle with center point at the origin and radius of 1
*/
Circle::Circle() {
    center = Point(0,0);
    distFromCenter = 1;
}

/**
* @brief Circle Constructor
* @details Creates Circle with user-defined values for the center point and radius
* @param centerP The center point of the circle
* @param distFromCenterD The radius of the circle
*/
Circle::Circle(Point centerP, double distFromCenterD) {
    center = centerP;
    distFromCenter = distFromCenterD;
}

/**
* @brief Returns the center point of the circle
* @return The center point of the circle
*/	
Point Circle::getCenterPoint() {
    return center;
}

/**
* @brief Calculates the area of the circle
* @return The computed area of the circle
*/
double Circle::getArea() {
    return M_PI * pow(distFromCenter, 2);
}

/**
* @brief Calculates the perimeter or circumference of the circle
* @return The computed perimeter or circumference of the circle
*/
double Circle::getPerimeter() {
    return 2 * M_PI * distFromCenter;
}

/**
* @brief Allows the user to set the center point of the circle, keeping the radius constant
* @param new_point The new center point of the circle
*/
void Circle::setCenterPoint(Point new_point) {
    center = new_point;
}

/**
* @brief Allows the user to set the radius of the circle, keeping the center point constant
* @param distFromCenterD The new radius of the circle
*/
void Circle::setCircleSize(double distFromCenterD) {
    distFromCenter = distFromCenterD;
}
