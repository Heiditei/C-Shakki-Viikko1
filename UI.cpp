#define WHITE_SQUARE 0xDB
#define BLACK_SQUARE 0xFF

#include "pch.h"
#include "UI.h"
#include "Station.h"
#include "Piece.h"


class UI{

	Station* station;

	UI(Station* station)
	{

	}

	void drawBoard()
	{
		for (int i=0; i < 8; i++) {
			if (iLine % 2 == 0)
			{				
				// Line starting with WHITE
				printLine(iLine, WHITE_SQUARE, BLACK_SQUARE, game);
			}

			else
			{
				// Line starting with BLACK
				printLine(iLine, BLACK_SQUARE, WHITE_SQUARE);
			}
		}
		/*SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_RED |
			BACKGROUND_GREEN | BACKGROUND_BLUE);

		_setmode(_fileno(stdout), _O_U16TEXT);*/
	}
	
	~UI()
	{

	}
};

