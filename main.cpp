#include <Windows.h>
#include <algorithm>
#include <iostream>
#include <list>
#include <io.h>
#include <fcntl.h>
#include <string>
#include "kayttoliittyma.h"
#include "asema.h"
#include "siirto.h"

using namespace std;

int main()
{

	Asema asema;
	Kayttoliittyma ui(&asema);
	while (1)
	{
		wcout << "Valitse puoli: M = musta, V= valkoinen" << endl;
		wstring puoli;
		wcin >> puoli;

		if (puoli == L"V" || puoli == L"v")
		{
			asema.setSiirtovuoro(0);
			break;
		}
		else if (puoli == L"M" || puoli == L"m")
		{
			asema.setSiirtovuoro(1);
			break;
		}
		else
		{
			wcout << "Syöte ei tunnistettu!" << endl;
		}
	}

	while (1)
	{
		// Piirretään lauta.
		ui.piirraLauta();

		// Generoidaan siirrot.
		std::list<Siirto> siirtolista;
		asema.annaLaillisetSiirrot(siirtolista);
		wcout << siirtolista.size() << " siirtoa:\n";

		MinMaxPaluu ai_valinta = asema.minimax(2);
		wcout << "Minimax-arvo: " << ai_valinta._evaluointiArvo << "\n";
		Siirto ai_siirto = ai_valinta._parasSiirto;
		char kirjaimet[] = { 'a','b','c','d','e','f','h','g' };
		Ruutu alkuruutu = ai_siirto.getAlkuruutu();
		Ruutu loppuruutu = ai_siirto.getLoppuruutu();
		int aSarake = alkuruutu.getSarake();
		int lSarake = loppuruutu.getSarake();
		wcout << "(" << kirjaimet[aSarake] << ", " << alkuruutu.getRivi()+1 << ") - ";
		wcout << "(" << kirjaimet[lSarake] << ", " << loppuruutu.getRivi()+1 << ")\n";

		// Kysytään pelaajan siirto (tarkistetaan että on siirtolistassa).
		Siirto s = ui.annaVastustajanSiirto();
		while (std::find(siirtolista.begin(), siirtolista.end(), s) == siirtolista.end())
		{
			s = ui.annaVastustajanSiirto();
		}

		// Päivitetään asema pelaajan siirrolla.
		asema.paivitaAsema(&s);
	}

	return 0;
}
