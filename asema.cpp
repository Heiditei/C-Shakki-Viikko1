#include <iostream>
#include "asema.h"
#include "nappula.h"
#include "ruutu.h"

Nappula* Asema::vk = new Kuningas(L"\u2654", 0, VK);
Nappula* Asema::vd = new Daami(L"\u2655", 0, VD);
Nappula* Asema::vt = new Torni(L"\u2656", 0, VT);
Nappula* Asema::vl = new Lahetti(L"\u2657", 0, VL);
Nappula* Asema::vr = new Ratsu(L"\u2658", 0, VR);
Nappula* Asema::vs = new Sotilas(L"\u2659", 0, VS);

Nappula* Asema::mk = new Kuningas(L"\u265A", 1, MK);
Nappula* Asema::md = new Daami(L"\u265B", 1, MD);
Nappula* Asema::mt = new Torni(L"\u265C", 1, MT);
Nappula* Asema::ml = new Lahetti(L"\u265D", 1, ML);
Nappula* Asema::mr = new Ratsu(L"\u265E", 1, MR);
Nappula* Asema::ms = new Sotilas(L"\u265F", 1, MS);


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

	// Kaksoisaskel-lippu on oletusarvoisesti pois p‰‰lt‰.
	// Asetetaan myˆhemmin, jos tarvii.
	this->kaksoisaskelSarakkeella = -1;

	//Tarkastetaan on siirto lyhyt linna
	if (siirto->onkoLyhytLinna()) {
		if (_siirtovuoro == 0) {
			_lauta[4][0] = NULL; // kuninkaan paikalle tyhj‰
			_lauta[6][0] = vk; // kuningas uudelle paikalle
			_lauta[7][0] = NULL; // tornin paikalle tyhj‰
			_lauta[5][0] = vt; // torni uudella paikalle
		}
		if (_siirtovuoro == 1) {
			_lauta[4][7] = NULL; // kuninkaan paikalle tyhj‰
			_lauta[6][7] = mk; // kuningas uudelle paikalle
			_lauta[7][7] = NULL; // tornin paikalle tyhj‰
			_lauta[5][7] = mt; // torni uudella paikalle
		}
	}

	// onko pitk‰ linna
	else if (siirto->onkoPitk‰linna()) {
		if (_siirtovuoro == 0) {
			_lauta[4][0] = NULL; // kuninkaan paikalle tyhj‰
			_lauta[2][0] = vk; // kuningas uudelle paikalle
			_lauta[0][0] = NULL; // tornin paikalle tyhj‰
			_lauta[3][0] = vt; // torni uudella paikalle
		}
		if (_siirtovuoro == 1) {
			_lauta[4][7] = NULL; // kuninkaan paikalle tyhj‰
			_lauta[2][7] = mk; // kuningas uudelle paikalle
			_lauta[0][7] = NULL; // tornin paikalle tyhj‰
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

		// Tarkistetaan oliko sotilaan kaksoisaskel
		// (asetetaan kaksoisaskel-lippu)
		if
		(
			(_lauta[alkuSarakeInt][alkuRiviInt]->getKoodi() == VS || _lauta[alkuSarakeInt][alkuRiviInt]->getKoodi() == MS) &&
			(alkuRiviInt - loppuRiviInt == 2 || alkuRiviInt - loppuRiviInt == -2)
		)
			kaksoisaskelSarakkeella = alkuSarakeInt;

		// Ohestalyˆnti on tyhj‰‰n ruutuun. Vieress‰ oleva (sotilas) poistetaan.
		if
		(
			(_lauta[alkuSarakeInt][alkuRiviInt]->getKoodi() == VS || _lauta[alkuSarakeInt][alkuRiviInt]->getKoodi() == MS) &&
			(alkuSarakeInt != loppuSarakeInt) &&
			(_lauta[loppuSarakeInt][loppuRiviInt] == NULL)
		)
			_lauta[loppuSarakeInt][alkuRiviInt] = NULL;

		//// Katsotaan jos nappula on sotilas ja rivi on p‰‰tyrivi niin ei vaihdeta nappulaa 
		////eli alkuruutuun laitetaan null ja loppuruudussa on jo kliittym‰n laittama nappula MIIKKA, ei taida minmaxin kanssa hehkua?
		//if ((nappula->getKoodi() == VS || nappula->getKoodi() == MS) && (loppuRiviInt == 0 || loppuRiviInt == 7)) {
		//	_lauta[alkuSarakeInt][alkuRiviInt] = NULL;
		//}
		////muissa tapauksissa alkuruutuun null ja loppuruutuun sama alkuruudusta l‰htenyt nappula
		//else {
		_lauta[alkuSarakeInt][alkuRiviInt] = NULL;
		_lauta[loppuSarakeInt][loppuRiviInt] = nappula;
		if (siirto->_miksikorotetaan != NULL)
			_lauta[loppuSarakeInt][loppuRiviInt] = siirto->_miksikorotetaan;
//		}
		// katsotaan jos liikkunut nappula on kuningas niin muutetaan onkoKuningasLiikkunut arvo (molemmille v‰reille)
		if (nappula->getKoodi() == VK) {
			_onkoValkeaKuningasLiikkunut = true;
		}
		if (nappula->getKoodi() == MK) {
			_onkoMustaKuningasLiikkunut = true;
		}
		// katsotaan jos liikkunut nappula on torni niin muutetaan onkoTorniLiikkunut arvo (molemmille v‰reille ja molemmille torneille)
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
	//p‰ivitet‰‰n _siirtovuoro
	if (_siirtovuoro == 0)
		_siirtovuoro = 1;
	else
		_siirtovuoro = 0;
}
/*Nappula Asema::annaNappulaRuudusta(Ruutu *ruutu){
	int sarake = ruutu->getSarake();
	int rivi = ruutu->getRivi();
	return *_lauta[rivi][sarake];
}*/


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


bool Asema::onkoRuutuUhattu(Ruutu* ruutu, int vastustajanVari)
{
	std::list<Siirto> vastustajaSiirrotLista;
	//V‰reitt‰in k‰yd‰‰n l‰pi kaikki ruudut ja niiss‰ olevan nappulan siirrot ker‰t‰‰n vastustajan siirtolistaan
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (this->_lauta[i][j] == NULL) {
				continue;
			}
			if (this->_lauta[i][j]->getVari() == vastustajanVari)
				this->_lauta[i][j]->annaSiirrot(vastustajaSiirrotLista, &Ruutu(i, j), this, vastustajanVari); // myˆh.sidonta
		}
	}
	// K‰yd‰‰n vastustajaSiirtoLista l‰pi ja jos sielt‰ lˆytyy tarkasteltava ruutu niin tiedet‰‰n sen olevan uhattu
	bool ruutuOk = true;
	for (auto s : vastustajaSiirrotLista)
	{
		if (ruutu->getSarake() == s.getLoppuruutu().getSarake() && ruutu->getRivi() == s.getLoppuruutu().getRivi()) {
			ruutuOk = false;
			break;
		}
	}
	return ruutuOk;
}


void Asema::huolehdiKuninkaanShakeista(std::list<Siirto>& lista, int vari) 
{ 
	// poistaa listasta siirrot jotka viev‰t oman kuninkaan shakkiin
	// k‰yd‰‰n saatua siirtolistaa l‰pi ja jos siell‰ oleva siirto asettaa kuninkaan shakkiin, 
	// niin siirto poistetaan listasta
	int kuninkaanX;
	int kuninkaanY;
	if (vari == 0) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (this->_lauta[i][j] == NULL)
					continue;
				if (this->_lauta[i][j]->getKoodi() == VK) {
					kuninkaanX = i;
					kuninkaanY = j;
					break;
				}
			}
		}
	}
	if (vari == 1) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (this->_lauta[i][j] == NULL)
					continue;
				if (this->_lauta[i][j]->getKoodi() == MK) {
					kuninkaanX = i;
					kuninkaanY = j;
					break;
				}
			}
		}
	}
	// Jotta ei jouduta perumaan oikeaan asemaan tehty‰ siirtoa
	Asema testiAsema;
	std::list<Siirto> siivottuSiirrotLista;
	for (auto s : lista) {
		testiAsema = *this;
		testiAsema.paivitaAsema(&s);
		int x, y;

		// Kuninkaan siirto?
		if (s.onkoLyhytLinna())
		{
			x = 6;
			if (this->getSiirtovuoro() == 0)
				y = 0;
			else
				y = 7;
		}
		else if (s.onkoPitk‰linna())
		{
			x = 2;
			if (this->getSiirtovuoro() == 0)
				y = 0;
			else
				y = 7;
		}
		else
		{
			Nappula* siirtyva = this->_lauta[s.getAlkuruutu().getSarake()][s.getAlkuruutu().getRivi()];
			if (siirtyva->getKoodi() == VK || siirtyva->getKoodi() == MK)
			{
				x = s.getLoppuruutu().getSarake();
				y = s.getLoppuruutu().getRivi();
			}
			else
			{
				// Ei ole, kuninkaan sijainti sama kuin ennen siirron s kokeilua
				x = kuninkaanX;
				y = kuninkaanY;
			}
		}

		// huom !vari
		if (testiAsema.onkoRuutuUhattu(&Ruutu(x, y), !vari) == true) {
			siivottuSiirrotLista.push_back(s);
		}
	}
	lista = siivottuSiirrotLista;
}


void Asema::annaLinnoitusSiirrot(std::list<Siirto>& lista, int vari)
{
	//// Linnoituksien huomioiminen
	//// 1. Kuningas ei saa olla liikkunut
	//// 2. Torni ei saa olla liikkunut
	//// 3. Kuningas ei saa olla shakattuna
	//// 4. Ruutujen pit‰‰ olla tyhj‰t
	//// 5. Ruudut eiv‰t saa olla uhattuja
	if (vari == 0) {
		//valkean lyhyt linna
		if (!this->getOnkoValkeaKuningasLiikkunut() && !this->getOnkoValkeaKTliikkunut()
			&& this->onkoRuutuUhattu(&Ruutu(4, 0), !vari)
			&& this->onkoRuutuUhattu(&Ruutu(5, 0), !vari) && this->onkoRuutuUhattu(&Ruutu(6, 0), !vari)
			&& this->_lauta[5][0] == NULL && this->_lauta[6][0] == NULL) {
			//p‰ivitet‰‰n listaan lyhytlinna
			lista.push_back(Siirto(true, false)); // lis‰t‰‰n listaan lyhyt linna
		}
		//valkean pitk‰ linna
		if (!this->getOnkoValkeaKuningasLiikkunut() && !this->getOnkoValkeaDTliikkunut()
			&& this->onkoRuutuUhattu(&Ruutu(4, 0), !vari)
			&& this->onkoRuutuUhattu(&Ruutu(3, 0), !vari) && this->onkoRuutuUhattu(&Ruutu(3, 0), !vari)
			&& this->_lauta[3][0] == NULL && this->_lauta[2][0] == NULL) {
			//p‰ivitet‰‰n listaan lyhytlinna
			lista.push_back(Siirto(false, true)); // lis‰t‰‰n listaan lyhyt linna
		}
	}
	if (vari == 1) {
		//mustan lyhyt linna
		if (!this->getOnkoMustaKuningasLiikkunut() && !this->getOnkoMustaKTliikkunut()
			&& this->onkoRuutuUhattu(&Ruutu(4, 7), !vari)
			&& this->onkoRuutuUhattu(&Ruutu(5, 7), !vari) && this->onkoRuutuUhattu(&Ruutu(6, 7), !vari)
			&& this->_lauta[5][7] == NULL && this->_lauta[6][7] == NULL) {
			//p‰ivitet‰‰n listaan lyhytlinna
			lista.push_back(Siirto(true, false)); // lis‰t‰‰n listaan lyhyt linna
		}
		//mustan pitk‰ linna
		if (!this->getOnkoMustaKuningasLiikkunut() && !this->getOnkoMustaDTliikkunut()
			&& this->onkoRuutuUhattu(&Ruutu(4, 7), !vari)
			&& this->onkoRuutuUhattu(&Ruutu(3, 7), !vari) && this->onkoRuutuUhattu(&Ruutu(3, 7), !vari)
			&& this->_lauta[3][7] == NULL && this->_lauta[2][7] == NULL) {
			//p‰ivitet‰‰n listaan lyhytlinna
			lista.push_back(Siirto(false, true)); // lis‰t‰‰n listaan lyhyt linna
		}
	}
}


void Asema::annaLaillisetSiirrot(std::list<Siirto>& lista) {
	int vari = this->getSiirtovuoro();

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			//Ei kysele tyhjilt‰ ruuduilta nappulan nime‰
			if (this->_lauta[i][j] == NULL) {
				continue;
			}
			if (this->_lauta[i][j]->getVari() != vari) {
				continue;
			}
			this->_lauta[i][j]->annaSiirrot(lista, &Ruutu(i, j), this, vari); // myˆh‰inen sidonta!
		}
	}
	this->annaLinnoitusSiirrot(lista, vari);
	this->huolehdiKuninkaanShakeista(lista, vari);
}


MinMaxPaluu Asema::minimax(int syvyys)
{
	MinMaxPaluu paluuarvo;

	// Generoidaan aseman lailliset siirrot.
	std::list<Siirto> siirrot;
	annaLaillisetSiirrot(siirrot);

	// Rekursion kantatapaus 1: peli on loppu koska laillisia siirtoja ei ole.
	if (siirrot.size() == 0)
	{
		paluuarvo._evaluointiArvo = lopputulos();
		return paluuarvo;
	}

	// Rekursion kantatapaus 2: katkaisusyvyydess‰
	if (syvyys == 0)
	{
		paluuarvo._evaluointiArvo = evaluoi();
		return paluuarvo;
	}

	// Rekursioaskel: kokeillaan jokaista laillista siirtoa s
	// (alustetaan paluuarvo huonoimmaksi mahdolliseksi).
	paluuarvo._evaluointiArvo = (_siirtovuoro == 0 ? -1000000 : 1000000);
	for (auto s : siirrot)
	{
		// Seuraaja-asema (tehd‰‰n nykyisess‰ asemassa siirto s).
		Asema uusi_asema = *this;
		uusi_asema.paivitaAsema(&s);

		// Rekursiivinen kutsu.
		MinMaxPaluu arvo = uusi_asema.minimax(syvyys - 1);

		// Tutkitaan ollaan lˆydetty uusi paras siirto.
		if
		(
			(_siirtovuoro == 0 && arvo._evaluointiArvo > paluuarvo._evaluointiArvo) ||
			(_siirtovuoro == 1 && arvo._evaluointiArvo < paluuarvo._evaluointiArvo)
		)
		{
			// Lˆydettiin uusi paras siirto.
			paluuarvo._evaluointiArvo = arvo._evaluointiArvo;
			paluuarvo._parasSiirto = s;
		}
	}
	return paluuarvo;
}


double Asema::lopputulos()
{
	// Asemassa ei ole en‰‰ laillisia siirtoja. Etsit‰‰n siirtovuoroisen pelaajan
	// kuningas; jos kuningas on uhattu, on pelaaja h‰vinnyt (muuten tasapeli, "patti").

	// Kuninkaan sijainti (x,y).
	Nappula* kunkku = _siirtovuoro == 0 ? vk : mk;
	int kx, ky;
	for (int x = 0; x < 8; ++x)
	{
		for (int y = 0; y < 8; ++y)
		{
			if (_lauta[x][y] == kunkku)
			{
				kx = x;
				ky = y;
			}
		}
	}

	if (onkoRuutuUhattu(&Ruutu(kx, ky), _siirtovuoro == 0 ? 1 : 0))
		return 0; // tasapeli (patti)
	else
		return _siirtovuoro == 0 ? -1000000 : 1000000;	// matti
}


/* 
	Aseman numeerinen arviointi eri tekijˆiden perusteella, esim.

	1. Nappuloiden arvo ("materiaali")
		Daami = 9
		Torni = 5
		L‰hetti = 3,25
		Ratsu = 3
		Sotilas = 1

	2. Kuninkaan turvallisuus/hyvyys
		Jos avaus tai keskipeli, niin hyv‰ ett‰ kunigas g1 tai b1/c1
		Loppupeliss‰ vaikea sanoa halutaanko olla auttamassa omaa sotilasta korottumaan
		vai olla est‰m‰ss‰ vastustajan korotusta siksi ei oteta kantaa.

	3. Sentralisaatio (keskustan hallinta)
		Nappulat ovat yleens‰ paremmin laudan keskell‰ kuin laidoilla.

	4. Linjojen hallinta
		Tornit sijaitsevat hyvin avoimilla linjoilla (= linja jolla ei ole yht‰‰n omaa sotilasta).

	jne. jne.
*/
double Asema::evaluoi()
{
	// Vakiokertoimet kuvaavat eri tekijˆiden t‰rkeytt‰ suhteessa toisiinsa.
	// Kertoimien asettaminen edellytt‰‰ testaamista ja sovellusalueen (shakki)
	// osaamista. T‰ss‰ materiaalin t‰rkeydeksi on asetettu 1. Muiden tekijˆiden
	// kertoimet ovat yleens‰ t‰t‰ pienempi‰, koska materiaali on kaikkein
	// t‰rkein yksitt‰inen tekij‰.
	const double materiaaliKerroin = 1.0;

	// Materiaali
	double materiaali = laskeNappuloidenArvo(0) - laskeNappuloidenArvo(1);

	// Palautetaan eri tekijˆiden painotettu summa.
	return materiaaliKerroin * materiaali; // + linjaKerroin * linjat + ... jne
}


double Asema::laskeNappuloidenArvo(int vari)
{
	double valkeaArvo = 0;
	double mustaArvo = 0;
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {
			if (this->_lauta[x][y] != NULL) {
				int nappulanNimi = this->_lauta[x][y]->getKoodi();
				//Valkoiset
				if (nappulanNimi == VD)
					valkeaArvo += 9;
				if (nappulanNimi == VT)
					valkeaArvo += 5;
				if (nappulanNimi == VL)
					valkeaArvo += 3.25;
				if (nappulanNimi == VR)
					valkeaArvo += 3;
				if (nappulanNimi == VS)
					valkeaArvo += 1;
				//Mustat
				if (nappulanNimi == MD)
					mustaArvo += 9;
				if (nappulanNimi == MT)
					mustaArvo += 5;
				if (nappulanNimi == ML)
					mustaArvo += 3.25;
				if (nappulanNimi == MR)
					mustaArvo += 3;
				if (nappulanNimi == MS)
					mustaArvo += 1;
			}
		}
	}
	if (vari == 0)
		return valkeaArvo;
	else
		return mustaArvo;
}


