#include "zawodnik.h"

int Zawodnik::getId() const
{
    return id;
}

void Zawodnik::setId(int value)
{
    id = value;
}

Zawodnik::Zawodnik() : Osoba()
{
    this->setId(0);
    this->setDataUrodzenia(tm());
    this->setNarodowosc("");
    this->setZarobki(0.00);
    this->setBrejkiMaksymalne(0);
    this->setBrejkiStupunktowe(0);
    this->setNajwyzszyBrejk(0);
}

Zawodnik::~Zawodnik(){

}

Zawodnik::Zawodnik(string imie, string nazwisko, string narodowosc, tm dataUrodzenia, int najwyzszyBrejk, int brejkiMaksymalne,
                   int brejkiStupunktowe, double zarobki,int id): Osoba(imie,nazwisko){
    this->setNarodowosc(narodowosc);
    this->setDataUrodzenia(dataUrodzenia);
    this->setNajwyzszyBrejk(najwyzszyBrejk);
    this->setBrejkiMaksymalne(brejkiMaksymalne);
    this->setBrejkiStupunktowe(brejkiStupunktowe);
    this->setZarobki(zarobki);
    this->setId(id);
}

void Zawodnik::setZarobki(double suma){
    this->zarobki = suma;
}

int Zawodnik::getBrejkiMaksymalne(){
   return this->brejkiMaksymalne;
}

int Zawodnik::getBrejkiStupunktowe(){
    return this->brejkiStupunktowe;
}

tm Zawodnik::getDataUrodzenia(){
    return this->dataUrodzenia;
}

int Zawodnik::getNajwyzszyBrejk(){
    return this->najwyzszyBrejk;
}

string Zawodnik::getNarodowosc(){
    return this->narodowosc;
}

double Zawodnik::getZarobki(){
    return this->zarobki;
}

void Zawodnik::setDataUrodzenia(tm dataUrodzenia){
    this->dataUrodzenia = dataUrodzenia;
}

void Zawodnik::setNarodowosc(string narodowosc){
    this->narodowosc = narodowosc;
}

void Zawodnik::dodajBrejkStupunktowy(int wartosc){
    if(wartosc == 147){
        this->setBrejkiMaksymalne(this->getBrejkiMaksymalne() + 1);
    }
    if(wartosc > this->getNajwyzszyBrejk()){
        this->setNajwyzszyBrejk(wartosc);
    }
    this->setBrejkiStupunktowe(this->getBrejkiStupunktowe() + 1);
}

void Zawodnik::setBrejkiMaksymalne(int wartosc){
    this->brejkiMaksymalne = wartosc;
}

void Zawodnik::setBrejkiStupunktowe(int wartosc){
    this->brejkiStupunktowe = wartosc;
}

Zawodnik::Zawodnik(string imie, string nazwisko): Osoba(imie,nazwisko){
    this->setZarobki(0.00);
    this->setBrejkiMaksymalne(0);
    this->setBrejkiStupunktowe(0);
    this->setNajwyzszyBrejk(0);
    this->setDataUrodzenia(tm());
    this->setNarodowosc("");
}

Zawodnik::Zawodnik(string imie, string nazwisko,string narodowosc,tm dataUrodzenia) : Osoba(imie,nazwisko){
    this->setNarodowosc(narodowosc);
    this->setDataUrodzenia(dataUrodzenia);
    this->setZarobki(0.00);
    this->setBrejkiMaksymalne(0);
    this->setBrejkiStupunktowe(0);
    this->setNajwyzszyBrejk(0);
    this->setId(0);
}


void Zawodnik::setNajwyzszyBrejk(int wartosc){
    this->najwyzszyBrejk = wartosc;
}
