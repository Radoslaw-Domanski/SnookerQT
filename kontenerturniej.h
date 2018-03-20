#ifndef KONTENERTURNIEJ_H
#define KONTENERTURNIEJ_H
#include "zawodnik.h"
#include <vector>
#include "turniej.h"
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_iterators.hpp"
#include "rapidxml/rapidxml_print.hpp"
#include "rapidxml/rapidxml_utils.hpp"

using namespace rapidxml;

class KontenerTurniej
{
private:
    vector<Turniej> turnieje;
public:
    KontenerTurniej();
    ~KontenerTurniej();
    void dodajTurniej(Turniej turniej);
    void pobierzTurnieje();
    void zapiszTurnieje();
    Turniej getTurniej(int index);
    int ustalNajwiekszyIdTurnieju();
    void pobierzMecze(int idTurnieju);
    void zapiszMecze(int indexTurnieju);
    vector<Turniej> getTurnieje() const;
    void setTurnieje(const vector<Turniej> &value);
    void aktualizujPartie(int indexTurnieju,int indexMeczu,int indexPartii, Partia partia);
    void aktualizujWynikMeczu(int indexTurnieju, int indexMeczu,Partia partia);
    void dodajPartie(int indexTurnieju, int indexMeczu);
};

#endif // KONTENERTURNIEJ_H
