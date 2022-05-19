#include "Plansza.h"
#include "Polozenie.h"
#include "Przedmiot.h"
#include "Pole.h"
#include "Enums.h"
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

Plansza::Plansza(int _a, bool tworz)
{
	a = _a;
	tablica = new Pole * *[a];
	for (int i = 0; i < a; i++)
	{
		tablica[i] = new Pole * [a];
	}

	if (tworz)
	{

		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < a; j++)
			{
				Pole* pole1 = new Pole;
				tablica[i][j] = pole1;
			}
		}
	}
	//cout << "TEST: " << tablica[0][0]->getNazwa();
		
}

void Plansza::wyswietlPlansze()
{
    HANDLE hOut;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    
	string kolor;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			Kolor kolor;
			Pole* wsk = tablica[i][j];
			kolor = wsk->getKolor();
			if (kolor == Zielony)
			{
				SetConsoleTextAttribute(hOut,
					BACKGROUND_GREEN |
					BACKGROUND_INTENSITY);
			}
			if (kolor == Niebieski)
			{
				SetConsoleTextAttribute(hOut,
					BACKGROUND_BLUE |
					BACKGROUND_INTENSITY);
			}
			if (kolor == Bialy)
			{
				SetConsoleTextAttribute(hOut,
					BACKGROUND_RED |
					BACKGROUND_GREEN |
					BACKGROUND_BLUE);
			}

			if (gracz1->czyJestGracz(i, j) == 1)
			{
				SetConsoleTextAttribute(hOut,
					BACKGROUND_RED);
				cout << "[ G1]";
			}
			else
			{
				if (gracz2->czyJestGracz(i, j) == 1)
				{
					SetConsoleTextAttribute(hOut,
						BACKGROUND_RED);
					cout << "[ G2]";	
				}
				else
				{
					if (wsk->getCzyJestPrzedmiot())
					{
						cout << "[" << " " << wsk->getSkrot() << "*" << "]";
					}
					else
					{
						cout << "[" << " " << wsk->getSkrot() << " " << "]";
					}
				}
			}

		}
		cout << endl;
	}
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
}

Pole* Plansza::getPole(int _x, int _y)
{
	return tablica[_x][_y];
}

void Plansza::przekazGraczy(Gracz* gracz1_, Gracz* gracz2_)
{
	gracz1 = gracz1_;
	gracz2 = gracz2_;
}

void Plansza::przekazGracza(Gracz* gracz_)
{
	if (gracz_->getID() == 1)
	{
		gracz1 = gracz_;
	}
	if (gracz_->getID() == 2)
	{
		gracz2 = gracz_;
	}
}

int Plansza::getRozmiar()
{
	return a;
}

void Plansza::ustawPole(Pole* pole, int x, int y)
{
	tablica[x][y] = pole;
}