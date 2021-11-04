#include "maths.h"

float Maths::lerp(float start, float end, float t)
{
	return start + t * (end - start);
}

Maths::Vector2D Maths::lerp(Maths::Vector2D a, Maths::Vector2D b, float t)
{
	float X = a.x + t * (b.x - a.x);
	float Y = a.y + t * (b.y - a.y);
	Maths::Vector2D result(X, Y);
	return result;
}

float Maths::Degrees(float r)
{
	return r * 180 / 3.14;
}

float Maths::Radians(float d)
{
	return d * 3.14 / 180;
}

Maths::Vector3D Maths::lerp(Maths::Vector3D a, Maths::Vector3D b, float t)
{
	// Interpolate all the components of the vector.
	float X = a.x + t * (b.x - a.x);
	float Y = a.y + t * (b.y - a.y);
	float Z = a.z + t * (b.z - a.z);
	Maths::Vector3D result(X, Y, Z); // Construct a new vector using these values.
	return result; // Return the new vector.
}

float Maths::Vector3D::Dot(Maths::Vector3D other)
{
	return (this->x * other.x) + (this->y * other.y) + (this->z * other.z);
}

float Maths::Vector3D::Magnitude()
{
	return std::sqrt(this->x*this->x + this->y*this->y + this->z*this->z);
}

Maths::Vector3D Maths::Vector3D::Cross(Maths::Vector3D other)
{
	float X = this->y * other.z - this->z * other.y;
	float Y = this->z * other.x - this->x * other.z;
	float Z = this->x * other.y - this->y * other.x;
	Maths::Vector3D result(X, Y, Z);
	return result;
}

float Maths::Vector2D::Dot(Maths::Vector2D other)
{
	return (this->x * other.x) + (this->y * other.y);
}

float Maths::Vector2D::Magnitude()
{
	return abs(std::sqrt(this->x*this->x + this->y*this->y));
}

float Maths::Vector2D::Angle(Maths::Vector2D other)
{
	float dotProd = this->Dot(other);
	float vecOneMag = this->Magnitude();
	float vecTwoMag = this->Magnitude();
	float angle = dotProd / vecOneMag * vecTwoMag;
	return abs(cos(angle));
}
