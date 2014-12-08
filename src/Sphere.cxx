/** @file LinePoint.cxx
 *  @brief File containing the implementation of the Sphere class
 *	@details Classes allow the user to represent a sphere
 *	@author Daniel Zurawski, Jay LeCavalier, Ryan Goss, Heather Witte
 */
 
 #include <iostream>
#include <cmath>
#include "LinePoint.h"
#include "Sphere.h"

using namespace std;

 /**
* @brief Default Sphere
* @details Creates sphere with origin (0, 0, 0) and radius 0
*/
Sphere::Sphere() {
	this -> origin = Point(0, 0, 0);
	this -> radius = 0;
};

 /**
* @brief Sphere constructor with origin only
* @details Creates sphere with origin new_origin and radius 0
* @param new_origin origin of the sphere
*/
Sphere::Sphere(Point new_origin) {
	this -> origin = new_origin;
	this -> radius = 0;
};

  /**
* @brief Sphere constructor with radius only
* @details Creates a sphere with specified radius and origin (0, 0, 0)
* @param new_radius radius of the sphere
*/
Sphere::Sphere(double new_radius) {
	this -> origin = Point(0, 0, 0);
	this -> radius = abs(new_radius);
};

  /**
* @brief Sphere constructor with all parameters
* @details Creates a sphere with origin new_origin and radius new_radius
* @param new_origin the origin of the sphere
* @param new_radius radius of the sphere
*/
Sphere::Sphere(Point new_origin, double new_radius) {
	this -> origin = new_origin;
	this -> radius = abs(new_radius);
};
 		
  /**
* @brief returns the origin of the sphere
* @return the origin of the sphere
*/
Point Sphere::getOrigin() {
	return this -> origin;
};

  /**
* @brief returns the radius of the sphere
* @return the radius of the sphere
*/
double Sphere::getRadius() {
	return this -> radius;
};
 		
  /**
* @brief changes the origin of the sphere
* @param new_origin the origin of the sphere
*/
void Sphere::setOrigin(Point new_origin) {
	this -> origin = new_origin;
};
 
  /**
* @brief changes the radius of the sphere
* @param new_origin the radius of the sphere
*/
void Sphere::setRadius(double new_radius) {
	this -> radius = abs(new_radius);
}
 		
  /**
* @brief moves the sphere in 3-D space
* @param horizontal_shift distance to move the sphere horizontally
* @param vertical_shift distance to move the sphere vertically
* @param depth_shift distance to move the sphere depthwise
*/
void Sphere::moveSphere(double horizontal_shift, double vertical_shift, double depth_shift) {
	(this -> origin).pointXShift(horizontal_shift);
	(this -> origin).pointYShift(vertical_shift);
	(this -> origin).pointZShift(depth_shift);
}; 

  /**
* @brief multiplies the radius by a positive real number
* @details first, take the absolute value of the scale factor, and multiply the radius by that factor.
* @param scale_factor how many times bigger/smaller should the radius be?
*/
void Sphere::scaleRadius(double scale_factor) {
	double new_scale_factor = abs(scale_factor);
	this -> radius = (this -> radius) * new_scale_factor;
};

  /**
* @brief returns the volume of the sphere
* @return the volume of the sphere
*/
double Sphere::getVolume() {
	return (this -> radius) * (this -> radius) * (this -> radius) * 
	3.141592653589793238462643383279502884L * (4 / 3);
};

  /**
* @brief changes the volume of the sphere
* @details first, we calculate the radius from the desired volume and then use setRadius() to update the radius accordingly.
* @param new_volume the volume of the sphere
*/
void Sphere::setVolume(double new_volume) {
	double corrected_new_volume = abs(new_volume);
	double factor = (corrected_new_volume * 3) / (4 * 
	3.141592653589793238462643383279502884L);
	this -> radius = pow(factor, (1 / 3));
};

  /**
* @brief changes the volume of the sphere by a positive real number
* @details first, we calculate the new volume, and then use setVolume() to update the volume accordingly.
* @param scale_factor how many times bigger/smaller should the volume be?
*/
void Sphere::scaleVolume(double scale_factor) {
	double new_volume = (this -> getVolume()) * abs(scale_factor);
	this -> setVolume(new_volume);
};

  /**
* @brief returns the surface area of the sphere
* @return the surface area of the sphere
*/
double Sphere::getSurfaceArea() {
	return (this -> radius) * (this -> radius) * 3.141592653589793238462643383279502884L *
	4;
}; 

  /**
* @brief changes the surface area of the sphere
* @details we calculate the radius of the sphere from the desired surface area
* @param new_surface_area the desired surface area of the sphere
*/
void Sphere::setSurfaceArea(double new_surface_area) {
	this -> radius = (1 / 2) * pow((new_surface_area /
	3.141592653589793238462643383279502884L), (1 / 2));
};

  /**
* @brief multiplies the surface area of the sphere by a real number
* @details first, we calculate the new surface area, and then update it accordingly using setSurfaceArea()
* @param scale_factor how many times bigger/smaller should the surface area be?
*/
void Sphere::scaleSurfaceArea(double scale_factor) {
	double new_surface_area = (this -> getSurfaceArea()) * abs(scale_factor);
	this -> setSurfaceArea(new_surface_area);
};

  /**
* @brief is the point passed in on the surface of the sphere or not?
* @param p the point in question
* @return true when p is on the surface of the sphere. false otherwise.
*/
bool Sphere::pointOnSphere(Point p) { 
	return (Point::distanceBetweenPoints(this -> origin, p) == this -> radius);
};

  /**
* @brief is the point passed inside or on the surface of the sphere or not?
* @param p the point in question
* @return true when p is inside or on the surface of the sphere. false otherwise.
*/
bool Sphere::pointInSphere(Point p) {
	return (Point::distanceBetweenPoints(this -> origin, p) <= this -> radius);
};
