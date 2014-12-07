#include <list>
#include "LinePoint.h"

/**
 *  @brief Generic Polygon class
 *	@details Class of Polygon which user can create any shape
 *  @author Daniel Zurawski 
 *  @version 0.5
 *
 */
class Polygon {
	protected:
	std::list<Point> points;
	int sides;
	
	public:
	//Constructor
	Polygon();
	Polygon(std::list<Point> inputPoints);
	
	//Getters
	Point getPoint(double xCoord, double yCoord);
	std::list<Point> getPoints();
	int getNumberSides();
	
	//Setters
	void setPoint(double xCoord, double yCoord, double NewXCoord, double NewYCoord);
	void setPoint(double xCoord, double yCoord, double zCoord, double NewXCoord, double NewYCoord, double NewZCoord);
	void setPoint(Point oldPoint, Point newPoint);
	void addPoint(double xCoord, double yCoord);
	void addPoint(double xCoord, double yCoord, double zCoord);
	void addPoint(Point newPoint);

	//Methods
	Point getCentroid();
	void rotateOrigin(double angle);

	
};
	
