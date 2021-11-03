#include "maths.h"
#include <iostream>

int main()
{
	Maths::Vector3D vec1(4, 12, 4);
	Maths::Vector3D vec2(7, 2, 5);
	Maths::Vector3D result = vec1.Cross(vec2);
	std::cout << result.x << " " << result.y << " " << result.z;
	return 0;
}