#pragma once
#include "ruutu.h"

// Ns. "forward declaration". Nyt Asema-luokassa voidaa esitell� Nappula-osoittimia ilman,
// ett� nappula.h -tiedostoa t�ytyy includoida.
class Nappula;


// Siirto kuvaa nappulan siirtymisen ruudusta toiseen, mukaanlukien erikoissiirrot
// (linnoitus ja ohestaly�nti).
class Siirto
{
public:
	Siirto(Ruutu, Ruutu);
	Siirto() {}
	Siirto(bool, bool); // Linnoitus lyhesti (K-siipi) tai pitk�sti (D-siipi?
	Ruutu getAlkuruutu();
	Ruutu getLoppuruutu();
	bool onkoLyhytLinna();
	bool onkoPitk�linna();
	bool operator== (const Siirto& rhs)
	{
		return _alkuRuutu == rhs._alkuRuutu && _loppuRuutu == rhs._loppuRuutu &&
			_lyhytLinna == rhs._lyhytLinna && _pitkaLinna == rhs._pitkaLinna;
	}

	Nappula* _miksikorotetaan = 0;

private:
	Ruutu _alkuRuutu;
	Ruutu _loppuRuutu;
	bool _lyhytLinna;
	bool _pitkaLinna;
};