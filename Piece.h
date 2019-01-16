#pragma once
#include <string>
#include <iostream>

// Vakioarvot nappulatyypeille.
enum
{
	wK, wQ, wT, wB, wKn, wP,
	bK, bQ, bT, bB, bKn, bP,
};

class Piece {

private:
	std::wstring unicode;
	int color; // white = 0, black = 1
	int _code; // VT, VR, MT tms.

public:
	Piece(std::wstring, int, int);
	Piece() {};
	void setCode(int);
	int getCode();
	void setUnicode(std::wstring);
	std::wstring getUnicode();
	void setColor(int);
	int getColor();
};
