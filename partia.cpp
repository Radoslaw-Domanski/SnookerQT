#include "partia.h"

Partia::Partia()
{    
    this->setPunktyZawodnika1(0);
    this->setPunktyZawodnika2(0);
    this->setAktualnyBrejk(0);
    this->setDostepnePunkty(147);
    this->setDostepneBileCzerwone(15);
    this->setAktualnyZawodnik(true);
    this->setZakonczona(false);
}

Partia:: Partia(int punkty1, int punkty2, int aktualnyBrejk, int dostepnePunkty, int dostepneBileCzerwone, bool aktualnyZawodnik, bool zakonczona){
    this->setPunktyZawodnika1(punkty1);
    this->setPunktyZawodnika2(punkty2);
    this->setAktualnyBrejk(aktualnyBrejk);
    this->setDostepnePunkty(dostepnePunkty);
    this->setDostepneBileCzerwone(dostepneBileCzerwone);
    this->setAktualnyZawodnik(aktualnyZawodnik);
    this->setZakonczona(zakonczona);
}

Partia::~Partia(){

}

int Partia::getPunktyZawodnika1(){
    return this->punktyZawodnika1;
}

int Partia::getPunktyZawodnika2(){
    return this->punktyZawodnika2;
}

void Partia::zmienZawodnika(){
    this->aktualnyZawodnik = !this->aktualnyZawodnik;
}

void Partia::faul(int punkty){
    if(this->getAktualnyZawodnik()){
        this->setPunktyZawodnika2(this->getPunktyZawodnika2() + punkty);
    }
    else{
        this->setPunktyZawodnika1(this->getPunktyZawodnika1() + punkty);
    }
    this->setAktualnyBrejk(0);
    this->zmienZawodnika();
}

void Partia::wbijBileCzerwona(){
    if(this->getDostepneBileCzerwone() > 0){
        if(this->getAktualnyZawodnik()){
            this->setPunktyZawodnika1( this->getPunktyZawodnika1() + 1) ;
        }
        else{
           this->setPunktyZawodnika2( this->getPunktyZawodnika2() + 1) ;
        }
        this->setAktualnyBrejk(this->getAktualnyBrejk() + 1);
        this->setDostepneBileCzerwone(this->getDostepneBileCzerwone() - 1);
        this->setDostepnePunkty(this->getDostepnePunkty() - 8);
    }
}

void Partia::wbijBileKolorowa(int punkty){
    if(this->getAktualnyZawodnik()){
        this->setPunktyZawodnika1(this->getPunktyZawodnika1() + punkty);
    }
    else{
        this->setPunktyZawodnika2(this->getPunktyZawodnika2() + punkty);
    }
    this->setAktualnyBrejk(this->getAktualnyBrejk() + punkty);
    if(this->getDostepneBileCzerwone() == 0 && this->getDostepnePunkty() <= 27){
        this->setDostepnePunkty(this->getDostepnePunkty() - punkty);
    }
    if(this->getDostepnePunkty() == 0){
        this->zakonczPartie();
    }
}

void Partia::zakonczPartie(){
    this->setZakonczona(true);
}

int Partia::getAktualnyBrejk(){
    return this->aktualnyBrejk;
}

int Partia::getDostepnePunkty(){
    return this->dostepnePunkty;
}

int Partia::getDostepneBileCzerwone(){
    return this->dostepneBileCzerwone;
}

bool Partia::getAktualnyZawodnik(){
    return this->aktualnyZawodnik;
}

bool Partia::getZakonczona(){
    return this->zakonczona;
}

void Partia::setPunktyZawodnika1(int punkty){
    this->punktyZawodnika1 = punkty;
}

void Partia::setPunktyZawodnika2(int punkty){
    this->punktyZawodnika2 = punkty;
}

void Partia::setAktualnyBrejk(int punkty){
    this->aktualnyBrejk = punkty;
}

void Partia::setDostepnePunkty(int punkty){
    this->dostepnePunkty = punkty;
}

void Partia::setDostepneBileCzerwone(int bile){
    this->dostepneBileCzerwone = bile;
}

void Partia::setAktualnyZawodnik(bool zawodnik){
    this->aktualnyZawodnik = zawodnik;
}

void Partia::setZakonczona(bool zakonczona){
    this->zakonczona = zakonczona;
}

void Partia::edytujPartie(Partia partia){
    this->setPunktyZawodnika1(partia.getPunktyZawodnika1());
    this->setPunktyZawodnika2(partia.getPunktyZawodnika2());
    this->setAktualnyBrejk(partia.getAktualnyBrejk());
    this->setDostepnePunkty(partia.getDostepnePunkty());
    this->setDostepneBileCzerwone(partia.getDostepneBileCzerwone());
    this->setAktualnyZawodnik(partia.getAktualnyZawodnik());
    this->setZakonczona(partia.getZakonczona());
}
