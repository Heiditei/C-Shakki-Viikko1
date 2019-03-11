#include "pch.h"
#include "Station.h"
#include "Piece.h"
#include <io.h>
#include <fcntl.h>
#include <string>
using namespace std;

Station::Station()
{


	Piece* wK = new Piece(L"\u2654", 0, 0);			//White King
	Piece* wQ = new Piece(L"\u2655", 0, 1);			//White Queen
	Piece* wR = new Piece(L"\u2656", 0, 2);			//White Rook
	Piece* wB = new Piece(L"\u2657", 0, 3);			//White Bishop
	Piece* wKn = new Piece(L"\u2658", 0, 4);		//White Knight
	Piece* wP = new Piece(L"\u2659", 0, 5);			//White Pawn

	Piece* bK = new Piece(L"\u265A", 1, 6);			//Black King
	Piece* bQ = new Piece(L"\u265B", 1, 7);			//Black Queen
	Piece* bR = new Piece(L"\u265C", 1, 8);			//Black Rook
	Piece* bB = new Piece(L"\u265D", 1, 9);			//Black Bishop
	Piece* bKn = new Piece(L"\u265E", 1, 10);		//Black Knight
	Piece* bP = new Piece(L"\u265F", 1, 11);		//Black Pawn

	for (size_t i = 0; i < 8; i++)
	{
		int row = i;
		for (size_t j = 0; j < 8; j++)
		{
			board[row][j] = NULL;
		}
	}

	board[0][0] = wR;
	board[0][1] = wKn;
	board[0][2] = wB;
	board[0][3] = wQ;
	board[0][4] = wK;
	board[0][5] = wB;
	board[0][6] = wKn;
	board[0][7] = wR;

	board[1][0] = wP;
	board[1][1] = wP;
	board[1][2] = wP;
	board[1][3] = wP;
	board[1][4] = wP;
	board[1][5] = wP;
	board[1][6] = wP;
	board[1][7] = wP;

	board[6][0] = bP;
	board[6][1] = bP;
	board[6][2] = bP;
	board[6][3] = bP;
	board[6][4] = bP;
	board[6][5] = bP;
	board[6][6] = bP;
	board[6][7] = bP;

	board[7][0] = bR;
	board[7][1] = bKn;
	board[7][2] = bB;
	board[7][3] = bQ;
	board[7][4] = bK;
	board[7][5] = bB;
	board[7][6] = bKn;
	board[7][7] = bR;

}

