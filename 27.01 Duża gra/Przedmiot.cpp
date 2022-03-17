#include "Przedmiot.h"
#include "Enums.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;



Przedmiot::Przedmiot()
{
	int m;
	m = rand() % 8 + 1;

	if (m == 1)
	{
		rzecz = Miecz;
	}
	if (m == 2)
	{
		rzecz = Zbroja;
	}
	if (m == 3)
	{
		rzecz = Napoj;
	}
	if (m == 4)
	{
		rzecz = Truskawki;
	}
	if (m == 5)
	{
		rzecz = Diament;
	}
	if (m == 6)
	{
		rzecz = Kolce;
	}
	if (m == 7)
	{
		rzecz = Wojownik;
	}
	if (m == 8)
	{
		rzecz = LZwierze;
	}
}

char Przedmiot::getSymbol()
{
	return ToChar(rzecz);
}


string Przedmiot::getNazwa()
{
	return ToString(rzecz);
}


int Przedmiot::getIloscPunktow()
{
	return rzecz;
}