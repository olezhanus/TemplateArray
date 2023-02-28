#pragma once
#include <iostream>

struct Vector3d
{
	int X;
	int Y;
	int Z;
};
std::ostream &operator<<(std::ostream &os, const Vector3d &v)
{
	return os << "{ " << v.X << ", " << v.Y << ", " << v.Z << " }";
}
