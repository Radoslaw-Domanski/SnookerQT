#include <string>
#include "Osoba.h"


Osoba::Osoba()
{
    this->imie = "";
    this->nazwisko = "";
}

Osoba::Osoba(string imie, string nazwisko)
{
    this->imie = imie;
    this->nazwisko = nazwisko;
}

Osoba::~Osoba()
{

}

string Osoba::getImie() {
    return this->imie;
}

void Osoba::setImie(string imie) {
    this->imie = imie;
}

string Osoba::getNazwisko() {
    return this->nazwisko;
}

void Osoba::setNazwisko(string nazwisko) {
    this->nazwisko = nazwisko;
}
