#include "maths.h"
#include <iostream>

int main()
{
	Maths::Vector3D myVec(1, 1, 1);
	myVec.Left();
	std::cout << myVec.x << " " << myVec.y << " " << myVec.z;
	return 0;
}