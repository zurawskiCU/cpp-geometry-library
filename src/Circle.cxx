/** CSCI 3308
 * C++ Library Class File
 * Authors: Daniel Zurawski, Jay LeCavalier, Ryan Goss, Heather Witte
 */
 
#include "Circle.h"
#include <iostream>
#include <math.h>

using namespace std;

Circle::Circle() {
    center = Point(0,0);
    distFromCenter = 1;
}

Circle::Circle(Point centerP, double distFromCenterD) {
    center = centerP;
    distFromCenter = distFromCenterD;
}

	
Point Circle::getCenterPoint() {
    return center;
}


double Circle::getArea() {
    return M_PI * pow(distFromCenter, 2);
}
double Circle::getPerimeter() {
    return 2 * M_PI * distFromCenter;
}

void Circle::setCenterPoint(Point new_point) {
    center = new_point;
}
void Circle::setCircleSize(double distFromCenterD) {
    distFromCenter = distFromCenterD;
}
