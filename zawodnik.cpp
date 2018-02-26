#include "zawodnik.h"

Zawodnik::Zawodnik()
{
    this->zarobki = 0.0;
    this->brejkiMaksymalne = 0;
    this->brejkiStupunktowe = 0;
    this->najwyzszyBrejk = 0;
}

Zawodnik::~Zawodnik(){

}

Zawodnik::Zawodnik(string imie, string nazwisko, string narodowosc, tm dataUrodzenia, int najwyzszyBrejk, int iloscBrejkowMaksymalnych,
                   int iloscBrejkowStupunktowych, double lacznaWygrana): Osoba(imie,nazwisko){
    this->narodowosc = narodowosc;
    this->dataUrodzenia = dataUrodzenia;
    this->najwyzszyBrejk = najwyzszyBrejk;
    this->brejkiMaksymalne = iloscBrejkowMaksymalnych;
    this->brejkiStupunktowe = iloscBrejkowStupunktowych;
    this->zarobki = lacznaWygrana;
}

void Zawodnik::dodajZarobki(double suma){
    this->zarobki += suma;
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
        this->brejkiMaksymalne++;
    }
    if(wartosc > this->najwyzszyBrejk){
        this->setNajwyzszyBrejk(wartosc);
    }
    this->brejkiStupunktowe++;
}

Zawodnik::Zawodnik(string imie, string nazwisko): Osoba(imie,nazwisko){

}

Zawodnik::Zawodnik(string imie, string nazwisko,string narodowosc,tm dataUrodzenia) : Osoba(imie,nazwisko){
    this->narodowosc = narodowosc;
    this->dataUrodzenia = dataUrodzenia;
}


void Zawodnik::setNajwyzszyBrejk(int wartosc){
    this->najwyzszyBrejk = wartosc;
}
