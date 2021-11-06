#pragma once
#include <math.h>
#include <cmath>
#include<iostream>

namespace Maths
{
	struct Vector2D
	{
		Vector2D(float x_ = 0, float y_ = 0) : x(x_), y(y_) {};
		float Dot(Vector2D other); //!< Get the dot product of two 2D vectors.
		float Magnitude(); //!< Get the magnitude of the vector.
		float Angle(Vector2D other); //!< Get the angle between 2 vectors.
		Vector2D operator+(Vector2D other); //!< Operator Overload for +.

		float x; //!< X component of the vector.
		float y; //!< Y component of the vector.
	};
	struct Vector3D //!< A data structure for 3 dimensional vectors.
	{
		Vector3D(float x_ = 0, float y_ = 0, float z_ = 0) : x(x_), y(y_), z(z_) {};  //!< Constructor for Vector.


		float Dot(Vector3D other); //!< Get the dot product of two 3D vectors.
		float Magnitude(); //!< Get the magnitude of the vector.
		Vector3D Cross(Vector3D other); //!< Get the cross product of two 3D vectors.
		Vector3D operator+(const Vector3D& other); //!< Operator Overload for +.
		Vector3D operator+=(const Vector3D& other); //!< Operator Overload for +=.
		
		

		void Back();
		void Down();
		void Forward();
		void Left();
		void One();
		void Right();
		void Up();
		void Zero();
		

		float x; //!< X component of the vector.
		float y; //!< Y component of the vector.
		float z; //!< Z component of the vector.
	};
	float lerp(float start, float end, float t); //!< Lerp function for floats.
	Vector2D lerp(Vector2D a, Vector2D b, float t); //!< Lerp function for Vector2D.
	Vector3D lerp(Vector3D a, Vector3D b, float t); //!< Lerp function for Vector3D.
	float Degrees(float r); //!< Convert to degrees.
	float Radians(float d); //!< Convert to radians.
	std::ostream& operator<<(std::ostream& os, const Maths::Vector3D vec); //!< Operator overload for << when using Vector3D.
	std::ostream& operator<<(std::ostream& os, const Maths::Vector2D vec); //!< Operator overload for << when using Vector2D.

	const Vector3D back(0, 0, -1);
	const Vector3D down(0, -1, 0);
	const Vector3D forward(0, 0, 1);
	const Vector3D left(-1, 0, 0);
	const Vector3D one(1, 1, 1);
	const Vector3D right(1, 0, 0);
	const Vector3D up(0, 1, 0);
	const Vector3D zero(0, 0, 0);

}