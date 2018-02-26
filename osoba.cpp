#include <string>
#include "Osoba.h"


Osoba::Osoba()
{
    this->setImie("");
    this->setNazwisko("");
}

Osoba::Osoba(string imie, string nazwisko)
{
    this->setImie(imie);
    this->setNazwisko(nazwisko);
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
