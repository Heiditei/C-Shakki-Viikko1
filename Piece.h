#pragma once
#include <string>
#include <iostream>

// Vakioarvot nappulatyypeille.
enum
{
	VT, VR, VL, VD, VK, VS,
	MT, MR, ML, MD, MK, MS
};

class Pawn {

private:
	std::wstring unicode;
	int color; // white = 0, black = 1
	int _code; // VT, VR, MT tms.

public:
	Pawn(std::wstring, int, int);
	Pawn() {};
	void setCode(int);
	int getCode();
	void setUnicode(std::wstring);
	std::wstring getUnicode();
	void setColor(int);
	int getColor();
};
