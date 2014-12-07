#include "RegularPolygon.h"
		
//Constructors

 /**
* @brief Default Regular Polygon Constructor
* @details Creates a Regular Polygon with 3 sides and a side length of 1
*/
RegularPolygon::RegularPolygon(){
	RegularPolygon(3, 1);
}

 /**
* @brief  Regular Polygon Constructor
* @details Creates a Regular Polygon; allows the user to define the number of sides and the side length; the first point of the polygon is located at Point(0,0)
* @param numberSides The number of sides of the Regular Polygon
* @param sideLen The length of each side of the Regular Polygon
*/
RegularPolygon::RegularPolygon(int numberSides, double sideLen){
	sides = numberSides;
	sideLength = sideLen;
	interiorAngle = (numberSides-2)*(180/numberSides);
	double centerX = sideLen/2;
	double centerY = centerX*tan((interiorAngle/2)*(M_PI/180));
	centerPoint = Point(centerX, centerY);
	
	
	Point nextPoint(0,0);
	
	for (int i=0; i<numberSides; i++) {
		points.push_back(nextPoint);
		nextPoint.rotateAround(centerPoint, interiorAngle);
		}
}

/**
* @brief  Regular Polygon Constructor
* @details Creates a Regular Polygon; allows the user to define the number of sides, the side length, and the center point
* @param numberSides The number of sides of the Regular Polygon
* @param sideLen The length of each side of the Regular Polygon
* @param center The center point of the Regular Polygon
*/
RegularPolygon::RegularPolygon(int numberSides, double sideLen, Point center){
	sides = numberSides;
	sideLength = sideLen;
	centerPoint = center;
	interiorAngle = (sideLen-2)*(180/numberSides);
	double apothem = (sideLen*tan(interiorAngle/2))/2;
	double nextX = (center.getXCoord())-(.5*sideLen);
	double nextY = (center.getYCoord())-apothem;
	Point nextPoint(nextX, nextY);

	for (int i=0; i<numberSides; i++) {
		points.push_back(nextPoint);
		nextPoint.rotateAround(center, interiorAngle);
	};
}
		
//Getters	

/**
* @brief  Returns the center point of the Regular Polygon
* @return Returns the center point of the Regular Polygon
*/	
Point RegularPolygon::getCenter() const{
	return centerPoint;
}		

/**
* @brief  Returns the side length of the Regular Polygon
* @return Returns the side length of the Regular Polygon
*/		
double RegularPolygon::getSideLength() const{
	return sideLength;
}

/**
* @brief  Returns the measurement of the interior angle of the Regular Polygon
* @return Returns the measurement of the interior angle of the Regular Polygon
*/
double RegularPolygon::getInteriorAngle() const{
	return interiorAngle;
}

//Setters

/**
* @brief Updates the length of each side of the Regular Polygon
* @details Changes the side length of the Regular Polygon, leaving the number of sides and center point constant
* @param length The new side length of the Regular Polygon
*/
void RegularPolygon::setSideLength(double length){
	sideLength = length;
	double apothem = this->getApothem();
	double newX = (this->getCenter().getXCoord())-(.5*length);
	double newY = (this->getCenter().getYCoord())-apothem;
	Point nextPoint(newX, newY);
	
	points.clear();
	for (int i=0; i<this->getNumberSides(); i++) {
		points.push_back(nextPoint);
		nextPoint.rotateAround(this->getCenter(), this->getInteriorAngle());
	}; 
}

/**
* @brief Updates the number of sides of the Regular Polygon
* @details Changes the number of sides of the Regular Polygon, leaving the side length and center point constant
* @param numSides The new number of sides for the Regular Polygon
*/
void RegularPolygon::setNumberOfSides(int numSides){
	sides = numSides;
	interiorAngle = (this->getNumberSides()-2)*(180/this->getNumberSides());
	this->setSideLength(this->getSideLength());
}	

/**
* @brief Updates the area of the Regular Polygon
* @details Changes the Regular Polygon to have the defined area, leaving the number of sides and center point constant
* @param area The new area of the Regular Polygon
*/		
void RegularPolygon::setArea(double area){
	double newSideLength = sqrt((4*area)/(this->getNumberSides()*(1/tan(180/this->getNumberSides()))));
	this->setSideLength(newSideLength);
}				

/**
* @brief Updates the Perimeter of the Regular Polygon
* @details Changes the side length of the Regular Polygon, leaving the number of sides and center point constant
* @param perimeter The new perimeter of the Regular Polygon
*/
void RegularPolygon::setPerimeter(double perimeter){
	double newSideLength = perimeter/(this->getNumberSides());
	this->setSideLength(newSideLength);
}

/**
* @brief Updates the circumradius of the Regular Polygon
* @details Changes the side length of the Regular Polygon, leaving the number of sides and center point constant
* @param radius The new circumradius of the Regular Polygon
*/		
void RegularPolygon::setCircumradius(double radius){
	double newSideLen = 2*radius*sin((this->getInteriorAngle())/2);
	this->setSideLength(newSideLen);
}

/**
* @brief Updates the apothem of the Regular Polygon
* @details Changes the side length of the Regular Polygon, leaving the number of sides and center point constant
* @param apothem The new apothem of the Regular Polygon
*/		
void RegularPolygon::setApothem(double apothem){
	double newSideLen = 2 * apothem/(tan((this->getInteriorAngle())/2));
	this-> setSideLength(newSideLen);
} 

/**
* @brief Updates the center point of the Regular Polygon
* @details Shifts the entire Regular Polygon to the new center point
* @param newCenter The new center point of the Regular Polygon
*/
void RegularPolygon::setCenter(Point newCenter){
	double xShift =  newCenter.getXCoord() - this->getCenter().getXCoord();
	double yShift =  newCenter.getYCoord() - this->getCenter().getYCoord();
	centerPoint = newCenter;
	
	for (std::list<Point>::iterator i = points.begin(); i != points.end(); i++) {
		Point p = *i;
		p.pointXShift(xShift);
		p.pointYShift(yShift);
	} 
} 

/**
* @brief Calculates the perimeter of the Regular Polygon
* @return The perimeter of the Regular Polygon
*/
double RegularPolygon::getPerimeter(){
	return (this->getSideLength())*(this->getNumberSides());
}

/**
* @brief Calculates the area of the Regular Polygon
* @return The area of the Regular Polygon
*/		
double RegularPolygon::getArea(){
	return ((((this->getNumberSides())/4)*(this->getSideLength())*(this->getSideLength()))*(1/tan(M_PI/this->getNumberSides())));
}

/**
* @brief Calculates the circumradius of the Regular Polygon
* @details The circumradius of a Regular Polygon is the distance from the center point to any corner point of a Regular Polygon 
* @return The circumradius of the Regular Polygon
*/			
double RegularPolygon::getCircumradius(){
	return (this->getNumberSides())/(2*sin(M_PI/this-> getNumberSides()));
}

/**
* @brief Calculates the apothem of the Regular Polygon
* @details The apothem of a Regular Polygon is the distance from the center point to the midpoint of any side of a Regular Polygon 
* @return The apothem of the Regular Polygon
*/			
double RegularPolygon::getApothem(){
	return sqrt(((this->getSideLength()/(2*sin(M_PI/this->getNumberSides())))*(this->getSideLength()/(2*sin(M_PI/this->getNumberSides()))))-((this->getNumberSides()/2)*(this->getNumberSides()/2)));
}
