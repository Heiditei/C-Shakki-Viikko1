#include "pch.h"
#include "Square.h"
#include "Piece.h"
#include "Station.h"


Square::Square(int _row, int _column)
{
	row = _row;
	column = _column;
}

int Square::getRow()
{
	return row;
}

int Square::getColumn()
{
	return column;
}
