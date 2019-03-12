#pragma once


// Shakkilaudan ruutu tietyssä (rivi, sarake) -koordinaatissa.
class Ruutu {
public:
	Ruutu(int, int);
	Ruutu() {}
	int getRivi();
	int getSarake();
	void setRivi(int);
	void setSarake(int);
	bool operator== (const Ruutu& rhs)
	{
		return _sarake == rhs._sarake && _rivi == rhs._rivi;
	}

private:
	int _sarake;
	int _rivi;
};
