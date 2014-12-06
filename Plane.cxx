/** CSCI 3308
 * C++ Library Class File
 * Authors: Daniel Zurawski, Jay LeCavalier, Ryan Goss, Heather Witte
 */
 
#include "Plane.h"

//Constructors
Plane::Plane() {
//default constructor creates plane where z=0
	a = 0;
	b = 0;
	c = 1;
	d = 0;
}

Plane::Plane(double aParam, double bParam, double cParam, double dParam) {
	a = aParam;
	b = bParam;
	c = cParam;
	d = dParam;
}

//Getters
double Plane::getA(){
	return a;
}
		
double Plane::getB(){
	return b;
}
		
double Plane::getC(){
	return c;
}

double Plane::getD(){
	return d;
}

//Setters
void Plane::setParameters(double aParam, double bParam, double cParam, double dParam){
		a = aParam;
		b = bParam;
		c = cParam;
		d = dParam;
}

void Plane::setAParam(double aParam){
	a = aParam;
}

void Plane::setBParam(double bParam){
	b = bParam;
}

void Plane::setCParam(double cParam){
	c = cParam;
}
		
void Plane::setDParam(double dParam){
	d = dParam;
}



