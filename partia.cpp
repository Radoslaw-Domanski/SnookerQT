#include "partia.h"

Partia::Partia()
{
    this->dostepnePunkty = 147;
    this->aktualnyBrejk = 0;
    this->aktualnyZawodnik = true;
    this->dostepneBileCzerwone = 15;
    this->punktyZawodnika1 = 0;
    this->punktyZawodnika2 = 0;
    this->zakonczona = false;
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

void Partia::zerujBrejk(){
    this->aktualnyBrejk = 0;
}

void Partia::faul(int punkty){
    if(this->aktualnyZawodnik){
        this->punktyZawodnika2 += punkty;
    }
    else{
        this->punktyZawodnika1 += punkty;
    }
    this->zerujBrejk();
    this->zmienZawodnika();
}

void Partia::wbijBileCzerwona(){
    if(this->dostepneBileCzerwone > 0){
        if(this->aktualnyZawodnik){
            this->punktyZawodnika1 += 1;
        }
        else{
           this->punktyZawodnika2 += 1;
        }
        this->aktualnyBrejk += 1;
        this->dostepneBileCzerwone--;
        this->dostepnePunkty -= 8;
    }
}

void Partia::wbijBileKolorowa(int punkty){
    if(this->aktualnyZawodnik){
        this->punktyZawodnika1 += punkty;
    }
    else{
        this->punktyZawodnika2 += punkty;
    }
    this->aktualnyBrejk += punkty;
    if(this->dostepneBileCzerwone == 0 && this->dostepnePunkty <= 27){
        this->dostepnePunkty -= punkty;
    }
    if(this->dostepnePunkty == 0){
        this->zakonczPartie();
    }
}

void Partia::zakonczPartie(){
    this->zakonczona = true;
}
