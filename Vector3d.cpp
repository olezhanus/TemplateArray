#include "Vector3d.h"

Vector3d::Vector3d(int X, int Y, int Z) : X(X), Y(Y), Z(Z)
{
}

bool Vector3d::operator==(const Vector3d &right)
{
	return (X == right.X && Y == right.Y && Z == right.Z);
}

std::ostream &operator<<(std::ostream &os, const Vector3d &v)
{
	return os << "{ " << v.X << ", " << v.Y << ", " << v.Z << " }";
}
