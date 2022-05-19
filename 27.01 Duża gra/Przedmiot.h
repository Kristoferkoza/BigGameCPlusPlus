#ifndef Przedmiot_HEADER
#define Przedmiot_HEADER

#include <iostream>
#include <string>
#include "Enums.h"
using namespace std;

class Przedmiot
{
private:
	char symbol;
	string nazwa;
	int iloscPunktow;
	Rzecz rzecz;
public:
	Przedmiot();
	Przedmiot(string skrot);
	char getSymbol();
	string getNazwa();
	int getIloscPunktow();
};

#endif
