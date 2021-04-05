#pragma once
#pragma once
#include "Config.h"
#include "Coord.h"
#include "Bomb.h"
#include "Flag.h"

//////////////////////////////////////////
// GAME
//
//describe game logic
/////////////////////////////////////////
class Game
{
private:
	Flag* flagMap;
	GameState status;
	Bomb* bombMap;
	void openCell(const Coord& coord);
	void setOpenedToClosedBoxesAroundNumber(const Coord& coord);
	void openBombs(const Coord& bomed);
	void openBoxAround(const Coord& coord);
	void check();
public:
	Game(int rows, int cols, int bombs);
	GameState getStatus();
	Cell getCell(const Coord& coord);
	void pressLeftButton(const Coord& coord);
	void pressRightButton(const Coord& coord);
	bool gameOver();
	~Game();
};