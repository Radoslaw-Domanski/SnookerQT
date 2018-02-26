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
    Zawodnik(string imie, string nazwisko, string narodowosc, tm dataUrodzenia, int najwyzszyBrejk, int iloscBrejkowMaksymalnych,
             int iloscBrejkowStupunktowych, double lacznaWygrana);
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
    void setNajwyzszyBrejk(int wartosc);
    ~Zawodnik();
};

#endif // ZAWODNIK_H
