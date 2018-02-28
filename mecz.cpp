#include "mecz.h"

int Mecz::getNr() const
{
    return nr;
}

void Mecz::setNr(int value)
{
    nr = value;
}

Mecz::Mecz()
{
    this->partie = vector<Partia>();
}

Mecz::Mecz(Zawodnik zawodnik1, Zawodnik zawodnik2, tm dataMeczu, int liczbaPartii, int wynik1, int wynik2, int nr){
    this->partie = vector<Partia>();
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

void Mecz::dodajWynik(Zawodnik zawodnik){
    if(this->zawodnik1.getNazwisko() == zawodnik.getNazwisko() && this->zawodnik1.getImie() == zawodnik.getImie()){
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

Zawodnik Mecz::getZawodnik1(){
    return this->zawodnik1;
}

void Mecz::setZawodnik1(Zawodnik zawodnik1){
    this->zawodnik1 = zawodnik1;
}

void Mecz::setZawodnik2(Zawodnik zawodnik2){
    this->zawodnik2 = zawodnik2;
}

Zawodnik Mecz::getZawodnik2(){
    return this->zawodnik2;
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

Zawodnik Mecz::getZwyciezca(){
    if(this->getWynik1() > this->getWynik2()){
        return this->zawodnik1;
    }
    else if (this->getWynik2() > this->getWynik1()){
        return this->zawodnik2;
    }
    else return Zawodnik();
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
