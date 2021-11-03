#include "maths.h"
#include <iostream>

int main()
{
	Maths::Vector3D vec1(136, 8, 8);
	Maths::Vector3D vec2(204, 85, 0);
	Maths::Vector3D result = Maths::lerp(vec1, vec2, 0.44);
	std::cout << "X: " << result.x << std::endl;
	std::cout << "Y: " << result.y << std::endl;
	std::cout << "Z: " << result.z << std::endl;
	return 0;
}