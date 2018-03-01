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
    vector<int> zawodnicy;
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
    vector<Mecz> getMecze() const;
    void setMecze(const vector<Mecz> &value);
    int getId() const;
    void setId(int value);

    void ustalNajwyzszyBrejkTurnieju();
    void dodajMecz(Mecz mecz);
    Mecz getMecz(int index);
    void dodajZawodnika(int id);
    int ustalNajwyzszyNrMeczu();

    vector<int> getZawodnicy() const;
    void setZawodnicy(const vector<int> &value);
};

#endif // TURNIEJ_H
