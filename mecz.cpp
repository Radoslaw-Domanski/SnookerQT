#include "mecz.h"

int Mecz::getNr() const
{
    return nr;
}

void Mecz::setNr(int value)
{
    nr = value;
}

int Mecz::getZawodnik1() const
{
    return zawodnik1;
}

void Mecz::setZawodnik1(int value)
{
    zawodnik1 = value;
}

int Mecz::getZawodnik2() const
{
    return zawodnik2;
}

void Mecz::setZawodnik2(int value)
{
    zawodnik2 = value;
}

Mecz::Mecz()
{
    this->partie = vector<Partia>();
}

Mecz::Mecz(int zawodnik1, int zawodnik2, tm dataMeczu, int liczbaPartii, int wynik1, int wynik2, int nr){
    this->partie = vector<Partia>();
    //this->dodajPartie(Partia(0,0,0,147,15,true,false,1));
    this->setZawodnik1(zawodnik1);
    this->setZawodnik2(zawodnik2);
    this->setDataMeczu(dataMeczu);
    this->setLiczbaPartii(liczbaPartii);
    this->setWynik1(wynik1);
    this->setWynik2(wynik2);
    this->setNr(nr);
}

Mecz::~Mecz(){

}

void Mecz::dodajPartie(Partia partia){
    this->partie.push_back(partia);
}

void Mecz::dodajWynik(int zawodnik){
    if(this->getZawodnik1() == zawodnik){
        this->setWynik1(this->getWynik1() + 1);
    }
    else{
        this->setWynik2(this->getWynik2() + 1);
    }
}

tm Mecz::getDataMeczu(){
    return this->dataMeczu;
}

int Mecz::getLiczbaPartii(){
    return this->liczbaPartii;
}

Partia Mecz::getPartia(int index){
    return this->partie[index];
}

vector<Partia> Mecz::getPartie(){
    return this->partie;
}

int Mecz::getWynik1(){
    return this->wynik1;
}

void Mecz::setWynik1(int wynik1){
    this->wynik1 = wynik1;
}

void Mecz::setWynik2(int wynik2){
    this->wynik2 = wynik2;
}

int Mecz::getWynik2(){
    return this->wynik2;
}

void Mecz::setDataMeczu(tm dataMeczu){
    this->dataMeczu = dataMeczu;
}

void Mecz::setLiczbaPartii(int liczbaPartii){
    this->liczbaPartii = liczbaPartii;
}


void Mecz::setPartia(int index, Partia partia){
    this->partie[index].edytujPartie(partia);
}

int Mecz::getZwyciezca(){
    if(this->getWynik1() > this->getWynik2()){
        return this->zawodnik1;
    }
    else if (this->getWynik2() > this->getWynik1()){
        return this->zawodnik2;
    }
    else return -1;
}

vector<int> Mecz::getBrejkiStupunktoweGracza1(){
    vector<int> wektor = vector<int>();
    for(int i = 0; i < this->partie.size(); i++){
        if(this->partie[i].getAktualnyBrejk() >= 100 && this->partie[i].getPunktyZawodnika1() >= 100){
            wektor.push_back(this->partie[i].getAktualnyBrejk());
        }
    }
    return wektor;
}

vector<int> Mecz::getBrejkiStupunktoweGracza2(){
    vector<int> wektor = vector<int>();
    for(int i = 0; i < this->partie.size(); i++){
        if(this->partie[i].getAktualnyBrejk() >= 100 && this->partie[i].getPunktyZawodnika2() >= 100){
            wektor.push_back(this->partie[i].getAktualnyBrejk());
        }
    }
    return wektor;
}
