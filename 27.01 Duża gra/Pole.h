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
	Pole(string litera);
	char getSkrot();
	string getNazwa();
	string getOpis();
	Kolor getKolor();
	Przedmiot getPrzedmiot();
	bool getCzyJestPrzedmiot();
	void zmienCzyJestPrzedmiot(bool zmiana);
	void ustawPrzedmiot(string skrot);
};

#endif