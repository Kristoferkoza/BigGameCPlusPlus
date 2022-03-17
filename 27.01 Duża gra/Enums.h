#pragma once
#ifndef Enums_HEADER
#define Enums_HEADER

#include<iostream>
#include<string>

enum Rzecz{Wojownik = -5, LZwierze = -3, Kolce = -1, Truskawki = 1, Napoj = 3, Miecz = 5, Zbroja = 8, Diament = 10};
enum RodzajPola{Polana, Woda, Skaly};
enum Kolor{Zielony, Niebieski, Bialy};

inline const char* ToString(Rzecz v)
{
	switch (v)
	{
	case Miecz:   return "Miecz";
	case Zbroja:   return "Zbroja";
	case Napoj: return "Napoj";
	case Truskawki:   return "Truskawki";
	case Diament:   return "Diament";
	case Kolce: return "Kolce";
	case Wojownik:   return "Wojownik";
	case LZwierze:   return "Lesne zwierze";
	default:      return "[Nieznana rzecz]";
	}
}
inline const char* ToString(RodzajPola v)
{
	switch (v)
	{
	case Polana: return "Polana";
	case Woda:   return "Woda";
	case Skaly:   return "Skaly";
	default:      return "[Nieznane pole]";
	}
}
inline const char ToChar(Rzecz v)
{
	switch (v)
	{
	case Miecz:   return 'M';
	case Zbroja:   return 'Z';
	case Napoj: return 'N';
	case Truskawki:   return 'T';
	case Diament:   return 'D';
	case Kolce: return 'K';
	case Wojownik:   return 'W';
	case LZwierze:   return 'L';
	default:      return '0';
	}
}
inline const char ToChar(RodzajPola v)
{
	switch (v)
	{
	case Polana:   return 'P';
	case Woda:   return 'W';
	case Skaly: return 'S';
	default:      return '0';
	}
}
#endif
