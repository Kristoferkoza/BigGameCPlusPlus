#include "Polozenie.h"
#include <iostream>

using namespace std;

Polozenie::Polozenie(int _x, int _y)
{
	x = _x;
	y = _y;
}


int Polozenie::getX()
{
	return x;
}

int Polozenie::getY()
{
	return y;
}

void Polozenie::setX(int _x)
{
	x = _x;
}

void Polozenie::setY(int _y)
{
	y = _y;
}

int Polozenie::czyJestGracz(int _x, int _y)
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