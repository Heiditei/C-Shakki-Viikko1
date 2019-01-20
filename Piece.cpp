#include "pch.h"
#include "Piece.h"

class Piece {

	enum
	{
		wK, wQ, wR, wB, wKn, wP,
		bK, bQ, bR, bB, bKn, bP,
	};
private:
	wstring unicode;		//  L"u1234" etc
	int color;				// white = 0, black = 1
	int _code;				// wK, bQ etc

	
	Piece(wstring uni, int col, int code)
	{
		unicode = uni;
		color = col;
		_code = code;
	}

	void setCode(int code)
	{
		_code = code;
	}

	int getCode()
	{
		return _code;
	}

	void setUnicode(wstring uni)
	{
		unicode = uni;
	}

	wstring getUnicode()
	{
		return unicode;
	}

	void setColor(int col)
	{
		color = col;
	}

	int getColor()
	{
		return color;
	}


	~Piece()
	{

	}
};