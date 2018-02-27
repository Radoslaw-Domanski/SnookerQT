#ifndef KONTENERSNOOKER_H
#define KONTENERSNOOKER_H
#include "turniej.h"
#include "vector"
#include <zawodnik.h>
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_print.hpp"
#include "rapidxml/rapidxml_iterators.hpp"
#include "fstream"

using namespace rapidxml;

class KontenerSnooker
{
private:
    vector<Turniej> turnieje;
    vector<Zawodnik> zawodnicy;
public:
    KontenerSnooker();
    ~KontenerSnooker();
    bool dodajZawodnika(Zawodnik zawodnik);
    vector<Zawodnik> getZawodnicy();
    bool walidujZawodnika(Zawodnik zawodnik);
    void pobierzZawodnikow();
    void zapiszZawodnikow();
    Zawodnik getZawodnik(int index);
    bool setZawodnik(int index, Zawodnik zaw);
    Zawodnik getZawodnikId(int id);
    Zawodnik getZawodnik(string imie, string nazwisko);
    bool sprawdzZawodnika(Zawodnik zawodnik);
    int ustalNajwiekszyIdZawodnika();
    vector<Turniej> getTurnieje() const;
    void setTurnieje(const vector<Turniej> &value);
    void dodajTurniej(Turniej turniej);
    void pobierzTurnieje();
    Turniej getTurniej(int index);
    void zapiszTurnieje();
    int ustalNajwiekszyIdTurnieju();

};

#endif // KONTENERSNOOKER_H
