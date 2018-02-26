#ifndef TURNIEJ_H
#define TURNIEJ_H
#include "mecz.h"
#include "string"

class Turniej
{
private:
    int id;
    string nazwa;
    string sponsor;
    string miejsce;
    double pulaNagrod;
    int najwyzszyBrejkTurnieju;
    int liczbaZawodnikow;
    vector<Zawodnik> zawodnicy;
    vector<Mecz> mecze;
public:
    Turniej();
    Turniej(string nazwa,string sponsor, string miejsce, double pulaNagrod,int najwyzszyBrejkTurnieju, int liczbaZawodnikow, int id);
    ~Turniej();
    string getSponsor() const;
    void setSponsor(const string &value);
    string getNazwa() const;
    void setNazwa(const string &value);
    string getMiejsce() const;
    void setMiejsce(const string &value);
    double getPulaNagrod() const;
    void setPulaNagrod(double value);
    int getNajwyzszyBrejkTurnieju() const;
    void setNajwyzszyBrejkTurnieju(int value);
    int getLiczbaZawodnikow() const;
    void setLiczbaZawodnikow(int value);
    vector<Zawodnik> getZawodnicy() const;
    void setZawodnicy(const vector<Zawodnik> &value);
    vector<Mecz> getMecze() const;
    void setMecze(const vector<Mecz> &value);
    void ustalNajwyzszyBrejkTurnieju();
    void dodajMecz(Mecz mecz);
    void dodajZawodnika(Zawodnik zawodnik);
    int getId() const;
    void setId(int value);
};

#endif // TURNIEJ_H
