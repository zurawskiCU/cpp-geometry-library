/** CSCI 3308
 * C++ Library Header File
 * Authors: Daniel Zurawski, Jay LeCavalier, Ryan Goss, Heather Witte
 */
 
 #include <cmath>
 #include "LinePoint.h"
 
 #ifndef SPHERE_H
 #define SPHERE_H
 
 class Sphere{
 	private:
 		Point origin;
 		double radius;
 		
 	public:
 		//! Constructors
 		Sphere(); //! Default constructor
 		Sphere(Point new_origin); //! Constructor with origin only
 		Sphere(double new_radius); //! Constructor with radius only
 		Sphere(Point new_origin, double new_radius); //! Complete constructor
 		
 		//! Getters
 		Point getOrigin(); //! Returns origin
 		double getRadius(); //! Returns radius
 		
 		//! Setters
 		void setOrigin(Point new_origin); //! Change the origin
 		void setRadius(double new_radius); //! Change the radius
 		
 		//! Geometric Functions
 		void moveSphere(double horizontal_shift, double vertical_shift, double depth_shift); //! Moves Sphere
 		void scaleRadius(double scale_factor); //! scales the radius
 		double getVolume(); //! returns the volume of the sphere
 		void setVolume(double new_volume); //! Sets the volume of the sphere
 		void scaleVolume(double scale_factor); //! scales the volume
 		double getSurfaceArea(); //! returns the surface area of the sphere
 		void setSurfaceArea(double new_surface_area); //! sets the surface area
 		void scaleSurfaceArea(double scale_factor); //! scales the surface area
 		bool pointOnSphere(Point p); //! returns true if p is on the sphere
 		bool pointInSphere(Point p); //! returns true if p is on or inside sphere
 
 };
 
 #endif