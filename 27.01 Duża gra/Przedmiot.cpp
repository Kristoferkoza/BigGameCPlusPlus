#include "Przedmiot.h"
#include "Enums.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;



Przedmiot::Przedmiot()
{
	int m;
	m = rand() % 15 + 1;

	if (m == 1 || m == 2)
	{
		rzecz = Miecz;
	}
	if (m == 3 || m == 4)
	{
		rzecz = Zbroja;
	}
	if (m == 5 || m == 6 || m == 7)
	{
		rzecz = Napoj;
	}
	if (m == 8 || m == 9 || m == 10)
	{
		rzecz = Truskawki;
	}
	if (m == 11)
	{
		rzecz = Diament;
	}
	if (m == 12 || m == 13)
	{
		rzecz = Kolce;
	}
	if (m == 14)
	{
		rzecz = Wojownik;
	}
	if (m == 15)
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