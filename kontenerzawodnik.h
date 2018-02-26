#ifndef KONTENERZAWODNIK_H
#define KONTENERZAWODNIK_H
#include "vector"
#include <zawodnik.h>
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_print.hpp"
#include "rapidxml/rapidxml_iterators.hpp"
#include "fstream"

using namespace rapidxml;

class KontenerZawodnik
{
private:
    vector<Zawodnik> zawodnicy;
public:
    KontenerZawodnik();
    ~KontenerZawodnik();
    bool dodajZawodnika(Zawodnik zawodnik);
    vector<Zawodnik> getZawodnicy();
    bool walidujZawodnika(Zawodnik zawodnik);
    void pobierzZawodnikow();
    void zapiszZawodnikow();
    Zawodnik getZawodnik(int index);
    Zawodnik getZawodnik(string imie, string nazwisko);
    bool sprawdzZawodnika(Zawodnik zawodnik);
    /*+edytujZawodnika(int index,Administrator adm): bool*/
};

#endif // KONTENERZAWODNIK_H
