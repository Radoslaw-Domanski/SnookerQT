#ifndef OSOBA_H
#define OSOBA_H
#include <iostream>
#include <string>

using namespace std;

class Osoba
{
private:
    string imie;
    string nazwisko;
public:
    string getImie();
    string getNazwisko();
    void setImie(string imie);
    void setNazwisko(string nazwisko);
    Osoba();
    ~Osoba();
    Osoba(string imie, string nazwisko);
};
#endif
