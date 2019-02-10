#pragma once

#include <list>
#include <string>
#include "asema.h"


// Vakioarvot nappulatyypeille.
enum
{
	VT, VR, VL, VD, VK, VS,
	MT, MR, ML, MD, MK, MS
};


// Yliluokka shakkinappuloille.
class Nappula
{

private:
	std::wstring	_unicode;	// nappulaa vastaava unicode-merkki
	int				_vari;		// valkea = 0, musta = 1
	int				_koodi;		// VT, VR, MT tms.

public:
	Nappula(std::wstring, int, int);
	Nappula() {}

	// virtual jotta my�h�inen sidonta k�yt�ss�
	virtual void annaSiirrot(
		std::list<Siirto>& lista,
		Ruutu* ruutu,
		Asema* asema,
		int vari
	) = 0;

	void setUnicode(std::wstring unicode) { _unicode = unicode; }
	std::wstring getUnicode() { return _unicode; }
	void setVari(int vari) { _vari = vari; }
	int getVari() { return _vari; }
	int getKoodi() { return _koodi; }
	void setKoodi(int koodi) { _koodi = koodi; }
};


class Torni : virtual public Nappula
{
	virtual void annaSiirrot(
		std::list<Siirto>& lista,
		Ruutu* ruutu,
		Asema* asema,
		int vari
	)
	{
		// Nykyiset koordinaatit
		int x = ruutu->getSarake();
		int y = ruutu->getRivi();

		// "oikealle" (dx = "delta x", eli x:n muutos)
		for (int dx = 1; dx <= 7; dx++)
		{
			// uudet koordinatit
			int new_x = x + dx;

			// menn��nk� yli laudan reunasta?
			if (new_x > 7)
				break;

			// mit� tutkittavassa ruudussa (new_x, y) on?
			Nappula* n = asema->_lauta[new_x][y];

			// onko tyhj� ruutu?
			if (n == nullptr)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, y)));
				continue;
			}

			// onko vastustajan nappula?
			if (n->getVari() != vari)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, y)));
			}

			break;
		}

		// "vasemmalle" (dx = "delta x", eli x:n muutos)
		for (int dx = 1; dx <= 7; dx++)
		{
			// uudet koordinatit
			int new_x = x - dx;

			// menn��nk� yli laudan reunasta?
			if (new_x < 0)
				break;

			// mit� tutkittavassa ruudussa (new_x, y) on?
			Nappula* n = asema->_lauta[new_x][y];

			// onko tyhj� ruutu?
			if (n == nullptr)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, y)));
				continue;
			}

			// onko vastustajan nappula?
			if (n->getVari() != vari)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, y)));
			}

			break;
		}

		// "yl�s" (dy = "delta y", eli y:n muutos)
		for (int dy = 1; dy <= 7; dy++)
		{
			// uudet koordinatit
			int new_y = y + dy;

			// menn��nk� yli laudan reunasta?
			if (new_y > 7)
				break;

			// mit� tutkittavassa ruudussa (new_x, y) on?
			Nappula* n = asema->_lauta[x][new_y];

			// onko tyhj� ruutu?
			if (n == nullptr)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, new_y)));
				continue;
			}

			// onko vastustajan nappula?
			if (n->getVari() != vari)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, new_y)));
			}

			break;
		}

		// "alas" (dy = "delta y", eli y:n muutos)
		for (int dy = 1; dy <= 7; dy++)
		{
			// uudet koordinatit
			int new_y = y - dy;

			// menn��nk� yli laudan reunasta?
			if (new_y < 0)
				break;

			// mit� tutkittavassa ruudussa (new_x, y) on?
			Nappula* n = asema->_lauta[x][new_y];

			// onko tyhj� ruutu?
			if (n == nullptr)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, new_y)));
				continue;
			}

			// onko vastustajan nappula?
			if (n->getVari() != vari)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, new_y)));
			}

			break;
		}

	}
};


class Ratsu : virtual public Nappula 
{
	virtual void annaSiirrot(
		std::list<Siirto>& lista,
		Ruutu* ruutu,
		Asema* asema,
		int vari
	)
	{
		// Nykyiset koordinaatit
		int x = ruutu->getSarake();
		int y = ruutu->getRivi();

		//Mysteeri
	}
};

class Lahetti : virtual public Nappula
{
	virtual void annaSiirrot(
		std::list<Siirto>& lista,
		Ruutu* ruutu,
		Asema* asema,
		int vari
	)
	{
		// Nykyiset koordinaatit
		int x = ruutu->getSarake();
		int y = ruutu->getRivi();

		// "oikealle yl�s" (i = muutos)
		for (int i = 1; i <= 7; i++)
		{
			// uudet koordinatit
			int new_x = x + i;
			int new_y = y + i;

			// menn��nk� yli laudan reunasta?
			if (new_x > 7 || new_y > 7) 
			{
				break;
			}

			// mit� tutkittavassa ruudussa (new_x, new_y) on?
			Nappula* n = asema->_lauta[new_x][new_y];

			// onko tyhj� ruutu?
			if (n == nullptr)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
				continue;
			}

			// onko vastustajan nappula?
			if (n->getVari() != vari)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
			}

			break;
		}

		// "oikealle alas" (i = muutos)
		for (int i = 1; i <= 7; i++)
		{
			// uudet koordinatit
			int new_x = x + i;
			int new_y = y - i;

			// menn��nk� yli laudan reunasta?
			if (new_x > 7 || new_y < 0)
			{
				break;
			}

			// mit� tutkittavassa ruudussa (new_x, new_y) on?
			Nappula* n = asema->_lauta[new_x][new_y];

			// onko tyhj� ruutu?
			if (n == nullptr)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
				continue;
			}

			// onko vastustajan nappula?
			if (n->getVari() != vari)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
			}

			break;
		}

		// "vasemmalle alas" (i = muutos)
		for (int i = 1; i <= 7; i++)
		{
			// uudet koordinatit
			int new_x = x - i;
			int new_y = y - i;

			// menn��nk� yli laudan reunasta?
			if (new_x < 0 || new_y < 0)
			{
				break;
			}

			// mit� tutkittavassa ruudussa (new_x, new_y) on?
			Nappula* n = asema->_lauta[new_x][new_y];

			// onko tyhj� ruutu?
			if (n == nullptr)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
				continue;
			}

			// onko vastustajan nappula?
			if (n->getVari() != vari)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
			}

			break;
		}

		// "vasemmalle yl�s" (i = muutos)
		for (int i = 1; i <= 7; i++)
		{
			// uudet koordinatit
			int new_x = x - i;
			int new_y = y + i;

			// menn��nk� yli laudan reunasta?
			if (new_x < 0 || new_y > 7)
			{
				break;
			}

			// mit� tutkittavassa ruudussa (new_x, new_y) on?
			Nappula* n = asema->_lauta[new_x][new_y];

			// onko tyhj� ruutu?
			if (n == nullptr)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
				continue;
			}

			// onko vastustajan nappula?
			if (n->getVari() != vari)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, new_y)));
			}

			break;
		}

	}
};

class Daami : virtual public Torni, virtual public Lahetti
{
};

class Kuningas : virtual public Nappula
{
	virtual void annaSiirrot(
		std::list<Siirto>& lista,
		Ruutu* ruutu,
		Asema* asema,
		int vari
	)
	{
		// Nykyiset koordinaatit
		int x = ruutu->getSarake();
		int y = ruutu->getRivi();

		// "oikealle" (dx = "delta x", eli x:n muutos)
		for (int dx = 1; dx <= 2; dx++)
		{
			// uudet koordinatit
			int new_x = x + dx;

			// menn��nk� yli laudan reunasta?
			if (new_x > 7)
				break;

			// mit� tutkittavassa ruudussa (new_x, y) on?
			Nappula* n = asema->_lauta[new_x][y];

			// onko tyhj� ruutu?
			if (n == nullptr)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, y)));
				continue;
			}

			// onko vastustajan nappula?
			if (n->getVari() != vari)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, y)));
			}

			break;
		}

		// "vasemmalle" (dx = "delta x", eli x:n muutos)
		for (int dx = 1; dx <= 2; dx++)
		{
			// uudet koordinatit
			int new_x = x - dx;

			// menn��nk� yli laudan reunasta?
			if (new_x < 0)
				break;

			// mit� tutkittavassa ruudussa (new_x, y) on?
			Nappula* n = asema->_lauta[new_x][y];

			// onko tyhj� ruutu?
			if (n == nullptr)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, y)));
				continue;
			}

			// onko vastustajan nappula?
			if (n->getVari() != vari)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(new_x, y)));
			}

			break;
		}

		// "yl�s" (dy = "delta y", eli y:n muutos)
		for (int dy = 1; dy <= 2; dy++)
		{
			// uudet koordinatit
			int new_y = y + dy;

			// menn��nk� yli laudan reunasta?
			if (new_y > 7)
				break;

			// mit� tutkittavassa ruudussa (new_x, y) on?
			Nappula* n = asema->_lauta[x][new_y];

			// onko tyhj� ruutu?
			if (n == nullptr)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, new_y)));
				continue;
			}

			// onko vastustajan nappula?
			if (n->getVari() != vari)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, new_y)));
			}

			break;
		}

		// "alas" (dy = "delta y", eli y:n muutos)
		for (int dy = 1; dy <= 2; dy++)
		{
			// uudet koordinatit
			int new_y = y - dy;

			// menn��nk� yli laudan reunasta?
			if (new_y < 0)
				break;

			// mit� tutkittavassa ruudussa (new_x, y) on?
			Nappula* n = asema->_lauta[x][new_y];

			// onko tyhj� ruutu?
			if (n == nullptr)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, new_y)));
				continue;
			}

			// onko vastustajan nappula?
			if (n->getVari() != vari)
			{
				lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, new_y)));
			}

			break;
		}

	}
};


class Sotilas : virtual public Nappula
{
	int max = 1;

	virtual void annaSiirrot(
		std::list<Siirto>& lista,
		Ruutu* ruutu,
		Asema* asema,
		int vari
	)
	{
		// Nykyiset koordinaatit
		int x = ruutu->getSarake();
		int y = ruutu->getRivi();


		//Jos valkoinen
		if (vari == 0) 
		{
			//Katsotaan onko aloitussijainnissa, eli voiko sittenkin liikkua ylim��r�isen askeleen
			if (y == 1) 
			{
				max = 2;
			}

			// "yl�s" (dy = "delta y", eli y:n muutos)
			for (int dy = 1; dy <= max; dy++)
			{
				// uudet koordinatit
				int new_y = y + dy;

				// menn��nk� yli laudan reunasta?
				if (new_y > 7)
					break;

				if (new_y == 7)
				{
					//Korotus!
				}

				// mit� tutkittavassa ruudussa (x, new_y) on?
				Nappula* n = asema->_lauta[x][new_y];

				// onko tyhj� ruutu?
				if (n == nullptr)
				{
					lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, new_y)));
					continue;
				}
				
				break;
			}
		}

		//Jos musta
		if (vari == 1) 
		{
			//Katsotaan onko aloitussijainnissa, eli voiko sittenkin liikkua ylim��r�isen askeleen
			if (y == 6)
			{
				max = 2;
			}

			// "alas" (dy = "delta y", eli y:n muutos)
			for (int dy = 1; dy <= max; dy++)
			{
				// uudet koordinatit
				int new_y = y - dy;

				// menn��nk� yli laudan reunasta?
				if (new_y < 0)
					break;

				if (new_y == 0)
				{
					//Korotus!
				}

				// mit� tutkittavassa ruudussa (x, new_y) on?
				Nappula* n = asema->_lauta[x][new_y];

				// onko tyhj� ruutu?
				if (n == nullptr)
				{
					lista.push_back(Siirto(Ruutu(x, y), Ruutu(x, new_y)));
					continue;
				}
				break;
			}
		}

	}
};

