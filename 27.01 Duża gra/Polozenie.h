#ifndef Polozenie_HEADER
#define Polozenie_HEADER

#include<iostream>
using namespace std;
class Polozenie
{
private:
	int x;
	int y;
public:
	Polozenie(int _x, int _y);
	Polozenie(){}
	int getX();
	int getY();
	void setX(int _x);
	void setY(int _y);
	int czyJestGracz(int _x, int _y);

};


#endif