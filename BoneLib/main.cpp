#include "maths.h"
#include <iostream>

int main()
{
	Maths::Vector2D vec1(3, 7);
	Maths::Vector2D vec2(3, 5);
	std::cout << vec1.Magnitude() << std::endl;
	std::cout << vec2.Magnitude() << std::endl;
	std::cout << acos(44.42);
	std::cout << Maths::Degrees(vec1.Angle(vec2)) << std::endl;
	std::cout << Maths::Radians(56.7);
	return 0;
}