#pragma once
#include "pch.h"
#include "Square.h"

class Piece;

class Move {
public:
	Move(Square, Square);
	Move() {}
	Move(bool, bool); // Poikkeussiirto linnoitusta varten
	Square getStartSquare();
	Square getEndSquare();
	bool isShortCastle();
	bool isLongCastle();


private:
	int whichRaised = 0;
	Square startSquare;
	Square endSquare;
	bool shortCastle;
	bool longCastle;
};