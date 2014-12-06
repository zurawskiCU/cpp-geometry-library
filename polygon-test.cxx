#include <iostream>
#include <vector>
#include "Polygon.h"

using namespace std;

int main() {

	//test getPoint()
	Point testPoints[3] = {Point(1,2), Point(3,2), Point(5,6)};

	list<Point> test_list (testPoints, testPoints+sizeof(testPoints)/sizeof(Point));
	Polygon testPoly = Polygon(test_list);

	Point findPoint = testPoly.getPoint(5,6);

	cout << findPoint.getXCoord() << endl;

	return 0;
}