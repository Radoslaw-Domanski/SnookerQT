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
/**
 * @brief The KontenerTurniej class
 * klasa przechowuje turnieje utworzone przez administratorow programu
 */
class KontenerTurniej
{
private:
    /**
     * @brief turnieje
     * wektor zawierajacy turnieje
     */
    vector<Turniej> turnieje;
public:
    /**
     * @brief KontenerTurniej
     * domyslny konstruktor
     */
    KontenerTurniej();
    /**
     * @brief ~KontenerTurniej
     * domyslny denstruktor
     */
    ~KontenerTurniej();
    /**
     * @brief dodajTurniej
     * metoda dodaje turniej do wektora
     * @param turniej
     */
    void dodajTurniej(Turniej turniej);
    /**
     * @brief pobierzTurnieje
     * metoda pobiera wszystkie turnieje z pliku .xml
     */
    void pobierzTurnieje();
    /**
     * @brief zapiszTurnieje
     * metoda zapisuje turnieje do pliku .xml
     */
    void zapiszTurnieje();
    /**
     * @brief getTurniej
     * metoda zwraca turniej z wektora o podanym indeksie
     * @param index
     * @return turniej
     */
    Turniej getTurniej(int index);
    /**
     * @brief ustalNajwiekszyIdTurnieju
     * metoda zwraca najwiekszy identyfikator turnieju z wektora turniejow
     * @return najwiekszy identyfikator turnieju
     */
    int ustalNajwiekszyIdTurnieju();
    /**
     * @brief pobierzMecze
     * metoda pobiera mecze z pliku .xml dla turnieju o podanym identyfikatorze
     * @param idTurnieju
     */
    void pobierzMecze(int idTurnieju);
    /**
     * @brief zapiszMecze
     * metoda zapisuje mecze z pliku .xml dla turnieju o podanym indeksie
     * @param indexTurnieju
     */
    void zapiszMecze(int indexTurnieju);
    /**
     * @brief getTurnieje
     * metoda zwraca wektor wszystkich turniejow
     * @return
     */
    vector<Turniej> getTurnieje() const;
    /**
     * @brief setTurnieje
     * metoda nadpisuje wektor turniejow wlasnych wektorem
     * @param value
     */
    void setTurnieje(const vector<Turniej> &value);
    /**
     * @brief aktualizujPartie
     * metoda aktualizuje partie meczu dla podanego turnieju o podanych indeksach: turnieju ,meczu i partii
     * @param indexTurnieju
     * @param indexMeczu
     * @param indexPartii
     * @param partia
     */
    void aktualizujPartie(int indexTurnieju,int indexMeczu,int indexPartii, Partia partia);
    /**
     * @brief aktualizujWynikMeczu
     * metoda aktualizuje wynik meczu dla turnieju o podanych indeksach: turnieju i meczu i okreslonej partii
     * @param indexTurnieju
     * @param indexMeczu
     * @param partia
     */
    void aktualizujWynikMeczu(int indexTurnieju, int indexMeczu,Partia partia);
    /**
     * @brief dodajPartie
     * metoda dodaje nowa partie do meczu dla podanego indeksu turnieju i meczu
     * @param indexTurnieju
     * @param indexMeczu
     */
    void dodajPartie(int indexTurnieju, int indexMeczu);
    /**
     * @brief losujNastepnaRunde
     * metoda losuje pary dla nastepnej rundy o okreslonym indeksie turnieju
     * @param indexTurnieju
     */
    void losujNastepnaRunde(int indexTurnieju);
    /**
     * @brief ustalNajwiekszyBrejkTurnieju
     * metoda ustala najwiekszy brejk turnieju z aktualnie rozegranych partii dla okreslonego turnieju
     * @param indexTurnieju
     */
    void ustalNajwiekszyBrejkTurnieju(int indexTurnieju);
};

#endif // KONTENERTURNIEJ_H
