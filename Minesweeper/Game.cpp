#include "Game.h"
#include "Ranges.h"

Game::Game(int rows, int cols, int bombs)
{
	Coord size(rows, cols);
	Ranges::setSize(size);
	bombMap = new Bomb(bombs);
	bombMap->start();
	flagMap = new Flag();
	status = GameState::PLAYED;
}

GameState Game::getStatus()
{
	return status;
}

Cell Game::getCell(const Coord& coord)
{
	if (flagMap->getCell(coord) == Cell::OPENED)
		return bombMap->getCell(coord);
	else
		return flagMap->getCell(coord);
}

void Game::check()
{
	if (status == GameState::PLAYED)
		if (flagMap->getCountOfClosedCells() == bombMap->getTotalBombs())
			status = GameState::WINNER;
}

void Game::openCell(const Coord& coord)
{
	switch (flagMap->getCell(coord))
	{
	case OPENED: setOpenedToClosedBoxesAroundNumber(coord);
		break;
	case FLAGED: return;
	case CLOSED:
		switch (bombMap->getCell(coord))
		{
		case ZERO:
			openBoxAround(coord);
			break;
		case BOMB:
			openBombs(coord);
			return;
		default: flagMap->setOpenedCell(coord);
		}

	}
}

void Game::setOpenedToClosedBoxesAroundNumber(const Coord& coord)
{
	if (bombMap->getCell(coord) != Cell::BOMB)
		if (flagMap->getCountOfFlagedCellsAround(coord) == static_cast<int>(bombMap->getCell(coord)))
		{
			auto aroundCoords = Ranges::getCoordsAround(coord);
			for (auto around = aroundCoords->begin(); around != aroundCoords->end(); ++around)
				if (flagMap->getCell(*around) == Cell::CLOSED)
					openCell(*around);
			delete aroundCoords;
		}
}

void Game::openBombs(const Coord& coord)
{
	status = GameState::LOSER;
	flagMap->setBombedCell(coord);
	auto allCoords = Ranges::getAllCoords();
	for (auto i = allCoords.begin(); i != allCoords.end(); ++i)
		if (bombMap->getCell(*i) == Cell::BOMB)
			flagMap->setOpenedToClosedBombCell(*i);
		else
			flagMap->setNoBombToFlagedCell(*i);
}

void Game::openBoxAround(const Coord& coord)
{
	flagMap->setOpenedCell(coord);
	std::vector<Coord> *aroundCoords = Ranges::getCoordsAround(coord);
	for (auto around = aroundCoords->begin(); around != aroundCoords->end(); ++around)
		openCell(*around);
	delete aroundCoords;
}

void Game::pressLeftButton(const Coord& coord)
{
	if (gameOver())
		return;
	openCell(coord);
	check();
}

void Game::pressRightButton(const Coord& coord)
{
	if (gameOver())
		return;
	flagMap->toggleFlagedCell(coord);
}

bool Game::gameOver()
{
	if (status == GameState::PLAYED)
		return false;
	return true;
}

Game::~Game()
{
	delete flagMap;
	delete bombMap;
}