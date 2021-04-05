#include "Bomb.h"
#include "Ranges.h"

Bomb::Bomb(int totalBombs)
{
	this->totalBombs = totalBombs;
	fixBombsCount();
}

void Bomb::start()
{
	bombMap = new Matrix(Cell::ZERO);
	for (int i = 0; i < totalBombs; i++)
		placeBomb();
}

Cell Bomb::getCell(const Coord& coord) {
	return bombMap->getCell(coord);
}

int Bomb::getTotalBombs()
{
	return totalBombs;
}
void Bomb::placeBomb()
{
	while (true)
	{
		Coord coord = Ranges::getRandomCoord();
		if (Cell::BOMB == bombMap->getCell(coord))
			continue;
		bombMap->setCell(coord, Cell::BOMB);
		incNumbersAround(coord);
		break;
	}
}

void Bomb::incNumbersAround(const Coord& coord)
{
	auto aroundCells = Ranges::getCoordsAround(coord);
	for (auto i = aroundCells->begin(); i != aroundCells->end(); ++i)
		if (Cell::BOMB != bombMap->getCell(*i))
			bombMap->setCell(*i, static_cast<Cell>(bombMap->getCell(*i) + 1));
}

void Bomb::fixBombsCount()
{
	int maxBombs = Ranges::getSize().getX()*Ranges::getSize().getY() / 2;
	if (totalBombs > maxBombs)
		totalBombs = maxBombs;
}

Bomb::~Bomb()
{
	delete bombMap;
}