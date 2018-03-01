#ifndef KONTENERZAWODNIK_H
#define KONTENERZAWODNIK_H
#include "zawodnik.h"
#include <vector>
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_iterators.hpp"
#include "rapidxml/rapidxml_print.hpp"
#include "rapidxml/rapidxml_utils.hpp"

using namespace rapidxml;

class KontenerZawodnik
{
private:
    vector<Zawodnik> zawodnicy;
public:
    KontenerZawodnik();
    ~KontenerZawodnik();

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

    vector<Zawodnik> getZawodnicy() const;
    void setZawodnicy(const vector<Zawodnik> &value);
};

#endif // KONTENERZAWODNIK_H
