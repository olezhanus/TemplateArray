#pragma once
#include <iostream>

struct Vector3d
{
	Vector3d(int X = 0, int Y = 0, int Z = 0);
	int X;
	int Y;
	int Z;
	bool operator==(const Vector3d &right);
};

std::ostream &operator<<(std::ostream &os, const Vector3d &v);