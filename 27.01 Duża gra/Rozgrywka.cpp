#include "Rozgrywka.h"
#include "Enums.h"
#include "Pole.h"
#include "Plansza.h"
#include "Gracz.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define q 113
#define k 3

using namespace std;

int losowanie(int n)
{
	int m;
	m = rand() % n;
	return m;
}

string Rozgrywka::szyfrCS(string wyraz)
{
	int dlugosc = wyraz.length();
	char znak;
	for (int i = 0; i < dlugosc; i++)
	{
		znak = wyraz[i];
		if (znak > 64 && znak < 91 - k) //duze litery
		{
			wyraz[i] = znak + k;
		}
		else if (znak >= 91 - k && znak < 91)
		{
			wyraz[i] = znak - 26 + k;
		}

		if (znak > 96 && znak < 123 - k) //male litery
		{
			wyraz[i] = znak + k;
		}
		else if (znak >= 123 - k && znak < 123)
		{
			wyraz[i] = znak - 26 + k;
		}
	}
	return wyraz;
}

char Rozgrywka::szyfrCC(char litera)
{

	if (litera > 64 && litera < 91 - k) //duze litery
	{
		litera = litera + k;
	}
	else if (litera >= 91 - k && litera < 91)
	{
		litera = litera - 26 + k;
	}

	if (litera > 96 && litera < 123 - k) //male litery
	{
		litera = litera + k;
	}
	else if (litera >= 123 - k && litera < 123)
	{
		litera = litera - 26 + k;
	}
	return litera;
}

string Rozgrywka::szyfrCI(int liczba)
{
	string wyraz = to_string(liczba);
	int dlugosc = wyraz.length();
	char znak;
	for (int i = 0; i < dlugosc; i++)
	{
		znak = wyraz[i];
		if (znak > 47 && znak < 58 - k)
		{
			wyraz[i] = wyraz[i] + k;
		}
		else if (znak >= 58 - k && znak < 58)
		{
			wyraz[i] = wyraz[i] - 10 + k;
		}
	}
	
	return wyraz;
}

string Rozgrywka::odczytCS(string wyraz)
{
	int dlugosc = wyraz.length();
	char znak;
	for (int i = 0; i < dlugosc; i++)
	{
		znak = wyraz[i];
		if (znak > 64+k && znak < 91) //duze litery
		{
			wyraz[i] = znak - k;
		}
		else if (znak > 64 && znak <= 64+k)
		{
			wyraz[i] = znak + 26 - k;
		}

		if (znak > 96+k && znak < 123) //male litery
		{
			wyraz[i] = znak - k;
		}
		else if (znak > 96 && znak <= 96+k)
		{
			wyraz[i] = znak + 26 - k;
		}
	}
	return wyraz;
}


char Rozgrywka::odczytCC(char litera)
{
	if (litera > 64 + k && litera < 91) //duze litery
	{
		litera = litera - k;
	}
	else if (litera > 64 && litera <= 64 + k)
	{
		litera = litera + 26 - k;
	}

	if (litera > 96 + k && litera < 123) //male litery
	{
		litera = litera - k;
	}
	else if (litera > 96 && litera <= 96 + k)
	{
		litera = litera + 26 - k;
	}
	return litera;
}


int Rozgrywka::odczytCI(string liczba)
{
	int dlugosc = liczba.length();
	char znak;
	for (int i = 0; i < dlugosc; i++)
	{
		znak = liczba[i];
		if (znak > 47+k && znak < 58)
		{
			liczba[i] = liczba[i] - k;
		}
		else if (znak > 47 && znak <= 47+k)
		{
			liczba[i] = liczba[i] + 10 - k;
		}
	}
	int numer = stoi(liczba);
	return numer;
}


Rozgrywka::Rozgrywka(int n, string nazwa1, string nazwa2)
{
	srand(time(NULL));
	plansza = new Plansza(n, true);

	int a, b;
	a = losowanie(n);
	b = losowanie(n);
	while (plansza->getPole(a, b)->getSkrot() != ToChar(Polana))
	{
		a = losowanie(n);
		b = losowanie(n);
	}

	player1 = new Gracz(nazwa1, a, b, 1);

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
	char wczytanie;
	cout << "Chcesz wczytac gre (wpisz w) czy kontynuowac nowowygenerowana (wpisz k)? ";
	cin >> wczytanie;
	if (wczytanie == 'w')
	{
		wczytajGre();
	}
	char zapis = 'a';
	koniecRozgrywki = false;
	while (player1->getIloscPunktow() < 20 && player2->getIloscPunktow() < 20 && koniecRozgrywki == false)
	{
		cout << endl << "Teraz jest tura gracza " << player1->getNazwa() << "." << endl;
		cout << endl << "Twoje punkty ruchu: " << player1->getPunktyRuchu() << ". " << endl;
		cout << "Twoje zdobyte punkty: " << player1->getIloscPunktow() << ". " << endl;
		cout << "Czy chcesz wykonac ruch? Jesli tak, wpisz a. Jesli nie, wpisz q. Jesli chcesz zapisac gre wpisz s: ";
		cin >> czyDalej;
		if (czyDalej == 's')
		{
			zapiszGre();
			break;
		}
		while (player1->getPunktyRuchu() > 0 && czyDalej == 'a')
		{
			ruchGracza(player1);
			if (koniecRozgrywki == true)
			{
				break;
			}
			if (player1->getPunktyRuchu() != 0)
			{
				cout << endl << "Twoje punkty ruchu: " << player1->getPunktyRuchu() << ". " << endl;
				cout << "Twoje zdobyte punkty: " << player1->getIloscPunktow() << ". " << endl;
				cout << "Jesli chcesz zakonczyc swoja ture, napisz q. Aby kontynuowac ruch wskaz kierunek ruchu wybierajac odpowiednia strzalke.";
			}
		}
		if (koniecRozgrywki == true)
		{
			break;
		}
		player1->zmienPunktyRuchu(5);


		cout << endl << "Teraz jest tura gracza " << player2->getNazwa() << "." << endl;
		czyDalej = 'a';
		cout << endl << "Twoje punkty ruchu: " << player2->getPunktyRuchu() << ". " << endl;
		cout << "Twoje zdobyte punkty: " << player2->getIloscPunktow() << ". " << endl;
		cout << "Czy chcesz wykonac ruch? Jesli tak, wpisz a. Jesli nie, wpisz q: ";
		cin >> czyDalej;
		while (player2->getPunktyRuchu() > 0 && czyDalej != 'q')
		{
			ruchGracza(player2);
			if (koniecRozgrywki == true)
			{
				break;
			}
			if (player2->getPunktyRuchu() != 0)
			{
				cout << endl << "Twoje punkty ruchu: " << player2->getPunktyRuchu() << ". " << endl;
				cout << "Twoje zdobyte punkty: " << player2->getIloscPunktow() << ". " << endl;
				cout << "Jesli chcesz zakonczyc swoja ture, napisz q. Aby kontynuowac ruch wskaz kierunek ruchu wybierajac odpowiednia strzalke.";
			}
		}
		player2->zmienPunktyRuchu(5);

		/*cout << "Czy chcesz zapisac gre? Jesli tak, nacisnij przycisk 's' na klawiaturze. W przeciwnym przypadku nacisnij przycisk 'a'.";
		cin >> zapis;
		if (zapis == 's')
		{
			zapiszGre();
			break;
		}*/

	}

	if (koniecRozgrywki == true)
	{
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

		if (player1->getX() == player2->getX() && player1->getY() == player2->getY())
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
				cout << player1->getNazwa() << ": " << player1->getIloscPunktow() << ". " << player2->getNazwa() << ": " << player2->getIloscPunktow() << ".";
			}
		}
	}

}

void Rozgrywka::ruchGracza(Gracz* player)
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
				if (ch == 80 && x != (plansza->getRozmiar() - 1) && plansza->getPole(x + 1, y)->getSkrot() != ToChar(Skaly))
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
	if (player1->getX() == player2->getX() && player1->getY() == player2->getY())
	{
		koniecRozgrywki = true;
	}

}

void Rozgrywka::zapiszGre()
{
	int rozmiar = plansza->getRozmiar();
	string nazwa_pliku;
	cout << "Podaj nazwe pliku, w ktorym zostanie zapisany aktualny stan rozgrywki: ";
	cin >> nazwa_pliku;
	nazwa_pliku.append(".txt");
	
	ofstream plik(nazwa_pliku);
	plik << szyfrCI(rozmiar) << endl;

	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < rozmiar; j++)
		{
			plik << szyfrCC(plansza->getPole(i, j)->getSkrot()) << " ";
		}
		plik << endl;
	}
	plik << endl;
	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < rozmiar; j++)
		{
			if (plansza->getPole(i, j)->getCzyJestPrzedmiot() == true)
			{
				plik << szyfrCC(plansza->getPole(i, j)->getPrzedmiot().getSymbol()) << " ";
			}
			else
			{
				plik << "0 ";
			}
		}
		plik << endl;
	}
	plik << endl;
	plik << szyfrCI(player1->getID()) << " " << szyfrCS(player1->getNazwa()) << " " << szyfrCI(player1->getIloscPunktow()) << " " << szyfrCI(player1->getPunktyRuchu()) << " " << szyfrCI(player1->getX()) << " " << szyfrCI(player1->getY()) << endl;
	plik << szyfrCI(player2->getID()) << " " << szyfrCS(player2->getNazwa()) << " " << szyfrCI(player2->getIloscPunktow()) << " " << szyfrCI(player2->getPunktyRuchu()) << " " << szyfrCI(player2->getX()) << " " << szyfrCI(player2->getY());


	plik.close();
}

void Rozgrywka::wczytajGre()
{
	string nazwa_pliku;
	cout << "Podaj nazwe pliku, z ktorego zostanie odczytany stan rozgrywki: ";
	cin >> nazwa_pliku;
	nazwa_pliku.append(".txt");
	ifstream plik(nazwa_pliku);

	int rozmiar;

	string tekst;
	char znak;

	string litera;
	plik >> tekst;
	rozmiar = odczytCI(tekst);
	//cout << rozmiar;
	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < rozmiar; j++)
		{
			plik >> znak;
			litera = odczytCC(znak);
			Pole* pole = new Pole(litera);
			plansza->ustawPole(pole, i, j);
			//cout << litera << " ";
		}
	}

	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < rozmiar; j++)
		{
			plik >> znak;
			litera = odczytCC(znak);
			if (litera != "0")
			{
				plansza->getPole(i, j)->zmienCzyJestPrzedmiot(true);
				plansza->getPole(i, j)->ustawPrzedmiot(litera);
			}

		}
	}
	int ID, punktyRuchu, punkty, x, y;
	string nazwa;

	plik >> tekst;
	ID = odczytCI(tekst);
	plik >> tekst;
	nazwa = odczytCS(tekst);
	plik >> tekst;
	punkty = odczytCI(tekst);
	plik >> tekst;
	punktyRuchu = odczytCI(tekst);
	plik >> tekst;
	x = odczytCI(tekst);
	plik >> tekst;
	y = odczytCI(tekst);
	player1 = new Gracz(nazwa, x, y, ID, punktyRuchu, punkty);

	plik >> tekst;
	ID = odczytCI(tekst);
	plik >> tekst;
	nazwa = odczytCS(tekst);
	plik >> tekst;
	punkty = odczytCI(tekst);
	plik >> tekst;
	punktyRuchu = odczytCI(tekst);
	plik >> tekst;
	x = odczytCI(tekst);
	plik >> tekst;
	y = odczytCI(tekst);
	player2 = new Gracz(nazwa, x, y, ID, punktyRuchu, punkty);

	plansza->przekazGraczy(player1, player2);

	cout << endl;
	plansza->wyswietlPlansze();
}