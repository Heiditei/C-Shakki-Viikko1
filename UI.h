#pragma once
#include "Station.h"
#include "Piece.h"
#include "Move.h"
#include <iostream>
#include <string>

class UI
{
public:
	Station* station;
	UI(Station* station);
	void drawBoard();
	Move giveOpponentsMove();
};
