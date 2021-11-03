#include "maths.h"

float Maths::lerp(float start, float end, float t)
{
	return start + t * (end - start);
}

Maths::Vector3D Maths::lerp(Maths::Vector3D a, Maths::Vector3D b, float t)
{
	// Interpolate all the components of the vector.
	float X = a.x + t * (b.x - a.x);
	float Y = a.y + t * (b.y - a.y);
	float Z = a.z + t * (b.z - a.z);
	Vector3D result(X, Y, Z); // Construct a new vector using these values.
	return result; // Return the new vector.
}

