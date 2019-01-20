#include "pch.h"
#include "Piece.h"
#include "Station.h"
#include "UI.h"
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
	//UI ui(&station);
	//ui.drawBoard();

	for (int i = 8; i > 0; i--)
	{
		for (int j = 8; j > 0; j--) {
			wcout << station.board[i][j]->Piece::getUnicode();
		}
		wcout << endl;
	}
}

