#include "pch.h"
#include "Station.h"
#include "Piece.h"


class Station
{
	Station()
	{
		//Instantiate pawns (unicode, color, code)
		//color, 0 = white, 1 = black

		Piece wK(L"\u2654", 0, 0);		//White King
		Piece wQ(L"\u2655", 0, 1);		//White Queen
		Piece wR(L"\u2656", 0, 2);		//White Rook
		Piece wB(L"\u2657", 0, 3);		//White Bishop
		Piece wKn(L"\u2658", 0, 4);		//White Knight
		Piece wP(L"\u2659", 0, 5);		//White Pawn


		Piece bK(L"\u265A", 1, 10);		//Black King
		Piece bQ(L"\u265B", 1, 11);		//Black Queen
		Piece bR(L"\u265C", 1, 12);		//Black Rook
		Piece bB(L"\u265D", 1, 13);		//Black Bishop
		Piece bKn(L"\u265E", 1, 14);	//Black Knight
		Piece bP(L"\u265F", 1, 15);		//Black Pawn

		
		Piece* board[8][8] =
		{ &wR, &wKn, &wB, &wQ, &wK, &wB, &wKn, &wR,
			&wP, &wP, &wP, &wP, &wP, &wP, &wP, &wP,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0,
			&bP, &bP, &bP, &bP, &bP, &bP, &bP, &bP,
			&bR, &bKn, &bB, &bQ, &bK, &bB, &bKn, &bR };
 	}
	~Station()
	{

	}
};