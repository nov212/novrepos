#pragma once
#pragma once
#include "Matrix.h"

//////////////////////////////////////////
// FLAG
//
// upper layer of game field
// consists of closed cells and flaged cells
///////////////////////////////////////////

class Flag
{
private:
	Matrix* flagMap;
	int countOfClosedBoxes;
public:
	Flag();
	Cell getCell(const Coord& coord);

	//mark cell as opened
	void setOpenedCell(const Coord& coord);

	//switch cell between closed and flaged states
	void toggleFlagedCell(const Coord& coord);

	//mark cell as bombed if player click cell with bomb
	void setBombedCell(const Coord& coord);

	//mark cell by strikethrough bomb icon if player set flag on cell without bomb
	void setNoBombToFlagedCell(const Coord& coord);

	//shows 
	void setOpenedToClosedBombCell(const Coord& coord);

	//set cell as closed
	void setClosedCell(const Coord& coord);

	//return count of unvisited cells 
	int getCountOfClosedCells();

	//return count of flaged cells around current cell
	int getCountOfFlagedCellsAround(const Coord& coord);
	~Flag();
private:
	void setFlagedCell(const Coord& coord);
};