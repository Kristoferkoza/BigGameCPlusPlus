#include "Plansza.h"
#include "Rozgrywka.h"
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    srand(time(NULL));

    //SetConsoleTextAttribute(hOut, FOREGROUND_RED);
    ////SetConsoleTextAttribute(hOut, BACKGROUND_BLUE);
    //cout << "Test";

    /*SetConsoleTextAttribute(hOut,
        BACKGROUND_RED);
    cout << "Red     " << flush;
    SetConsoleTextAttribute(hOut,
        BACKGROUND_RED |
        BACKGROUND_INTENSITY);
    cout << "Red     " << endl;

    SetConsoleTextAttribute(hOut,
        BACKGROUND_GREEN);
    cout << "Green   " << flush;
    SetConsoleTextAttribute(hOut,
        BACKGROUND_GREEN |
        BACKGROUND_INTENSITY);
    cout << "Green   " << endl;

    SetConsoleTextAttribute(hOut,
        BACKGROUND_BLUE);
    cout << "Blue    " << flush;
    SetConsoleTextAttribute(hOut,
        BACKGROUND_BLUE |
        BACKGROUND_INTENSITY);
    cout << "Blue    " << endl;

    SetConsoleTextAttribute(hOut,
        BACKGROUND_RED |
        BACKGROUND_GREEN);
    cout << "Yellow  " << flush;
    SetConsoleTextAttribute(hOut,
        BACKGROUND_RED |
        BACKGROUND_GREEN |
        BACKGROUND_INTENSITY);
    cout << "Yellow  " << endl;

    SetConsoleTextAttribute(hOut,
        BACKGROUND_GREEN |
        BACKGROUND_BLUE);
    cout << "Cyan    " << flush;
    SetConsoleTextAttribute(hOut,
        BACKGROUND_GREEN |
        BACKGROUND_BLUE |
        BACKGROUND_INTENSITY);
    cout << "Cyan    " << endl;

    SetConsoleTextAttribute(hOut,
        BACKGROUND_BLUE |
        BACKGROUND_RED);
    cout << "Magenta " << flush;
    SetConsoleTextAttribute(hOut,
        BACKGROUND_BLUE |
        BACKGROUND_RED |
        BACKGROUND_INTENSITY);
    cout << "Magenta " << endl;

    SetConsoleTextAttribute(hOut,
        BACKGROUND_RED |
        BACKGROUND_GREEN |
        BACKGROUND_BLUE);
    cout << "White   " << flush;
    SetConsoleTextAttribute(hOut,
        BACKGROUND_RED |
        BACKGROUND_GREEN |
        BACKGROUND_BLUE |
        BACKGROUND_INTENSITY);
    cout << "White   " << endl;*/

    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

    /*Plansza plansza1(20);
    plansza1.wyswietlPlansze();
    cout << "test";
    Sleep(5000);
    system("cls");

    plansza1.wyswietlPlansze();*/

    Rozgrywka rozgrywka1(20, "Adam", "Kamil");
    rozgrywka1.startRozgrywki();

    return 0;
}


