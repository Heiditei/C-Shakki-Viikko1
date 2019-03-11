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

Piece::Piece(wstring uni, int col, int cd)
{
	unicode = uni;
	color = col;
	code = cd;
	
}

void Piece::setCode(int cd)
{
	code = cd;
}

int Piece::getCode()
{
	return code;
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