/** CSCI 3308
 * C++ Library Header File
 * Authors: Daniel Zurawski, Jay LeCavalier, Ryan Goss, Heather Witte
 */
 
#ifndef PLANE_H
#define PLANE_H
#include "LinePoint.h"

class Plane {
	private:
	//plane in form ax + by + cz + d = 0
		double a;
		double b;
		double c;
		double d;
		
	public:
		//constructors
		Plane();
		Plane(double aParam, double bParam, double cParam, double dParam);
		
		//getters
		double getA();
		double getB();
		double getC();
		double getD();
		
		//setters
		void setParameters(double aParam, double bParam, double cParam, double dParam);
		void setAParam(double aParam);
		void setBParam(double bParam);
		void setCParam(double cParam);
		void setDParam(double dParam);
	
};

#endif
