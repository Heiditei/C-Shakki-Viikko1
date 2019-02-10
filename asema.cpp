#include <iostream>
#include "asema.h"
#include "nappula.h"

Nappula* Asema::vk = new Nappula(L"\u2654", 0, VK);
Nappula* Asema::vd = new Nappula(L"\u2655", 0, VD);
Nappula* Asema::vt = new Nappula(L"\u2656", 0, VT);
Nappula* Asema::vl = new Nappula(L"\u2657", 0, VL);
Nappula* Asema::vr = new Nappula(L"\u2658", 0, VR);
Nappula* Asema::vs = new Nappula(L"\u2659", 0, VS);

Nappula* Asema::mk = new Nappula(L"\u265A", 1, MK);
Nappula* Asema::md = new Nappula(L"\u265B", 1, MD);
Nappula* Asema::mt = new Nappula(L"\u265C", 1, MT);
Nappula* Asema::ml = new Nappula(L"\u265D", 1, ML);
Nappula* Asema::mr = new Nappula(L"\u265E", 1, MR);
Nappula* Asema::ms = new Nappula(L"\u265F", 1, MS);


Asema::Asema()
{
	// Ensin alustetaan kaikki laudan ruudut nappulla "NULL", koska muuten ruuduissa satunnaista tauhkaa
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			_lauta[i][j] = NULL;
	// Asetetaan alkuaseman mukaisesti nappulat ruuduille
	_lauta[0][0] = vt;
	_lauta[1][0] = vr;
	_lauta[2][0] = vl;
	_lauta[3][0] = vd;
	_lauta[4][0] = vk;
	_lauta[5][0] = vl;
	_lauta[6][0] = vr;
	_lauta[7][0] = vt;

	_lauta[0][1] = vs;
	_lauta[1][1] = vs;
	_lauta[2][1] = vs;
	_lauta[3][1] = vs;
	_lauta[4][1] = vs;
	_lauta[5][1] = vs;
	_lauta[6][1] = vs;
	_lauta[7][1] = vs;

	_lauta[0][7] = mt;
	_lauta[1][7] = mr;
	_lauta[2][7] = ml;
	_lauta[3][7] = md;
	_lauta[4][7] = mk;
	_lauta[5][7] = ml;
	_lauta[6][7] = mr;
	_lauta[7][7] = mt;

	_lauta[0][6] = ms;
	_lauta[1][6] = ms;
	_lauta[2][6] = ms;
	_lauta[3][6] = ms;
	_lauta[4][6] = ms;
	_lauta[5][6] = ms;
	_lauta[6][6] = ms;
	_lauta[7][6] = ms;
	// Kunkun testausta varten
	/*_lauta[7][5] = vk;
	_lauta[5][5] = mt;
	_lauta[4][3] = ml;
	_lauta[3][3] = vs;*/

	//_lauta[4][4] = vr;

	_siirtovuoro = 0;
	_onkoValkeaKuningasLiikkunut = false;
	_onkoMustaKuningasLiikkunut = false;
	_onkoValkeaDTliikkunut = false;
	_onkoValkeaKTliikkunut = false;
	_onkoMustaDTliikkunut = false;
	_onkoMustaKTliikkunut = false;

}


void Asema::paivitaAsema(Siirto *siirto)
{
	//Tarkastetaan on siirto lyhyt linna
	if (siirto->onkoLyhytLinna()) {
		if (_siirtovuoro == 0) {
			_lauta[4][0] = NULL; // kuninkaan paikalle tyhjä
			_lauta[6][0] = vk; // kuningas uudelle paikalle
			_lauta[7][0] = NULL; // tornin paikalle tyhjä
			_lauta[5][0] = vt; // torni uudella paikalle
		}
		if (_siirtovuoro == 1) {
			_lauta[4][7] = NULL; // kuninkaan paikalle tyhjä
			_lauta[6][7] = mk; // kuningas uudelle paikalle
			_lauta[7][7] = NULL; // tornin paikalle tyhjä
			_lauta[5][7] = mt; // torni uudella paikalle
		}
	}

	// onko pitkä linna
	else if (siirto->onkoPitkälinna()) {
		if (_siirtovuoro == 0) {
			_lauta[4][0] = NULL; // kuninkaan paikalle tyhjä
			_lauta[2][0] = vk; // kuningas uudelle paikalle
			_lauta[0][0] = NULL; // tornin paikalle tyhjä
			_lauta[3][0] = vt; // torni uudella paikalle
		}
		if (_siirtovuoro == 1) {
			_lauta[4][7] = NULL; // kuninkaan paikalle tyhjä
			_lauta[2][7] = mk; // kuningas uudelle paikalle
			_lauta[0][7] = NULL; // tornin paikalle tyhjä
			_lauta[3][7] = mt; // torni uudella paikalle
		}

	}
	else {// Kaikki muut siirrot

		int alkuRiviInt;
		int alkuSarakeInt;
		int loppuRiviInt;
		int loppuSarakeInt;

		//Ottaa siirron alkuruudussa olleen nappulan talteen 
		alkuRiviInt = siirto->getAlkuruutu().getRivi();
		alkuSarakeInt = siirto->getAlkuruutu().getSarake();
		Nappula* nappula = _lauta[alkuSarakeInt][alkuRiviInt];

		//Laittaa talteen otetun nappulan uuteen ruutuun
		loppuRiviInt = siirto->getLoppuruutu().getRivi();
		loppuSarakeInt = siirto->getLoppuruutu().getSarake();

		//// Katsotaan jos nappula on sotilas ja rivi on päätyrivi niin ei vaihdeta nappulaa 
		////eli alkuruutuun laitetaan null ja loppuruudussa on jo kliittymän laittama nappula MIIKKA, ei taida minmaxin kanssa hehkua?
		//if ((nappula->getKoodi() == VS || nappula->getKoodi() == MS) && (loppuRiviInt == 0 || loppuRiviInt == 7)) {
		//	_lauta[alkuSarakeInt][alkuRiviInt] = NULL;
		//}
		////muissa tapauksissa alkuruutuun null ja loppuruutuun sama alkuruudusta lähtenyt nappula
		//else {
		_lauta[alkuSarakeInt][alkuRiviInt] = NULL;
		_lauta[loppuSarakeInt][loppuRiviInt] = nappula;

		if (siirto->_miksikorotetaan != NULL)
			_lauta[loppuSarakeInt][loppuRiviInt] = siirto->_miksikorotetaan;
		//		}
		// katsotaan jos liikkunut nappula on kuningas niin muutetaan onkoKuningasLiikkunut arvo (molemmille väreille)
		if (nappula->getKoodi() == VK) {
			_onkoValkeaKuningasLiikkunut = true;
		}
		if (nappula->getKoodi() == MK) {
			_onkoMustaKuningasLiikkunut = true;
		}
		// katsotaan jos liikkunut nappula on torni niin muutetaan onkoTorniLiikkunut arvo (molemmille väreille ja molemmille torneille)
		if (nappula->getKoodi() == VT && alkuSarakeInt == 7 && alkuRiviInt == 0) {
			_onkoValkeaKTliikkunut = true;
		}
		if (nappula->getKoodi() == VT && alkuSarakeInt == 0 && alkuRiviInt == 0) {
			_onkoValkeaDTliikkunut = true;
		}
		if (nappula->getKoodi() == MT && alkuSarakeInt == 7 && alkuRiviInt == 7) {
			_onkoMustaKTliikkunut = true;
		}
		if (nappula->getKoodi() == VT && alkuSarakeInt == 0 && alkuRiviInt == 7) {
			_onkoMustaDTliikkunut = true;
		}
	}
	//päivitetään _siirtovuoro
	if (_siirtovuoro == 0)
		_siirtovuoro = 1;
	else
		_siirtovuoro = 0;
}


int Asema::getSiirtovuoro()
{
	return this->_siirtovuoro;
}


void Asema::setSiirtovuoro(int vuoro)
{
	this->_siirtovuoro = vuoro;
}


bool Asema::getOnkoValkeaKuningasLiikkunut()
{
	return this->_onkoValkeaKuningasLiikkunut;
}


bool Asema::getOnkoMustaKuningasLiikkunut()
{
	return this->_onkoMustaKuningasLiikkunut;
}


bool Asema::getOnkoValkeaDTliikkunut()
{
	return this->_onkoValkeaDTliikkunut;
}


bool Asema::getOnkoValkeaKTliikkunut()
{
	return this->_onkoValkeaKTliikkunut;
}


bool Asema::getOnkoMustaDTliikkunut()
{
	return this->_onkoMustaDTliikkunut;
}


bool Asema::getOnkoMustaKTliikkunut()
{
	return this->_onkoMustaKTliikkunut;
}
