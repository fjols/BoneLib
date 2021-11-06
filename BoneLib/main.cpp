#include "maths.h"
#include <iostream>

int main()
{
	Maths::Vector3D vec1(2, 2, 2);
	Maths::Vector3D vec2(3, 3, 3);
	Maths::Vector2D vector1(3, 4);
	Maths::Vector2D vector2(4, 3);
	Maths::Vector3D res = vec1 + vec2;
	Maths::Vector2D result = vector1 + vector2;
	std::cout << vec1 + vec2 << std::endl;
	std::cout << vector1 + vector2;
	return 0;
}