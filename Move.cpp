#include "pch.h"
#include "Move.h"
#include "Square.h"

Move::Move(Square start, Square end) {
	startSquare = start;
	endSquare = end;
	this->shortCastle = false;
	this->longCastle = false;
}

// Poikkeussiirto linnoittautumista varten
Move::Move(bool _short, bool _long)
{
	shortCastle = _short;
	longCastle = _long;
}


Square Move::getStartSquare()
{
	return startSquare;
}


Square Move::getEndSquare()
{
	return endSquare;
}


bool Move::isShortCastle()
{
	return shortCastle;
}


bool Move::isLongCastle()
{
	return longCastle;
}