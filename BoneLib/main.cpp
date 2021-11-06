#include "maths.h"
#include <iostream>

int main()
{
	Maths::Vector3D myVec;
	Maths::Vector3D otherVec(3, 6, 7);
	
	myVec += otherVec;
	std::cout << myVec;
	return 0;
}