#include "pch.h"
#ifndef _UI
#define _UI
#pragma once
#include "Station.h"
#include "Piece.h"
#include <iostream>
#include <string>

class UI
{
public:
	Station* station;
	UI(Station* station);
	void drawBoard();
};
#endif