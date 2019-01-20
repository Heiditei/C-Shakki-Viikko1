#ifndef UI
#define UI
#pragma once
#include "pch.h"
#include "Station.h"
#include "Piece.h"

class UI
{
public:
	UI(Station* station);
	Station* station;
	void drawBoard();
};

};
#endif