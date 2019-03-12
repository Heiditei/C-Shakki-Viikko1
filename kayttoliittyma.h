#pragma once
#include "asema.h"
#include "nappula.h"


// Shakkiohjelman käyttöliittymä, joka osaa visualisoida nykyisen aseman
// ja lukea käyttäjän syöttämät siirrot.
class Kayttoliittyma
{
public:

	Kayttoliittyma(Asema* asema) { this->_asema = asema; }
	void piirraLauta();
	Siirto annaVastustajanSiirto();

private:

	Asema* _asema;
};
