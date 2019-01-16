#pragma once
#include <iostream>
#include "Piece.h"


class Station
{
public:
	//Konstruktori luo alkuaseman laudalle
	Station();
	Piece* board[8][8];

	Piece* wK;
	Piece* wQ;
	Piece* wT;
	Piece* wB;
	Piece* wKn;
	Piece* wP;

	Piece* bK;
	Piece* bQ;
	Piece* bT;
	Piece* bB;
	Piece* bKn;
	Piece* bP;

}


};
