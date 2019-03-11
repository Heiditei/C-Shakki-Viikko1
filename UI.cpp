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
	for (int i = 0; i < 8; i++) {
		int row = i+1;

		SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN);
		wcout << row;
		if (i % 2 == 0)
		{
			for (int j = 0; j < 8; j++)
			{
				if (j % 2 == 0)
				{
					SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
					wcout << " ";
				}
				else
				{
					SetConsoleTextAttribute(handle, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
					wcout << " ";
				}

				if (station->board[i][j] == nullptr)
				{
					wcout << L"  ";
				}

				else
				{
					wcout << station->board[i][j]->getUnicode() << L" ";
				}
			}
		}
		else
		{
			for (int j = 0; j < 8; j++)
			{
				if (j % 2 == 0)
				{
					SetConsoleTextAttribute(handle, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
					wcout << " ";
				}
				else
				{
					SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
					wcout << " ";
				}
				if (station->board[i][j] == nullptr)
				{
					wcout << L"  ";
				}

				else
				{
					wcout << station->board[i][j]->getUnicode() << L" ";
				}
			}
		}
		wcout << endl;
	}

	SetConsoleTextAttribute(handle, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN);
	wcout << "  a  b  c  d  e  f  g  h " << endl << endl << endl;
}

Move UI::giveOpponentsMove()
{



}