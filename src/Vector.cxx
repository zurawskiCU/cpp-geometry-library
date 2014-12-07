#include "Vector.h"
#include <math.h>

/*//////////////
/ CONSTRUCTORS /
//////////////*/

//Default constructor
Vector::Vector(){
	values = 0;
}

// Dimension specific constructor
Vector::Vector(int dimensions_input){
	double arr[dimensions_input];
	values = arr;
}

// User already has an array of coordinates ready
Vector::Vector(double * values_input){
	values = values_input;
}

/*/////////
/ GETTERS /
/////////*/

// Returns the number of coordinates of the vector
int get_Dimensions(){
	return this->(values->size());
}

// Returns the magnitude of the vector
double get_Magnitude(){
	double temp = 0;
	for(int i=0;i<this->(values->size());i++){
		temp += ((this->values)+i);
	}
	return pow(temp, 0.5);
}

// Returns the nth coordinate of the vector
double get_Entry_N(int n){
	return ((this->values)+n);
}

// Returns an array of all coordinates of the vector
double * get_Values(){
	return this->values;
}

/*/////////
/ SETTERS /
/////////*/

// Sets dimensions of the vector
void set_Dimensions(int n){
	double this->arr[n];
	values = arr;
}

// Sets the nth coordinate of the vector
void set_Entry_N(int n, double input_number){
	(values+n) = input_number;
}

// Sets all coordinates to an array of doubles
void set_Values(double * n){
	values = n;
}

// Sets all coordinates to zero
void set_Zero_Vector(){
	for(int i=0;i<values->size();i++){
		(values+i) = 0;
	}
}

/*/////////////////////
/ GEOMETRIC FUNCTIONS /
/////////////////////*/

// returns the calling vector scaled by a real number constant called scalar
Vector * new_Scaled_Vector(double scalar){
	rVector = new Vector*;
	rVector->set_Values(values);
	for(int i=0;i<(rVector->get_Values())->size();i++){
		((rVector->get_Values)+i) = ((rVector->get_values)+i)*scalar;
	}
	return rVector;
}

// Scales the calling vector by a real number constant called scalar
void scale_Vector(double scalar){
	for(int i=0;i<values->size(){
		(values+i) = (values+i)*scalar;
	}
}

// Returns a vector which is the sum of two other vectors, v and u.
Vector * add_Two_Vectors(Vector * u){
	if(values->size()==(u->get_Values())->size()){
		rVector = new Vector*;
		rVector->set_Dimensions(v->size());
		for(int i=0;i<values->size();i++){
			rVector->set_Entry_N(i, (values+i)+((u->get_Values())->get_Entry_N(i));
		}
		return rVector;
	else{
		return 0;
	}
}