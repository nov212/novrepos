#include "Ranges.h"
#include <time.h>
#include<stdlib.h>

Coord Ranges::size;
std::vector<Coord> Ranges::cells;

void Ranges::setSize(const Coord& fieldSize)
{
	size = fieldSize;
	for (int x = 0; x < size.getX(); x++)
		for (int y = 0; y < size.getY(); y++)
			cells.push_back(Coord(x, y));
	srand(time(NULL));
}

Coord& Ranges::getSize()
{
	return size;
}

bool Ranges::inRange(const Coord& coord)
{
	if (coord.getX() >= 0 && coord.getX() < size.getX() && coord.getY() >= 0 && coord.getY() < size.getY())
		return true;
	return false;
}

std::vector<Coord>& Ranges::getAllCoords()
{
	return cells;
}

Coord Ranges::getRandomCoord()
{
	return Coord(rand() % size.getX(), rand() % size.getY());
}

std::vector<Coord>* Ranges::getCoordsAround(const Coord& coord)
{
	Coord around;
	std::vector<Coord>* aroundCells = new std::vector<Coord>();
	for (int x = coord.getX() - 1; x <= coord.getX() + 1; x++)
		for (int y = coord.getY() - 1; y <= coord.getY() + 1; y++)
		{
			around = Coord(x, y);
			if (inRange(around))
				if (around != coord)
					aroundCells->push_back(around);
		}
	return aroundCells;
}