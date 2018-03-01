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
    vector<Turniej> getTurnieje() const;
    void setTurnieje(const vector<Turniej> &value);
    vector<Zawodnik> getZawodnicy();

    bool dodajZawodnika(Zawodnik zawodnik);
    bool walidujZawodnika(Zawodnik zawodnik);
    void pobierzZawodnikow();
    void zapiszZawodnikow();
    Zawodnik getZawodnik(int index);
    bool setZawodnik(int index, Zawodnik zaw);
    Zawodnik getZawodnikId(int id);
    Zawodnik getZawodnik(string imie, string nazwisko);
    bool sprawdzZawodnika(Zawodnik zawodnik);
    int ustalNajwiekszyIdZawodnika();

    void dodajTurniej(Turniej turniej);
    void pobierzTurnieje();
    void zapiszTurnieje();
    Turniej getTurniej(int index);    
    int ustalNajwiekszyIdTurnieju();
    void pobierzMecze(int idTurnieju);
    void zapiszMecze(int idTurnieju);

};

#endif // KONTENERSNOOKER_H
