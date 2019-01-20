#include "pch.h"
#include "Piece.h"

class Piece {
	Piece()
	{
	}
	enum
	{
		wK, wQ, wT, wB, wKn, wP,
		bK, bQ, bT, bB, bKn, bP,
	};
private:
	wstring unicode;		//  L"u1234" etc
	int color;				// white = 0, black = 1
	int _code;				// wK, bQ etc


	Piece(wstring, int, int)
	{

	}

	void setCode(int)
	{

	}

	int getCode()
	{

	}

	void setUnicode(wstring)
	{

	}

	wstring getUnicode()
	{

	}

	void setColor(int)
	{

	}

	int getColor()
	{

	}


	~Piece()
	{

	}
};