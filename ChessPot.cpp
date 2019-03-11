#include "pch.h"
#include "Piece.h"
#include "Station.h"
#include "UI.h"
#include "Move.h"
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>
using namespace std;


int main()

//kaikkeen wcout, wcin yms wc-alku
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	Station station;
	UI ui(&station);
	while (1)
	{
		ui.drawBoard();

		Move m = ui.giveOpponentsMove();

		station.updateStation(&m);
	}

	return 0;

}