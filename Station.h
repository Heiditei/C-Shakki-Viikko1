#ifndef STATION
#define STATION
#pragma once
#include "pch.h"
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
	Piece* wR;
	Piece* wB;
	Piece* wKn;
	Piece* wP;

	Piece* bK;
	Piece* bQ;
	Piece* bR;
	Piece* bB;
	Piece* bKn;
	Piece* bP;

}


};
#endif