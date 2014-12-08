/**
* @brief Demo for presentation
* @details Main function implements class files of our library and shows that they work.
* @author Daniel Zurawski, Jay LeCavalier, Ryan Goss, Heather Witte
*/

#include <iostream>
#include <cmath>
#include "LinePoint.h"
#include "Circle.h"
#include "Polygon.h"
#include "Sphere.h"

using namespace std;

int main() {
	//! LinePoint demo
	Line myLine = Line(Point(0, 0, 0), Point(5.5, 3.141592, 5000));
	cout << "\n\nNew line segment created with end points (" << myLine.getPoint(1).getXCoord()
	<< ", " << myLine.getPoint(1).getYCoord() << ", " << myLine.getPoint(1).getZCoord() <<
	") and (" << myLine.getPoint(2).getXCoord() << ", " << myLine.getPoint(2).getYCoord()
	<< ", " << myLine.getPoint(2).getZCoord() << ").\n\n";
	cout << "The length of the line is " << myLine.lineLength(myLine) << " units.\n\n";
	
	//! Circle demo
	Circle myCircle = Circle(Point(0, 1, 2), 64);
	cout << "New circle created with center (" << myCircle.getCenterPoint().getXCoord() <<
	", " << myCircle.getCenterPoint().getYCoord() << ", "
	<< myCircle.getCenterPoint().getZCoord() << ") and radius 64 units.\n\n";
	cout << "The area of the circle is " << myCircle.getArea() << " units squared.\n\n";
	cout << "The perimeter of the circle is " << myCircle.getPerimeter() << " units.\n\n";
	
	//! Sphere demo
	Sphere mySphere = Sphere(Point(0, 1, 2), 64);
	cout << "New sphere created with center (" << mySphere.getOrigin().getXCoord() <<
	", " << mySphere.getOrigin().getYCoord() << ", " << mySphere.getOrigin().getZCoord() <<
	") and radius " << mySphere.getRadius() << " units.\n\n";
	cout << "The volume of the sphere is " << mySphere.getVolume() << " units cubed.\n\n";
	cout << "The surface area of the sphere is " << mySphere.getSurfaceArea() <<
	" units squared.\n\n";
	if(mySphere.pointOnSphere(Point(3, 3, 3))) {
		cout << "The point (3, 3, 3) is on the surface of the sphere.\n\n";
	}
	else {
		cout << "The point (3, 3, 3) is not on the surface of the sphere.\n\n";
	}
	if(mySphere.pointOnSphere(Point(64, 1, 2))){
		cout << "The point (64, 1, 2) is on the surface of the sphere.\n\n";
	}
	else {
		cout << "The point (64, 1, 2) is not on the surface of the sphere.\n\n";
	}
	if(mySphere.pointInSphere(Point(3, 3, 3))) {
		cout << "The point (3, 3, 3) is inside or on the surface of the sphere.\n\n";
	}
	else {
		cout << "The point (3, 3, 3) is not inside or on the surface of the sphere.\n\n";
	}
	
	
	
	
	return 0;
}