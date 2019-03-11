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
	Piece* whichRaised = 0;

private:
	
	Square startSquare;
	Square endSquare;
	bool shortCastle;
	bool longCastle;
};