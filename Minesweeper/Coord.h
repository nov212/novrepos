#pragma once
#pragma once

///////////////////////////////////////////////
// COORD
// 
// keeps row and col of cell
///////////////////////////////////////////////

class Coord
{
private:
	int x;
	int y;
public:
	Coord(int x = 0, int y = 0);
	Coord(const Coord& another);
	int getX() const;
	int getY() const;
	bool operator==(const Coord& another);
	bool operator!=(const Coord& another);
	Coord& operator=(const Coord& another);
};