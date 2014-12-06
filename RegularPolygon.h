//Regular Polygon class

#include "Polygon.cxx"
#include "LinePoint.h"
#ifndef REGULARPOLYGON_H
#define REGULARPOLYGON_H

using namespace std;


/**
* @brief Regular Polygon class
* @details A class to represent regular polygons.
* @author Heather Witte
*/

class RegularPolygon : public Polygon {
	private:
		Point centerPoint;
		double sideLength;
		double interiorAngle;
		
	public:
		//Constructors
		RegularPolygon();
		RegularPolygon(int numberSides, double sideLen);
		RegularPolygon(int numberSides, double sideLen, Point center);
		
		//Getters
		Point getCenter() const;
		double getSideLength() const;
		double getInteriorAngle() const;

	
		//Setters
		//the centerPoint of the polygon will remain the same for all setters
		void setSideLength(double length);
		void setNumberOfSides(int numSides);	//will keep sideLength constant		
		void setArea(double area);				
		void setPerimeter(double perimeter);
		void setCircumradius(double radius);
		void setApothem(double apothem);
		void setCenter(Point newCenter);
		
	
		//Methods
		double getPerimeter();
		double getArea();
		//Circumradius is distance from any corner point to the center
		double getCircumradius();
		//Apothem is distance from the midpoint of any side to the center
		double getApothem();
		
	
};

#endif
