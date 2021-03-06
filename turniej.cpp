#include "turniej.h"

string Turniej::getSponsor() const
{
    return sponsor;
}

void Turniej::setSponsor(const string &value)
{
    sponsor = value;
}

string Turniej::getNazwa() const
{
    return nazwa;
}

void Turniej::setNazwa(const string &value)
{
    nazwa = value;
}

string Turniej::getMiejsce() const
{
    return miejsce;
}

void Turniej::setMiejsce(const string &value)
{
    miejsce = value;
}

double Turniej::getPulaNagrod() const
{
    return pulaNagrod;
}

void Turniej::setPulaNagrod(double value)
{
    pulaNagrod = value;
}

int Turniej::getNajwyzszyBrejkTurnieju() const
{
    return najwyzszyBrejkTurnieju;
}

void Turniej::setNajwyzszyBrejkTurnieju(int value)
{
    najwyzszyBrejkTurnieju = value;
}

int Turniej::getLiczbaZawodnikow() const
{
    return liczbaZawodnikow;
}

void Turniej::setLiczbaZawodnikow(int value)
{
    liczbaZawodnikow = value;
}

vector<Mecz> Turniej::getMecze() const
{
    return mecze;
}

void Turniej::setMecze(const vector<Mecz> &value)
{
    mecze = value;
}

void Turniej::ustalNajwyzszyBrejkTurnieju()
{
    int aktualnyMax = this->getNajwyzszyBrejkTurnieju();
    for(int i = 0; i < this->mecze.size(); i++){
        vector<int> punkty1 = mecze[i].getBrejkiStupunktoweGracza1();
        vector<int> punkty2 = mecze[i].getBrejkiStupunktoweGracza2();

        for(int j = 0; j < punkty1.size(); j++){
            if(punkty1[j] > aktualnyMax){
                aktualnyMax = punkty1[j];
            }
        }

        for(int j = 0; j < punkty2.size(); j++){
            if(punkty2[j] > aktualnyMax){
                aktualnyMax = punkty2[j];
            }
        }
        punkty1.clear();
        punkty2.clear();
    }
    this->setNajwyzszyBrejkTurnieju(aktualnyMax);
}

void Turniej::dodajMecz(Mecz mecz)
{
    this->mecze.push_back(mecz);
}

Mecz Turniej::getMecz(int index)
{
    return this->mecze[index];
}

void Turniej::dodajZawodnika(int id)
{
    this->zawodnicy.push_back(id);
}

int Turniej::ustalNajwyzszyNrMeczu()
{
    int nr = this->mecze[0].getNr();
    for(int i = 1; i < this->mecze.size();i++){
        if(mecze[i].getNr() > nr){
            nr = mecze[i].getNr();
        }
    }
    return nr;
}

void Turniej::losujDrabinkeTurnieju()
{
    if(this->zawodnicy.size() == 2){
        struct tm  local_time;

        this->mecze.push_back(Mecz(this->zawodnicy[0],this->zawodnicy[1],local_time,5));
        this->mecze[0].dodajPartie(Partia(0,0,0,147,15,true,false,1));
    }
    else if(this->zawodnicy.size() == 4){
        struct tm  local_time;
        time_t t = time(0);   // get time now
        struct tm *now = localtime( & t );
        local_time.tm_year = now->tm_year;
        local_time.tm_mon = now->tm_mon;
        local_time.tm_mday = now->tm_mday;
        vector<int> zawodnicy = this->getZawodnicy();
        int losowyIndex = rand() % zawodnicy.size();
        int i = zawodnicy[losowyIndex];
        zawodnicy.erase(zawodnicy.begin() + losowyIndex);
        losowyIndex = rand() % zawodnicy.size();
        int j = zawodnicy[losowyIndex];
        zawodnicy.erase(zawodnicy.begin() + losowyIndex);

        this->mecze.push_back(Mecz(i,j,local_time,5,0,0,1));
        this->mecze.push_back(Mecz(zawodnicy[0],zawodnicy[1],local_time,5,0,0,2));
        this->mecze[0].dodajPartie(Partia(0,0,0,147,15,true,false,1));
        this->mecze[1].dodajPartie(Partia(0,0,0,147,15,true,false,1));
    }
}

void Turniej::losujNastepnaRunde()
{
    //vector<int> zawodnicy = this->getZawodnicy();
    struct tm  local_time;
    time_t t = time(0);   // get time now
    struct tm *now = localtime( & t );
    local_time.tm_year = now->tm_year;
    local_time.tm_mon = now->tm_mon;
    local_time.tm_mday = now->tm_mday;
    vector<int> nowi = vector<int>();
    // 1 runda
    if(this->getLiczbaZawodnikow() == 16){
        int i = -1;
        if(mecze.size() == 8){
            i=0;
        }
        else if(mecze.size() == 12){
            i=8;
        }
        else if(mecze.size() == 14){
            i=12;
        }

        if( i != -1){
            for(i; i < mecze.size();i++){
                if(this->mecze[i].getWynik1() > this->mecze[i].getWynik2()){
                    nowi.push_back(this->mecze[i].getZawodnik1());
                }
                else if(this->mecze[i].getWynik1() < this->mecze[i].getWynik2()){
                    nowi.push_back(this->mecze[i].getZawodnik2());
                }
            }
            for(int j = 0 ; j < nowi.size();j=j+2){
               this->dodajMecz(Mecz(nowi[j],nowi[j+1],local_time,5,0,0,this->getMecze().size()+1));
            }
        }
    }
    else if(this->getLiczbaZawodnikow() == 8){
        int i = -1;
        if(mecze.size() == 4){
            i=0;
        }
        else if(mecze.size() == 6){
            i=4;
        }

        if( i != -1){
            for(i; i < mecze.size();i++){
                if(this->mecze[i].getWynik1() > this->mecze[i].getWynik2()){
                    nowi.push_back(this->mecze[i].getZawodnik1());
                }
                else if(this->mecze[i].getWynik1() < this->mecze[i].getWynik2()){
                    nowi.push_back(this->mecze[i].getZawodnik2());
                }
            }
            for(int j = 0 ; j < nowi.size();j=j+2){
               this->dodajMecz(Mecz(nowi[j],nowi[j+1],local_time,5,0,0,this->getMecze().size()+1));
            }
        }
    }
    else if(this->getLiczbaZawodnikow() == 4){
        int i = -1;
        if(mecze.size() == 2){
            i=0;
        }

        if( i != -1){
            for(i; i < mecze.size();i++){
                if(this->mecze[i].getWynik1() > this->mecze[i].getWynik2()){
                    nowi.push_back(this->mecze[i].getZawodnik1());
                }
                else if(this->mecze[i].getWynik1() < this->mecze[i].getWynik2()){
                    nowi.push_back(this->mecze[i].getZawodnik2());
                }
            }
            for(int j = 0 ; j < nowi.size();j=j+2){
               this->dodajMecz(Mecz(nowi[j],nowi[j+1],local_time,5,0,0,this->getMecze().size()+1));
            }
        }
    }
}

int Turniej::getId() const
{
    return id;
}

void Turniej::setId(int value)
{
    id = value;
}

vector<int> Turniej::getZawodnicy() const
{
    return zawodnicy;
}

void Turniej::setZawodnicy(const vector<int> &value)
{
    zawodnicy = value;
}

void Turniej::aktualizujPartie(int indexMeczu, int indexPartii, Partia partia)
{
    Mecz mecz = this->getMecz(indexMeczu);
    int ilosc = mecz.getPartie().size() + 1;
    this->mecze[indexMeczu].setPartia(indexPartii,partia);
    if(mecz.getWynik1() < ( mecz.getLiczbaPartii()/2  + 1 ) &&
       mecz.getWynik2() < ( mecz.getLiczbaPartii()/2  + 1 )   ){
        this->mecze[indexMeczu].dodajPartie(Partia(0,0,0,147,15,true,false,ilosc));
    }
}

void Turniej::aktualizujWynikMeczu(int indexMeczu, Partia partia)
{
    if(partia.getPunktyZawodnika1() > partia.getPunktyZawodnika2()){
        this->mecze[indexMeczu].setWynik1(this->mecze[indexMeczu].getWynik1() + 1);
    }
    else if(partia.getPunktyZawodnika2() > partia.getPunktyZawodnika1()){
        this->mecze[indexMeczu].setWynik2(this->mecze[indexMeczu].getWynik2() + 1);
    }
}

bool Turniej::sprawdzNastepnaRunde()
{
    for(int i = 0; i < this->getMecze().size();i++){
        if(this->mecze[i].getWynik1() < ( this->mecze[i].getLiczbaPartii()/2  + 1 ) &&
           this->mecze[i].getWynik2() < ( this->mecze[i].getLiczbaPartii()/2  + 1 )   ){
            return false;
        }
    }
    return true;
}

void Turniej::dodajPartie(int indexMeczu)
{
    this->mecze[indexMeczu].dodajPartie(Partia(0,0,0,147,15,true,false,this->mecze[indexMeczu].getPartie().size()+ 1));
}

Turniej::Turniej()
{
    this->setId(0);
    this->mecze = vector<Mecz>();
    this->zawodnicy = vector<int>();
}

Turniej::Turniej(string nazwa, string sponsor, string miejsce, double pulaNagrod, int najwyzszyBrejkTurnieju, int liczbaZawodnikow, int id)
{
    this->setNazwa(nazwa);
    this->setSponsor(sponsor);
    this->setMiejsce(miejsce);
    this->setPulaNagrod(pulaNagrod);
    this->setNajwyzszyBrejkTurnieju(najwyzszyBrejkTurnieju);
    this->setLiczbaZawodnikow(liczbaZawodnikow);
    this->mecze = vector<Mecz>();
    this->zawodnicy = vector<int>();
    this->setId(id);
}

Turniej::~Turniej()
{

}

