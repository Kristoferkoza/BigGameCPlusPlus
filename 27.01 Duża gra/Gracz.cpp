#include "Gracz.h"
#include "Enums.h"
#include <iostream>

using namespace std;

Gracz::Gracz(string _nazwa, int _x, int _y, int _id)
{
	nazwa = _nazwa;
	iloscPunktow = 0;
	punktyRuchu = 5;
	x = _x;
	y = _y;
	id = _id;
}

string Gracz::getNazwa()
{
	return nazwa;
}

int Gracz::getIloscPunktow()
{
	return iloscPunktow;
}

int Gracz::getPunktyRuchu()
{
	return punktyRuchu;
}

void Gracz::ustawGracza(int _x, int _y)
{
	x = _x;
	y = _y;
}

int Gracz::getX()
{
	return x;
}

int Gracz::getY()
{
	return y;
}

int Gracz::getID()
{
	return id;
}

void Gracz::setX(int _x)
{
	x = _x;
}

void Gracz::setY(int _y)
{
	y = _y;
}

int Gracz::czyJestGracz(int _x, int _y)
{
	if (x == _x && y == _y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Gracz::zmienPunktyRuchu(int a)
{
	punktyRuchu = punktyRuchu + a;
}

void Gracz::zmienIloscPunktow(int a)
{
	iloscPunktow = iloscPunktow + a;
}