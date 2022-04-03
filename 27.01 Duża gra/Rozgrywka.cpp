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
#define q 113

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
	Gracz* player;
	koniecRozgrywki = false;
	while (player1->getIloscPunktow() < 20 && player2->getIloscPunktow() < 20 && koniecRozgrywki == false)
	{
		player = player1;
		cout << endl << "Teraz jest tura gracza 1." << endl;
		cout << endl << "Twoje punkty ruchu: " << player->getPunktyRuchu() << ". " << endl;
		cout << "Twoje zdobyte punkty: " << player->getIloscPunktow() << ". " << endl;
		cout << "Czy chcesz wykonac ruch? Jesli tak, wpisz a. Jesli nie, wpisz q: ";
		cin >> czyDalej;
		while (player->getPunktyRuchu() > 0 && czyDalej != 'q')
		{
			ruchGracza(player1);
			if (koniecRozgrywki == true)
			{
				break;
			}
			if (player->getPunktyRuchu() != 0)
			{
				cout << endl << "Twoje punkty ruchu: " << player->getPunktyRuchu() << ". " << endl;
				cout << "Twoje zdobyte punkty: " << player->getIloscPunktow() << ". " << endl;
				cout << "Jesli chcesz zakonczyc swoja ture, napisz q. Aby kontynuowac ruch wskaz kierunek ruchu wybierajac odpowiednia strzalke.";
			}
		}
		if (koniecRozgrywki == true)
		{
			break;
		}
		player->zmienPunktyRuchu(5);
		

		player = player2;
		cout << endl << "Teraz jest tura gracza 2." << endl;
		czyDalej = 'a';
		cout << endl << "Twoje punkty ruchu: " << player->getPunktyRuchu() << ". " << endl;
		cout << "Twoje zdobyte punkty: " << player->getIloscPunktow() << ". " << endl;
		cout << "Czy chcesz wykonac ruch? Jesli tak, wpisz a. Jesli nie, wpisz q: ";
		cin >> czyDalej;
		while (player->getPunktyRuchu() > 0 && czyDalej != 'q')
		{
			ruchGracza(player2);
			if (koniecRozgrywki == true)
			{
				break;
			}
			if (player->getPunktyRuchu() != 0)
			{
				cout << endl << "Twoje punkty ruchu: " << player->getPunktyRuchu() << ". " << endl;
				cout << "Twoje zdobyte punkty: " << player->getIloscPunktow() << ". " << endl;
				cout << "Jesli chcesz zakonczyc swoja ture, napisz q. Aby kontynuowac ruch wskaz kierunek ruchu wybierajac odpowiednia strzalke.";
			}
		}
		player->zmienPunktyRuchu(5);
	}
	if (player1->getIloscPunktow() >= 20 && player1->getIloscPunktow() > player2->getIloscPunktow())
	{
		cout << endl << player1->getNazwa() << " wygrywa!" << endl;
		cout << player1->getNazwa() << ": " << player1->getIloscPunktow() << ". " << player2->getNazwa() << ": " << player2->getIloscPunktow() << ".";
	}
	else
	{
		if (player2->getIloscPunktow() >= 20 && player1->getIloscPunktow() < player2->getIloscPunktow())
		{
			cout << endl << player2->getNazwa() << " wygrywa!" << endl;
			cout << player1->getNazwa() << ": " << player1->getIloscPunktow() << ". " << player2->getNazwa() << ": " << player2->getIloscPunktow() << ".";
		}
		else
		{
			cout << endl << "Mamy remis!" << endl;
			cout << player1->getNazwa() << ": " << player1->getIloscPunktow() << ". " << player2->getNazwa() << ": " << player2->getIloscPunktow() << ".";
		}
	}
	


	if (koniecRozgrywki == true)
	{
		cout << endl << "Walka!" << endl;
		if (player1->getIloscPunktow() > player2->getIloscPunktow())
		{
			cout << player1->getNazwa() << " wygrywa pojedynek, wiec zostaje zwyciezca!" << endl;
			cout << player1->getNazwa() << ": " << player1->getIloscPunktow() << ". " << player2->getNazwa() << ": " << player2->getIloscPunktow() << ".";
		}
		if (player1->getIloscPunktow() < player2->getIloscPunktow())
		{
			cout << player2->getNazwa() << " wygrywa pojedynek, wiec zostaje zwyciezca!" << endl;
			cout << player1->getNazwa() << ": " << player1->getIloscPunktow() << ". " << player2->getNazwa() << ": " << player2->getIloscPunktow() << ".";
		}
		if (player1->getIloscPunktow() == player2->getIloscPunktow())
		{
			cout << "Gracze maja jednakowa liczbe punktow, wiec mamy remis!" << endl;
			cout << player1->getNazwa() <<": " << player1->getIloscPunktow() << ". " << player2->getNazwa() << ": " << player2->getIloscPunktow() << ".";
		}
	}
}

void Rozgrywka::ruchGracza(Gracz *player)
{
	int x, y;
	
	x = player->getX();
	y = player->getY();
	int ch = _getch();
	bool wykonanyRuch = false;

	if (ch == 224) 
	{
		while (wykonanyRuch == false)
		{
			ch = _getch();
			if (ch == 72 && x != 0 && plansza->getPole(x - 1, y)->getSkrot() != ToChar(Skaly))
			{
				if (plansza->getPole(x - 1, y)->getSkrot() == ToChar(Woda) && player->getPunktyRuchu() > 1)
				{
					player->zmienPunktyRuchu(-2);
					player->setX(x - 1);
					wykonanyRuch = true;
				}
				if (plansza->getPole(x - 1, y)->getSkrot() == ToChar(Polana))
				{
					player->zmienPunktyRuchu(-1);
					player->setX(x - 1);
					wykonanyRuch = true;
				}
				
			}
			else
			{
				if (ch == 80 && x != (plansza->getRozmiar()-1) && plansza->getPole(x + 1, y)->getSkrot() != ToChar(Skaly))
				{
					if (plansza->getPole(x + 1, y)->getSkrot() == ToChar(Woda) && player->getPunktyRuchu() > 1)
					{
						player->zmienPunktyRuchu(-2);
						player->setX(x + 1);
						wykonanyRuch = true;
					}
					if (plansza->getPole(x + 1, y)->getSkrot() == ToChar(Polana))
					{
						player->zmienPunktyRuchu(-1);
						player->setX(x + 1);
						wykonanyRuch = true;
					}
					
				}
				else
				{
					if (ch == 77 && y != (plansza->getRozmiar() - 1) && plansza->getPole(x, y + 1)->getSkrot() != ToChar(Skaly))
					{
						if (plansza->getPole(x, y + 1)->getSkrot() == ToChar(Woda) && player->getPunktyRuchu() > 1)
						{
							player->zmienPunktyRuchu(-2);
							player->setY(y + 1);
							wykonanyRuch = true;
						}
						if (plansza->getPole(x, y + 1)->getSkrot() == ToChar(Polana))
						{
							player->zmienPunktyRuchu(-1);
							player->setY(y + 1);
							wykonanyRuch = true;
						}
						
					}
					else
					{
						if (ch == 75 && y != 0 && plansza->getPole(x, y - 1)->getSkrot() != ToChar(Skaly))
						{
							if (plansza->getPole(x, y - 1)->getSkrot() == ToChar(Woda) && player->getPunktyRuchu() > 1)
							{
								player->zmienPunktyRuchu(-2);
								player->setY(y - 1);
								wykonanyRuch = true;
							}
							if (plansza->getPole(x, y - 1)->getSkrot() == ToChar(Polana))
							{
								player->zmienPunktyRuchu(-1);
								player->setY(y - 1);
								wykonanyRuch = true;
							}
							
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
		if (ch == 113)
		{
			wykonanyRuch = true;
			czyDalej = 'q';
		}
	}

	system("cls");
	plansza->przekazGracza(player);
	cout << endl << endl;
	plansza->wyswietlPlansze();
	x = player->getX();
	y = player->getY();
	if (plansza->getPole(x, y)->getCzyJestPrzedmiot() == true)
	{
		player->zmienIloscPunktow(plansza->getPole(x, y)->getPrzedmiot().getIloscPunktow());
		cout << "Na polu, na ktore wszedles/as znajdowal sie: " << plansza->getPole(x, y)->getPrzedmiot().getNazwa();
		plansza->getPole(x, y)->zmienCzyJestPrzedmiot(false);
	}
	if (player1->getX()==player2->getX() && player1->getY() == player2->getY())
	{
		koniecRozgrywki = true;
	}

}

