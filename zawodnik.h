#ifndef ZAWODNIK_H
#define ZAWODNIK_H
#include "osoba.h"
#include "ctime"

class Zawodnik : public Osoba
{
private:
    string narodowosc;
    tm dataUrodzenia;
    double zarobki;
    int najwyzszyBrejk;
    int brejkiMaksymalne;
    int brejkiStupunktowe;
public:
    Zawodnik();
    Zawodnik(string imie, string nazwisko);
    Zawodnik(string imie, string nazwisko,string narodowosc,tm dataUrodzenia);
    string getNarodowosc();
    void setNarodowosc(string narodowosc);
    tm getDataUrodzenia();
    void setDataUrodzenia(tm dataUrodzenia);
    double getZarobki();
    void dodajZarobki(double suma);
    void dodajBrejkStupunktowy(int wartosc);
    int getBrejkiStupunktowe();
    int getBrejkiMaksymalne();
    int getNajwyzszyBrejk();
    ~Zawodnik();
};

#endif // ZAWODNIK_H
