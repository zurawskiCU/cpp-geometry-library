#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../include/catch.hpp"
#include "LinePoint.h"
#include <iostream>
#include <list>
#include <cmath>


//Rounds value to 5 decimal places
double round5 (double value) {
	return roundf(value * 100000) / 100000;
}


TEST_CASE( "Point getters are tested", "[Point Getters]") {

	Point testPoint = Point(1,2,3);

	REQUIRE(testPoint.getXCoord() == 1);
	REQUIRE(testPoint.getYCoord() == 2);
	REQUIRE(testPoint.getZCoord() == 3);

}

TEST_CASE( "Point setters are tested", "[Point Setters]") {

	//Individual setters
	Point testPoint = Point(1,2,3);
	testPoint.setXCoord(4);
	testPoint.setYCoord(5);
	testPoint.setZCoord(6);

	REQUIRE(testPoint.getXCoord() == 4);
	REQUIRE(testPoint.getYCoord() == 5);
	REQUIRE(testPoint.getZCoord() == 6);

	//2D setters
	testPoint.setCoords(7,8);
	REQUIRE(testPoint.getXCoord() == 7);
	REQUIRE(testPoint.getYCoord() == 8);

	//3d Setters
	testPoint.setCoords(9,10,11);
	REQUIRE(testPoint.getXCoord() == 9);
	REQUIRE(testPoint.getYCoord() == 10);
	REQUIRE(testPoint.getZCoord() == 11);
}


TEST_CASE( "pointsEqual() method tested", "[Points::pointsEqual()]") {

	Point a = Point(1,1);
	Point b = Point(1,2);
	Point c = Point(2,1);
	Point d = Point(1,1);

	REQUIRE(!Point::pointsEqual(a,b));
	REQUIRE(!Point::pointsEqual(a,c));
	REQUIRE(Point::pointsEqual(a,d));
}

TEST_CASE( "distances between points methods tested", "[Point distances)]") {

	Point a = Point(1,1,1);
	Point b = Point(4,4,4);

	REQUIRE(Point::distanceBetweenPoints(a,b) == sqrt(27));
	REQUIRE(Point::distanceBetweenPoints(b,a) == sqrt(27));

	REQUIRE(Point::getXDist(a,b) == 3);
	REQUIRE(Point::getYDist(a,b) == 3);
	REQUIRE(Point::getZDist(a,b) == 3);
}

TEST_CASE( "Point shift methods are tested", "[Point::shift") {

	Point testPoint = Point(1,2,3);

	testPoint.pointXShift(3.5);
	testPoint.pointYShift(2.5);
	testPoint.pointZShift(1.5);

	REQUIRE(testPoint.getXCoord() == 4.5);
	REQUIRE(testPoint.getYCoord() == 4.5);
	REQUIRE(testPoint.getZCoord() == 4.5);
}

TEST_CASE( "Point rotation methods tested", "[Point rotate]") {

	Point testPoint = Point(1,1);
	testPoint.rotateOrigin(90);

	REQUIRE(round5(testPoint.getXCoord()) == -1);
	REQUIRE(round5(testPoint.getYCoord()) == 1);

	testPoint = Point(1,0);
	Point center = Point(1,1);
	testPoint.rotateAround(center, 90);

	CHECK(round5(testPoint.getXCoord()) == 2);
	CHECK(round5(testPoint.getYCoord()) == 1);

}


//test cases for line class
TEST_CASE( "Line getters are tested", "[Line Getters]") {

	Point Point1 = Point(0,1,0);
	Point Point2 = Point(3,5,0);
	Line testLine = Line(Point1, Point2);

	REQUIRE(testLine.getPoint(1) == Point1);
	REQUIRE(testLine.getPoint(2) == Point2);
}

TEST_CASE( "Line setters are tested", "[Line Setters]") {

	//Individual setters
	Point Point1 = Point(1,2,3);
	Point Point2 = Point(4,5,6);
	Line testLine = Line(Point1, Point2);
	Point Point3 = Point(0,0,1);
	Point Point4 = Point(9,3,5);
	testLine.setPoint(Point3, 1);
	testLine.setPoint(Point4, 2);

	REQUIRE(testLine.getPoint(1) == Point3);
	REQUIRE(testLine.getPoint(2) == Point4);
}

TEST_CASE( "linesEqual() method tested", "[Line::linesEqual()]") {

	Point Point1 = Point(1,1);
	Point Point2 = Point(1,2);
	Point Point3 = Point(1,3);
	Line Line1 = Line(Point1, Point2);
	Line Line2 = Line(Point1, Point2);
	Line Line3 = Line(Point2, Point1);
	Line Line4 = Line(Point1, Point3);

	REQUIRE(Line::linesEqual(Line1, Line2));
	REQUIRE(Line::linesEqual(Line1, Line3));
	REQUIRE(!Line::linesEqual(Line1, Line4));
}


TEST_CASE( "line length and distance methods tested", "[Line length and distances)]") {

	Point a = Point(1,1,1);
	Point b = Point(4,4,4);
	Line testLine = Line(a, b);

	REQUIRE(Line::lineLength(testLine) == sqrt(27));

	//REQUIRE(Line::getXDist(testLine) == 3);
	//REQUIRE(Line::getYDist(testLine) == 3);
	//REQUIRE(Line::getZDist(testLine) == 3);
} 


TEST_CASE( "Line shift methods are tested", "[Line::shift") {

	Point Point1 = Point(0,0);
	Point Point2 = Point(0,1);
	Line testLine = Line(Point1, Point2);

	testLine.lineXShift(2);
	testLine.lineYShift(-2.5);
	testLine.lineZShift(3);
	
	Point Point3 = testLine.getPoint(1);
	Point Point4 = testLine.getPoint(2);

	REQUIRE(Point3.getXCoord() == 2);
	REQUIRE(Point4.getXCoord() == 2);
	REQUIRE(Point3.getYCoord() == -2.5);
	REQUIRE(Point4.getYCoord() == -1.5);
	REQUIRE(Point3.getZCoord() == 3); 
	REQUIRE(Point4.getZCoord() == 3);
}

//this test case fails...
TEST_CASE( "point on line method tested", "[Point on line)]") {

	Point Point1 = Point(1,1);
	Point Point2 = Point(4,4);
	Point Point3 = Point(3,3);
	Point Point4 = Point(3,6);
	Line testLine = Line(Point1, Point2);
	
	REQUIRE(testLine.pointOnLine(Point1));
	REQUIRE(testLine.pointOnLine(Point3));
	REQUIRE(!testLine.pointOnLine(Point4));

}
