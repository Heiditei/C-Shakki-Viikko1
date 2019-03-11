#pragma once
class Square {
public:
	Square(int row, int column);
	Square() {}
	int getRow();
	int getColumn();

private:
	int column;
	int row;
};

