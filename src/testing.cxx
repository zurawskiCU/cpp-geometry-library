// Tests the Point class constructors and methods
#include "LinePoint.h"
#include <iostream>

using namespace std;

int main(){
	/*
	Point * p1 = new Point(5, 6.7);
	Point * p2 = new Point(5, 7, 9);
	Point * p3 = new Point();
	Point * p4 = new Point(0, 44);
	Point * p5 = new Point(5, 6.7);
	if(Point::pointsEqual(*p1, *p2)){
		cout<<"TRUE\n\n";
	}
	else{
		cout<<"FALSE\n\n";
	}
	cout<<Point::distanceBetweenPoints(*p1, *p2)<<"\n\n";
	if(Point::pointsEqual(*p1, *p5)){
		cout<<"TRUE\n\n";
	}
	else{
		cout<<"FALSE";
	}
	cout<<Point::distanceBetweenPoints(*p3, *p4)<<"\n\n";
	p2->pointZShift(-9);
	if(Point::pointsEqual(*p1, *p2)){
		cout<<"TRUE\n\n";
	}
	else{
		cout<<"FALSE\n\n";
	}
	*/
	
	Point * a = new Point(2, 4, 2);
	Point * b = new Point(3, 7, -3);
	Line * l = new Line(*a, *b);
	Point * c = new Point(1, 3, 3);
	if(l->pointOnLine(*c)){
		cout<<"TRUE\n\n";
	}
	else{
		cout<<"FALSE\n\n";
	}
	
	Point * a2 = new Point(2, 4, 2);
	Point * b2 = new Point(3, 7, -3);
	Line * l2 = new Line(*a2, *b2);
	Point * c2 = new Point(1, 1, 7);
	if(l2->pointOnLine(*c2)){
		cout<<"TRUE\n\n";
	}
	else{
		cout<<"FALSE\n\n";
	}
	
	Point * a3 = new Point(0, 0, 0);
	Point * b3 = new Point(0, 0, 0);
	Line * l3 = new Line(*a3, *b3);
	Point * c3 = new Point(1, 0, 0);
	if(l3->pointOnLine(*c3)){
		cout<<"TRUE\n\n";
	}
	else{
		cout<<"FALSE\n\n";
	}
	
return 0;
};