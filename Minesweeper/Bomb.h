#pragma once
#pragma once
#include "Matrix.h"
#include "Config.h"

//////////////////////////////////////
// BOMB
// first layer of game field
// consists of bomb cells and number cells
//////////////////////////////////////

class Bomb
{
private:
	Matrix* bombMap;
	int totalBombs;
	void placeBomb();
	void incNumbersAround(const Coord& coord);
	void fixBombsCount();

public:
	Bomb(int totalBombs);
	void start();
	Cell getCell(const Coord& coord);
	int getTotalBombs();
	~Bomb();
};