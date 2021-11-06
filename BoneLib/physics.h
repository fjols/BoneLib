#pragma once
#include "maths.h"

//Axis Alligned Bounding Box
struct AABB {
	Maths::Vector2D lowerBound;
	Maths::Vector2D upperBound;
};

//Struct for rotation, should be moved to maths
struct rotation {

	rotation() {}
	rotation(float angle)
	{
		sine = sinf(angle); //Maths func needed
		cosine = cosf(angle);
	}

	float sine, cosine;

	void Set(float angle)
	{
		sine = sinf(angle); //Maths func needed
		cosine = cosf(angle);
	}

	void setIdentity()
	{
		sine = 0.0f;
		cosine = 1.0f;
	}
};

//Struct to handle object transform parameters --- should move to maths
struct transfrom {
	transfrom() {}
	transfrom(const Maths::Vector2D& pos, const rotation& rot) : p(pos), r(rot) {}

	Maths::Vector2D p;
	rotation r;

	void Set(const Maths::Vector2D& pos, float angle)
	{
		p = pos;
		r.Set(angle);
	}
};
//2D shape base class
class shape2D
{
public:
	enum Type {
		CIRCLE = 0,
		POLYGON = 1,
		CAPSULE = 2
	};

	virtual ~shape2D() {}

	Type m_type;
	Maths::Vector2D m_position;
	float m_radius;

	bool collisionAAB(AABB* coll) {

	};
};

class boxShape2D : public shape2D
{
	boxShape2D();
	boxShape2D(Maths::Vector2D pos);
	boxShape2D(Maths::Vector2D pos, float rad);
};
#pragma once
