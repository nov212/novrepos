#include "Coord.h"

Coord::Coord(int _x, int _y) :x(_x), y(_y)
{}

Coord::Coord(const Coord& another)
{
	x = another.getX();
	y = another.getY();
}

int Coord::getX() const
{
	return x;
}

int Coord::getY() const
{
	return y;
}

bool Coord::operator==(const Coord& another)
{
	if (this == &another)
		return true;
	if (x == another.getX() && y == another.getY())
		return true;
	return false;
}

bool Coord::operator!=(const Coord& another)
{
	if (this == &another)
		return false;
	if (x != another.getX() || y != another.getY())
		return true;
	return false;
}

Coord& Coord::operator=(const Coord& another)
{
	if (this == &another)
		return *this;
	this->x = another.getX();
	this->y = another.getY();
	return *this;
}