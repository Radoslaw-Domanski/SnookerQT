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

vector<Zawodnik> Turniej::getZawodnicy() const
{
    return zawodnicy;
}

void Turniej::setZawodnicy(const vector<Zawodnik> &value)
{
    zawodnicy = value;
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

void Turniej::dodajZawodnika(Zawodnik zawodnik)
{
    this->zawodnicy.push_back(zawodnik);
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

int Turniej::getId() const
{
    return id;
}

void Turniej::setId(int value)
{
    id = value;
}

Turniej::Turniej()
{
    this->setId(0);
    this->mecze = vector<Mecz>();
    this->zawodnicy = vector<Zawodnik>();
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
    this->zawodnicy = vector<Zawodnik>();
    this->setId(id);
}

Turniej::~Turniej()
{

}

