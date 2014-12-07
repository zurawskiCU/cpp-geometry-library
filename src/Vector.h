#ifndef VECTOR_H
#define VECTOR_H

class Vector{
	private:
	
		/*////////////
		/ ATTRIBUTES /
		////////////*/ 
		
		double * values; // This attribute will store an array of numbers, which 
		//correspond to the coordinates of the vector
		
	public:
	
		/*//////////////
		/ CONSTRUCTORS /
		//////////////*/
		
		Vector(); // Default constructor
		Vector(int dimensions_input); // Dimension specific constructor
		Vector(double * values_input); // User already has an array of coordinates ready
		Vector(int dimensions_input, double * values_input); // Complete constructor
		
		/*/////////
		/ GETTERS /
		/////////*/
		
		int get_Dimensions(); // Returns the number of coordinates of the vector
		double get_Magnitude(); // Returns the magnitude of the vector
		double get_Entry_N(int n); // Returns the nth coordinate of the vector
		double * get_Values(); // Returns an array of all coordinates of the vector
		
		/*/////////
		/ SETTERS /
		/////////*/
		
		void set_Dimensions(int n); // Sets dimensions of the vector
		void set_Entry_N(double n); // Sets the nth coordinate of the vector
		void set_Values(double * n); // Sets all coordinates to an array of doubles
		void set_Zero_Vector(); // Sets all coordinates to zero
		
		/*/////////////////////
		/ GEOMETRIC FUNCTIONS /
		/////////////////////*/
		
		Vector * scaled_Vector(double scalar); // returns the calling vector scaled by
		// a real number constant called scalar.
		void scale_Vector(double scalar); // Scales the calling vector by a real 
		// number constant called scalar.
		Vector * add_Two_Vectors(Vector * v, Vector * u); // Returns a vector which is the
		// sum of two other vectors, v and u.
		Vector * add_Two_Scaled_Vectors(Vector * v, double v_scale, Vector * u, double u_scale);
		// Returns a vector which is the sum of two other vectors v and u. v and u are
		// scaled first by constants v_scale and u_scale, and then added together.
		void invert_Vector(); // Scales the vector by -1


};

#endif