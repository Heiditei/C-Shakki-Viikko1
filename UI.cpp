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
	int startX;
	int startY;
	int endX;
	int endY;
	wstring moveString;
	wstring movedPieceString;

	do
	{
		wcout << "Give your move (eg. Kng1-f3, castle 0-0 tai 0-0-0)\n";
		wcin >> moveString;

		if (moveString == L"0-0" || moveString == L"0-0-0")
		{
			if (moveString == L"0-0") {
				return Move(true, false);
			}
			if (moveString == L"0-0-0")
			{
				return Move(false, true);
			}
		}
		else if (moveString.length() == 6)
		{
			movedPieceString = moveString[0];
			moveString.erase(0, 1);
		}
	
		else {
			movedPieceString = L"s";
		}

		startX = moveString[1] - '1';
		startY = moveString[0] - 'a';
		endX = moveString[4] - '1';
		endY = moveString[3] - 'a';

		if (((startX < 0 || startX > 7) || (startY < 0 || startY > 7)) || ((endX < 0 || endX >7) || (endY < 0 || endY > 7)))
			wcout << "Move must be in form eg. Bc1-a3,\n alphabets between a-h\n numbers between 1-8,\n Pieces are King(K,k), Queen(Q,q), Biship(B,b), Knight(Kn,kn), Rook(R,r)\n Pawn is left unmarked\n";
	} while (((startX < 0 || startX >7) || (startY < 0 || startY > 7)) || ((endX < 0 || endX >7) || (endY < 0 || endY > 7)));

	Square startSquare(startX, startY);
	Square endSquare(endX, endY);
	Move move(startSquare, endSquare);

	//katsotaan onko kyseessä sotilaan korotus
	std::wstring RaisedPiece;

	if (movedPieceString == L"s" && (endY == 0 || endY == 7)) {
		std::wcout << "To which piece do you wish to raise? (eg. Q)\n";
		std::wcin >> RaisedPiece;
		if (endY == 7) {
			if (RaisedPiece == L"D" || RaisedPiece == L"d") {
				move.whichRaised = station->wQ;
			}
			if (RaisedPiece == L"T" || RaisedPiece == L"t") {
				move.whichRaised = station->wR;
			}
			if (RaisedPiece == L"R" || RaisedPiece == L"r") {
				move.whichRaised = station->wKn;
			}
			if (RaisedPiece == L"L" || RaisedPiece == L"l") {
				move.whichRaised = station->wB;
			}
		}

		if (endY == 0) {
			if (RaisedPiece == L"D" || RaisedPiece == L"d") {
				move.whichRaised = station->bQ;
			}
			if (RaisedPiece == L"T" || RaisedPiece == L"t") {
				move.whichRaised = station->bR;
			}
			if (RaisedPiece == L"R" || RaisedPiece == L"r") {
				move.whichRaised = station->bKn;
			}
			if (RaisedPiece == L"L" || RaisedPiece == L"l") {
				move.whichRaised = station->bB;
			}
		}
	}

	return move;


}