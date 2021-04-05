#include "Matrix.h"
#include "Ranges.h"

Matrix::Matrix(Cell defaultCell)
{
	const int rows = Ranges::getSize().getY();
	const int cols = Ranges::getSize().getX();
	matrix = new Cell*[rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new Cell[cols];
		for (int j = 0; j < cols; j++)
			matrix[i][j] = defaultCell;
	}
}

Cell Matrix::getCell(const Coord& coord)
{
	if (Ranges::inRange(coord))
		return matrix[coord.getX()][coord.getY()];
}

void Matrix::setCell(const Coord& coord, Cell status)
{
	if (Ranges::inRange(coord))
		matrix[coord.getX()][coord.getY()] = status;
}

Matrix::~Matrix()
{
	for (int i = 0; i < Ranges::getSize().getY(); i++)
		delete[] matrix[i];
	delete[] matrix;
}