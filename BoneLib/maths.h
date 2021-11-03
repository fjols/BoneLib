#pragma once

namespace Maths
{
	struct Vector3D //!< A data structure for 3 dimensional vectors.
	{
		Vector3D(float x_, float y_, float z_) //!< Constructor for Vector.
		{
			x = x_;
			y = y_;
			z = z_;
		};
		float x;
		float y;
		float z;
	};
	float lerp(float start, float end, float t); //!< Lerp function for floats
	Vector3D lerp(Vector3D a, Vector3D b, float t); //!< Lerp function for Vector3D.
}