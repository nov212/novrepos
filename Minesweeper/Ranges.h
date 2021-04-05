#pragma once
#pragma once
#include "Coord.h"
#include <vector>

static class Ranges
{
private:
	static Coord size;
	static std::vector<Coord> cells;
public:
	static void setSize(const Coord& fieldSize);
	static Coord& getSize();
	static bool inRange(const Coord& point);
	static std::vector<Coord>& getAllCoords();
	static Coord getRandomCoord();
	static std::vector<Coord>* getCoordsAround(const Coord& coord);
};
