#ifndef Plansza_HEADER
#define Plansza_HEADER

#include <iostream>
#include "Pole.h"
#include "Gracz.h"
#include "Polozenie.h"

using namespace std;

class Plansza
{
private:
	int a;
	Pole*** tablica;
	Gracz *gracz1;
	Gracz *gracz2;
public:
	Plansza(int _a, bool tworz);
	void wyswietlPlansze();
	Pole* getPole(int _x, int _y);
	void przekazGraczy(Gracz* gracz1_, Gracz* gracz2_);
	void przekazGracza(Gracz* gracz_);
	int getRozmiar();
	void ustawPole(Pole* pole, int x, int y);
};

#endif
