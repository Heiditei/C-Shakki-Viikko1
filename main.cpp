#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <iostream>
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
		ui.piirraLauta();
		Siirto s = ui.annaVastustajanSiirto();
		asema.paivitaAsema(&s);
	}

	return 0;
}
