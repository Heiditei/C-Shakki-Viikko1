#pragma once
#include "Station.h"

class UI
{
public:
	UI(Station* station);
	Station* station;
	void drawBoard();
};

};