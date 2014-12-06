/** CSCI 3308
 * Test file for LinePoint
 * Authors: Daniel Zurawski, Jay LeCavalier, Ryan Goss, Heather Witte
 */
 
 #include "LinePoint.h"
 #include <iostream>
 using namespace std;
 
 int main() {
	
//tests for Point class
	Point defaultPoint;
	Point point1(1,7);
	Point point2(3, 9);
	
	//test getXCoord()	
	if (defaultPoint.getXCoord() == 0 and point1.getXCoord() == 1 and point2.getXCoord() == 3)
		cout<<"Point.getXCoord() passed"<<endl;
	else
		cout<<"Point.getXCoord() failed"<<endl;
		
	//test getYCoord()	
	if (defaultPoint.getYCoord() == 0 and point1.getYCoord() == 7 and point2.getYCoord() == 9)
		cout<<"Point.getYCoord() passed"<<endl;
	else
		cout<<"Point.getYCoord() failed"<<endl;
		
	//test setXCoord()
	defaultPoint.setXCoord(8);	
	point1.setXCoord(5);
	point2.setXCoord(2.7);
	
	if (defaultPoint.getXCoord() == 8 and point1.getXCoord() == 5 and point2.getXCoord() == 2.7)
		cout<<"Point.setXCoord() passed"<<endl;
	else
		cout<<"Point.setXCoord() failed"<<endl;
		
	//test for setYCoord()
	defaultPoint.setYCoord(3);	
	point1.setYCoord(9.9);
	point2.setYCoord(0);
	
	if (defaultPoint.getYCoord() == 3 and point1.getYCoord() == 9.9 and point2.getYCoord() == 0)
		cout<<"Point.setYCoord() passed"<<endl;
	else
		cout<<"Point.setYCoord() failed"<<endl;
		
	//test for setCoords()	
	defaultPoint.setCoords(2,8);	
	point1.setCoords(6.2, 1);
	point2.setCoords(3, 7.1);
	
	if (defaultPoint.getXCoord() == 2 and defaultPoint.getYCoord() == 8 and point1.getXCoord() == 6.2 and point1.getYCoord() == 1 and point2.getXCoord() == 3 and point2.getYCoord() == 7.1)
		cout<<"Point.setCoords() passed"<<endl;
	else
		cout<<"Point.setCoords() failed"<<endl;
		
//tests for Line class
	
	Line defaultLine;
	Line line1(point1, point2);
	
		
	
		

		
		
	
	
	


	return 0;
};
