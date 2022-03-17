#ifndef Pole_HEADER
#define Pole_HEADER

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <string>
#include "Przedmiot.h"

using namespace std;

class Pole
{
private:
	string opis;
	RodzajPola rodzaj;
	Kolor kolor;
	bool czyJestPrzedmiot;
	Przedmiot* przedmiot;
public:
	Pole();
	char getSkrot();
	string getNazwa();
	string getOpis();
	Kolor getKolor();
	bool getCzyJestPrzedmiot();
};

#endif