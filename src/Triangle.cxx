#include "Triangle.h"
#include "LinePoint.h"
#include <vector>
#include <iostream>

using namespace std;


Triangle::Triangle() {
	for (int i = 0; i < 3; i++) {
		Points.push_back(Point());
	}	
}

Triangle::Triangle(Point p1, Point p2, Point p3) {
	Points.push_back(p1);
	Points.push_back(p2);
	Points.push_back(p3);		
}

Point Triangle::getPoint(int point_number){
	if (point_number > 3) {
		cout << "point_number must be 1-3" << endl;
		return Point();
	}
	else {
		return Points.at(point_number - 1);	
	}
}

vector<Point> Triangle::getPoints() {
	return Points;	
}

void Triangle::setPoint(int point_number, Point new_point) {
	if (point_number > 3) {
		cout << "point_number must be 1-3" << endl;
	}
	else {
		Points.at(point_number - 1) = new_point;
	}
}

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
