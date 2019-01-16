#pragma once
#include <string>
#include <iostream>

// Vakioarvot nappulatyypeille.
enum
{
	WK, WQ, WT,WB, WKn, WP,
	BK, BQ, BT, BB, BKn, BP,
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
