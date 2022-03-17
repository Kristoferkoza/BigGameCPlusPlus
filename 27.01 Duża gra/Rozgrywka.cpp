#include "Rozgrywka.h"
#include "Enums.h"
#include "Pole.h"
#include "Plansza.h"
#include "Gracz.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

int losowanie(int n)
{
	int m;
	m = rand() % n;
	return m;
}
	
Rozgrywka::Rozgrywka(int n, string nazwa1, string nazwa2)
{
	srand(time(NULL));
	plansza = new Plansza(n);

	int a, b;
	a = losowanie(n);
	b = losowanie(n);
	while (plansza->getPole(a, b)->getSkrot() != ToChar(Polana))
	{
		a = losowanie(n);
		b = losowanie(n);
	}
	
	player1 = new Gracz(nazwa1,a,b, 1);

	a = losowanie(n);
	b = losowanie(n);
	while (plansza->getPole(a, b)->getSkrot() != ToChar(Polana))
	{
		a = losowanie(n);
		b = losowanie(n);
	}

	player2 = new Gracz(nazwa2, a, b, 2);

	plansza->przekazGraczy(player1, player2);

	plansza->wyswietlPlansze();
}

void Rozgrywka::startRozgrywki()
{
	turaGracza(player1);
}

void Rozgrywka::turaGracza(Gracz *player)
{
	int x, y;
	bool wykonanyRuch = false;
	x = player->getX();
	y = player->getY();
	int ch = _getch();
	if (ch == 224) 
	{
		ch = _getch();
		while (wykonanyRuch == false)
		{
			if (ch == 72 && plansza->getPole(x - 1, y)->getSkrot() != ToChar(Skaly))
			{
				player->setX(x - 1);
				wykonanyRuch = true;
			}
			else
			{
				if (ch == 80 && plansza->getPole(x + 1, y)->getSkrot() != ToChar(Skaly))
				{
					player->setX(x + 1);
					wykonanyRuch = true;
				}
				else
				{
					if (ch == 77 && plansza->getPole(x, y + 1)->getSkrot() != ToChar(Skaly))
					{
						player->setY(y + 1);
						wykonanyRuch = true;
					}
					else
					{
						if (ch == 75 && plansza->getPole(x, y - 1)->getSkrot() != ToChar(Skaly))
						{
							player->setY(y - 1);
							wykonanyRuch = true;
						}
						else
						{
							cout << "Pojscie w wybranym kierunku jest niemozliwe. Wybierz inny ruch: ";
							ch = _getch();
						}
					}
				}
			}
		}
	}
	else 
	{
		cout << char(ch) << '\n';
	}
	system("cls");
	plansza->przekazGracza(player);
	cout << endl << endl;
	plansza->wyswietlPlansze();

}


