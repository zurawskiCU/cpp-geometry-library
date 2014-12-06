/** CSCI 3308
 * C++ Library Class File
 * Authors: Daniel Zurawski, Jay LeCavalier, Ryan Goss, Heather Witte
 */
 
 #include <iostream>
#include <cmath>
#include "LinePoint.h"
#include "Sphere.h"

using namespace std;

//! Constructors
//! Default constructor
Sphere::Sphere() {
	this -> origin = Point(0, 0, 0);
	this -> radius = 0;
};

//! Constructor with origin only
Sphere::Sphere(Point new_origin) {
	this -> origin = new_origin;
	this -> radius = 0;
};

//! Constructor with radius only
Sphere::Sphere(double new_radius) {
	this -> origin = Point(0, 0, 0);
	this -> radius = abs(new_radius);
};

//! Complete constructor
Sphere::Sphere(Point new_origin, double new_radius) {
	this -> origin = new_origin;
	this -> radius = abs(new_radius)
};
 		
//! Getters
//! Returns origin
Point Sphere::getOrigin() {
	return this -> origin;
};

//! Returns radius
double Sphere::getRadius() {
	return this -> radius;
};
 		
//! Setters
//! Change the origin
void Sphere::setOrigin(Point new_origin) {
	this -> origin = new_origin;
};
 
//! Change the radius 
void Sphere::setRadius(double new_radius) {
	this -> radius = abs(new_radius);
}
 		
//! Geometric Functions
//! Moves Sphere
void Sphere::moveSphere(double horizontal_shift, double vertical_shift, double depth_shift) {
	(this -> origin).pointXShift(horizontal_shift);
	(this -> origin).pointYShift(vertical_shift);
	(this -> origin).pointZShift(depth_shift);
}; 

//! scales the radius
void Sphere::scaleRadius(double scale_factor) {
	new_scale_factor = abs(scale_factor);
	this -> radius = (this -> radius) * new_scale_factor;
};

//! returns the volume of the sphere
double Sphere::getVolume() {
	return (this -> radius) * (this -> radius) * (this -> radius) * 
	3.141592653589793238462643383279502884L * (4 / 3);
};

//! Sets the volume of the sphere
void Sphere::setVolume(double new_volume) {
	corrected_new_volume = abs(new_volume);
	double factor = (corrected_new_volume * 3) / (4 * 
	3.141592653589793238462643383279502884L);
	this -> radius = pow(factor, (1 / 3));
};

//! scales the volume
void Sphere::scaleVolume(double scale_factor) {
	double new_volume = (this -> getVolume()) * abs(scale_factor);
	this -> setVolume(new_volume);
};

//! returns the surface area of the sphere
double Sphere::getSurfaceArea() {
	return (this -> radius) * (this -> radius) * 3.141592653589793238462643383279502884L *
	4;
}; 

//! sets the surface area
void Sphere::setSurfaceArea(double new_surface_area) {
	this -> radius = (1 / 2) * pow((new_surface_area /
	3.141592653589793238462643383279502884L), (1 / 2));
};

//! scales the surface area
void Sphere::scaleSurfaceArea(double scale_factor) {
	double new_surface_area = (this -> getSurfaceArea()) * abs(scale_factor);
	this -> setSurfaceArea(new_surface_area);
};

//! returns true if p is on the sphere
bool Sphere::pointOnSphere(Point p) { 
	return (distanceBetweenPoints(this -> origin, p) == this -> radius);
};

//! returns true if p is on or inside sphere
bool Sphere::pointInSphere(Point p) {
	return (distanceBetweenPoints(this -> origin, p) <= this -> radius);
};
