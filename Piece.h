#pragma once
#include <string>
#include <iostream>
using namespace std;

// Standard values for pieces
enum
{
	wK, wQ, wT, wB, wKn, wP,
	bK, bQ, bT, bB, bKn, bP,
};

class Piece {

private:
	wstring unicode;		//  L"u1234" etc
	int color;				// white = 0, black = 1
	int _code;				// wK, bQ etc

public:
	Piece(wstring, int, int);
	Piece() {};
	void setCode(int);
	int getCode();
	void setUnicode(wstring);
	wstring getUnicode();
	void setColor(int);
	int getColor();
};