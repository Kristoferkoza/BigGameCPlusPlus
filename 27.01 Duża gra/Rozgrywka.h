#ifndef Rozgrywka_HEADER
#define Rozgrywka_HEADER

#include <iostream>
#include <string>
#include "Plansza.h"
#include "Gracz.h"

using namespace std;

class Rozgrywka
{
private:
	Plansza* plansza;
	Gracz* player1;
	Gracz* player2;
	char czyDalej;
	bool koniecRozgrywki;
public:
	Rozgrywka(int n, string _nazwa1, string _nazwa2);
	void startRozgrywki();
	void ruchGracza(Gracz* player);
};

#endif