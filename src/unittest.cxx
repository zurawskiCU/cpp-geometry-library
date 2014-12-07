#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Polygon.h"
#include "LinePoint.h"
#include <iostream>
#include <list>
#include <cmath>

using namespace std;


unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

//Rounds value to 5 decimal places
double round5 (double value) {
	return roundf(value * 100000) / 100000;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    CHECK( Factorial(0) == 0 );
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    //REQUIRE( Factorial(10) == 3628800 );

}

TEST_CASE( "Point is retrieved from polygon", "[getPoint(x,y)]") {

	Point test_points[3] = {Point(1,2), Point(3,2), Point(5,6)};
	list<Point> test_list (test_points, test_points+sizeof(test_points)/sizeof(Point));
	Polygon test_poly = Polygon(test_list);

	REQUIRE(test_poly.getPoint(5,6) == Point(5,6));

}

TEST_CASE( "Point rotated", "[rotateOrigin]") {
	Point test_rotate_point = Point(1,0);
	test_rotate_point.rotateOrigin(90);

	REQUIRE(round5(test_rotate_point.getXCoord()) == 0.0);
	REQUIRE(test_rotate_point.getYCoord() == 1.0);


}

