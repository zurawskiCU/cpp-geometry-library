
#include <cmath>
 
#ifndef LINEPOINT_H
#define LINEPOINT_H


/**
* @brief Point class
* @details A class to represent points in 3-dimensional cartesian space.
* @author Daniel Zurawski, Jay LeCavalier, Ryan Goss, Heather Witte
*/

class Point {
	private:
		double x;
		double y;
		double z;
	
	public:
		//Constructors
		Point();
		Point(double xCoord, double yCoord);
		Point(double xCoord, double yCoord, double zCoord);
		
		//Getters
		double getXCoord() const;
		double getYCoord() const;
		double getZCoord() const;
		
		//Setters
		void setCoords(double xCoord, double yCoord);
		void setCoords(double xCoord, double yCoord, double zCoord);
		void setXCoord(double xCoord);
		void setYCoord(double yCoord);
		void setZCoord(double zCoord);
		
		//Geometric Functions
		static bool pointsEqual(Point a, Point b);
		static double distanceBetweenPoints(Point a, Point b);
		void pointXShift(double n);
		void pointYShift(double n);
		void pointZShift(double n);

		void rotateOrigin(double angle);
		void rotateAround(Point center, double angle);
		void rotateAround(double xcenter, double ycenter);

		static double getXDist(Point p1, Point p2);
		static double getYDist(Point p1, Point p2);
		static double getZDist(Point p1, Point p2);
		
		//Operators
		Point& operator=(const Point& anotherPoint);
		friend bool operator==(const Point& a, const Point& b);
		

};

/**
 * @brief Line class
 * @details A class to represent lines in 3-dimensional cartesian space. Lines are defined by their end-points.
 * @author Daniel Zurawski, Jay LeCavalier, Ryan Goss, Heather Witte
 */
class Line {
	private:
		Point p1;
		Point p2;
		
	public:
		//Constructors
		Line();
		Line(Point point1, Point point2);
		
		//Getters
		Point getPoint(int pointNumber) const;
		double getXDist(Line my_line);
		double getYDist(Line my_line);
		double getZDist(Line my_line);
		
		//Setters
		void setPoint(Point newPoint, int pointNumber);	
		
		//Geometric Functions
		static bool linesEqual(Line a, Line b);
		static double lineLength(Line my_line);
		void lineXShift(double n);
		void lineYShift(double n);
		void lineZShift(double n);
		bool pointOnLine(Point p);
		
		//Operators
		Line& operator=(const Line& anotherLine);
		friend bool operator==(const Line& a, const Line& b);
};


#endif
