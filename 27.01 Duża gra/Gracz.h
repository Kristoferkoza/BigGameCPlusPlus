#ifndef Gracz_HEADER
#define Gracz_HEADER

#include <iostream>
#include <string>

using namespace std;

class Gracz
{
private:
	string nazwa;
	int iloscPunktow;
	int punktyRuchu;
	int id;
	int x;
	int y;
public:
	Gracz(string _nazwa, int _x, int _y, int _id);
	Gracz(string _nazwa, int _x, int _y, int _id, int _punktyRuchu, int punkty);
	string getNazwa();
	int getIloscPunktow();
	int getPunktyRuchu();
	void ustawGracza(int _x, int _y);
	void setX(int _x);
	void setY(int _y);
	int getX();
	int getY();
	int getID();
	int czyJestGracz(int _x, int _y);
	void zmienPunktyRuchu(int a);
	void zmienIloscPunktow(int a);
};

#endif