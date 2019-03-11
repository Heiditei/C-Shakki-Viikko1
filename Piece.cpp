#include "pch.h"
#include <iostream>
#include <string>
#include "Piece.h"
#include <io.h>
#include <fcntl.h>
using namespace std;

//	wstring unicode;		//  L"u1234" etc
//	int color;				// white = 0, black = 1
//	int _code;				// wK, bQ etc

Piece::Piece(wstring uni, int col, int code)
{
	unicode = uni;
	color = col;
	_code = code;
	
}

void Piece::setCode(int code)
{
	_code = code;
}

int Piece::getCode()
{
	return _code;
}

void Piece::setUnicode(wstring uni)
{
	unicode = uni;
}

wstring Piece::getUnicode()
{
	return unicode;
}

void Piece::setColor(int col)
{
	color = col;
}

int Piece::getColor()
{
	return color;
}