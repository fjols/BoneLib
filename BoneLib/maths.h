#pragma once

namespace Maths
{
	struct Vector2D
	{
		Vector2D(float x_, float y_)
		{
			x = x_;
			y = y_;
		};

		float Dot(Vector2D other);

		float x;
		float y;
	};
	struct Vector3D //!< A data structure for 3 dimensional vectors.
	{
		Vector3D(float x_, float y_, float z_) //!< Constructor for Vector.
		{
			x = x_;
			y = y_;
			z = z_;
		};

		float Dot(Vector3D other);
		Vector3D Cross(Vector3D other);

		float x;
		float y;
		float z;
	};
	float lerp(float start, float end, float t); //!< Lerp function for floats.
	Vector2D lerp(Vector2D a, Vector2D b, float t); //!< Lerp function for Vector2D.
	Vector3D lerp(Vector3D a, Vector3D b, float t); //!< Lerp function for Vector3D.
}