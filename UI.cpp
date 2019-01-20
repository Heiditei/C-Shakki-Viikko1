#include "pch.h"
#include "UI.h"
#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include "Station.h"
#include "Piece.h"
#include <Windows.h>


/*
	BlackFore = 0,
	GrayFore = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
	WhiteFore = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,

	BlackBack = 0,
	GrayBack = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
	WhiteBack = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
*/
using namespace std;

UI::UI(Station* stion)
{
	station = stion;
	//haistakaavittu.kokosakki.suorita();
}

void UI::drawBoard()
{
	const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY);
	cout << " A  B  C  D  E  F  G  H  " << endl;
	for (int i = 0; i < 8; i++) {
		SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY);
		cout << i + 1;
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0) {
				//White Background
				SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
				cout << "   ";
			}
			else if ((i + j) % 2 != 0)
			{
				//Gray Background
				SetConsoleTextAttribute(handle, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
				cout << "   ";
			}
			else {
				cout << "pim";
			}
		}
		cout << endl;
	}

}

