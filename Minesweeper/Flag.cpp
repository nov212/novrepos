#include "Flag.h"
#include "Config.h"
#include "Ranges.h"

Flag::Flag()
{
	flagMap = new Matrix(Cell::CLOSED);
	countOfClosedBoxes = Ranges::getSize().getX()*Ranges::getSize().getY();
}

Cell Flag::getCell(const Coord& coord)
{
	return flagMap->getCell(coord);
}

void Flag::setOpenedCell(const Coord& coord)
{
	flagMap->setCell(coord, Cell::OPENED);
	countOfClosedBoxes--;
}

void Flag::toggleFlagedCell(const Coord& coord)
{
	if (flagMap->getCell(coord) == Cell::FLAGED)
		setClosedCell(coord);
	else
		if (flagMap->getCell(coord) == Cell::CLOSED)
			setFlagedCell(coord);
}

void Flag::setBombedCell(const Coord& coord)
{
	flagMap->setCell(coord, Cell::BOMBED);
}

void Flag::setOpenedToClosedBombCell(const Coord& coord)
{
	if (flagMap->getCell(coord) == Cell::CLOSED)
		flagMap->setCell(coord, Cell::BOMB);
}

void Flag::setNoBombToFlagedCell(const Coord& coord)
{
	if (flagMap->getCell(coord) == Cell::FLAGED)
		flagMap->setCell(coord, Cell::NOBOMB);
}

void Flag::setClosedCell(const Coord& coord)
{
	flagMap->setCell(coord, Cell::CLOSED);
}

void Flag::setFlagedCell(const Coord& coord) {
	flagMap->setCell(coord, Cell::FLAGED);
}

int Flag::getCountOfClosedCells()
{
	return countOfClosedBoxes;
}

int Flag::getCountOfFlagedCellsAround(const Coord& coord)
{
	int count = 0;
	auto aroundCells = Ranges::getCoordsAround(coord);
	for (auto i = aroundCells->begin(); i != aroundCells->end(); ++i)
		if (flagMap->getCell(coord) == Cell::FLAGED)
			count++;
	delete aroundCells;
	return count;
}

Flag::~Flag()
{
	delete flagMap;
}