#include "Pole.h"
#include "Enums.h"
#include "Przedmiot.h"
#include "Rozgrywka.h"
#include <iostream>
#include <string>

using namespace std;

Pole::Pole()
{
	int n;
	n = rand() % 6 + 1;
	if (n == 1 || n == 2 || n == 3)
	{
		rodzaj = Polana;
		opis = "Stoisz teraz na polanie (P).";
		kolor = Zielony;
	}
	if (n == 4 || n == 5)
	{
		rodzaj = Woda;
		opis = "Jesteœ teraz w wodzie (W).";
		kolor = Niebieski;
	}
	if (n == 6)
	{
		rodzaj = Skaly;
		opis = "Na skaly nie mozna wejsc (S).";
		kolor = Bialy;
	}

	int a;
	a = rand() % 3+1;
	if(a == 1)
	{ 
		czyJestPrzedmiot = true;
	}
	else
	{
		czyJestPrzedmiot = false;
	}

	if (czyJestPrzedmiot == true && ToString(rodzaj) == ToString(Polana))
	{
		przedmiot = new Przedmiot;
	}
	else
	{
		czyJestPrzedmiot = false;
	}

}

Pole::Pole(string litera)
{
	if (litera=="P")
	{
		rodzaj = Polana;
		opis = "Stoisz teraz na polanie (P).";
		kolor = Zielony;
	}
	if (litera == "W")
	{
		rodzaj = Woda;
		opis = "Jesteœ teraz w wodzie (W).";
		kolor = Niebieski;
	}
	if (litera == "S")
	{
		rodzaj = Skaly;
		opis = "Na skaly nie mozna wejsc (S).";
		kolor = Bialy;
	}
}

char Pole::getSkrot()
{
	return ToChar(rodzaj);
}

string Pole::getNazwa()
{
	return ToString(rodzaj);
}

string Pole::getOpis()
{
	return opis;
}

Kolor Pole::getKolor()
{
	return kolor;
}

bool Pole::getCzyJestPrzedmiot()
{
	return czyJestPrzedmiot;
}

Przedmiot Pole::getPrzedmiot()
{
	return *przedmiot;
}

void Pole::zmienCzyJestPrzedmiot(bool zmiana)
{
	czyJestPrzedmiot = zmiana;
}

void Pole::ustawPrzedmiot(string skrot)
{
	przedmiot = new Przedmiot(skrot);
}