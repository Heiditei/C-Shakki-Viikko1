#pragma once
#include "pch.h"
#include <iostream>
#include "Piece.h"
#include "Move.h"


class Station
{
public:
	//Konstruktori luo alkuaseman laudalle
	Station();

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

	Piece* board[8][8];

	void updateStation(Move*);
	int getTurn();
	void setTurn(int);
	bool getIsWhiteKingMoved();
	bool getIsBlackKingMoved();
	bool getIsWhiteRightRookMoved();
	bool getIsWhiteLeftRookMoved();
	bool getIsBlackRightRookMoved();
	bool getIsBlackLeftRookMoved();


private:

	int turn;
	bool IsWhiteKingMoved;
	bool IsBlackKingMoved;
	bool IsWhiteRightRookMoved;
	bool IsWhiteLeftRookMoved;
	bool IsBlackRightRookMoved;
	bool IsBlackLeftRookMoved;
};