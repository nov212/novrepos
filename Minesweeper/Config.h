#pragma once
#pragma once

///////////////////////////////////////
// CONFIG
//
// contains game settings
//////////////////////////////////////


//game field size in cells
const int COLS = 9;
const int ROWS = 9;

const int IMAGE_SIZE = 50; //cell size in pixels
const int BOMBS = 10; //count of bombs

enum Cell
{
	ZERO,
	NUM1,
	NUM2,
	NUM3,
	NUM4,
	NUM5,
	NUM6,
	NUM7,
	NUM8,
	BOMB,
	OPENED,
	CLOSED,
	FLAGED,
	BOMBED,
	NOBOMB
};

enum GameState
{
	PLAYED, //game is active
	LOSER,	//game ends with lose
	WINNER	//game ends with victory
};
