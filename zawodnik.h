#ifndef ZAWODNIK_H
#define ZAWODNIK_H
#include "osoba.h"
#include "ctime"

class Zawodnik : public Osoba
{
private:
    int id;
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
    Zawodnik(string imie, string nazwisko, string narodowosc, tm dataUrodzenia, int najwyzszyBrejk, int brejkiMaksymalne,
             int brejkiStupunktowe, double zarobki,int id);
    string getNarodowosc();
    void setNarodowosc(string narodowosc);
    tm getDataUrodzenia();
    void setDataUrodzenia(tm dataUrodzenia);
    double getZarobki();
    void setZarobki(double suma);
    void dodajBrejkStupunktowy(int wartosc);
    int getBrejkiStupunktowe();
    void setBrejkiStupunktowe(int wartosc);
    int getBrejkiMaksymalne();
    void setBrejkiMaksymalne(int wartosc);
    int getNajwyzszyBrejk();
    void setNajwyzszyBrejk(int wartosc);
    ~Zawodnik();
    int getId() const;
    void setId(int value);
};

#endif // ZAWODNIK_H
