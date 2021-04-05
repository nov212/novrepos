#pragma once
#pragma once
#include "Config.h"
#include "Coord.h"

class Matrix
{
private:
	Cell** matrix;
public:
	Matrix(Cell defaultCell);
	Cell getCell(const Coord& coord);
	void setCell(const Coord& coord, Cell status);
	~Matrix();
};
