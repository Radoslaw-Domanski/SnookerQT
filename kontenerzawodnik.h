#ifndef KONTENERZAWODNIK_H
#define KONTENERZAWODNIK_H
#include "zawodnik.h"
#include <vector>
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_iterators.hpp"
#include "rapidxml/rapidxml_print.hpp"
#include "rapidxml/rapidxml_utils.hpp"

using namespace rapidxml;
/**
 * @brief The KontenerZawodnik class
 * klasa przechowuje i zarzadza zawodnikami utworzonymi przez administratorow programu
 */
class KontenerZawodnik
{
private:
    /**
     * @brief zawodnicy
     * wektor przechowujacy zawodnikow
     */
    vector<Zawodnik> zawodnicy;
public:
    /**
     * @brief KontenerZawodnik
     * domyslny konstruktor
     */
    KontenerZawodnik();
    /**
     * @brief ~KontenerZawodnik
     * domyslny destruktor
     */
    ~KontenerZawodnik();
    /**
     * @brief dodajZawodnika
     * metoda dodaje podanego uzytkownika do wektora
     * @param zawodnik
     * @return
     * zwraca powodzenie lub nie
     */
    bool dodajZawodnika(Zawodnik zawodnik);
    /**
     * @brief walidujZawodnika
     * metoda waliduje poprawnosc danych podanego uzytkownika
     * @param zawodnik
     * @return
     * poprawne lub nie
     */
    bool walidujZawodnika(Zawodnik zawodnik);
    /**
     * @brief pobierzZawodnikow
     * metoda pobiera zawodnikow z pliku .xml
     */
    void pobierzZawodnikow();
    /**
     * @brief zapiszZawodnikow
     * metoda zapisuje uzytkownikow do pliku .xml
     */
    void zapiszZawodnikow();
    /**
     * @brief getZawodnik
     * metoda zwraca zawodnika z wektora o podanym indeksie
     * @param index
     * @return zawodnik
     */
    Zawodnik getZawodnik(int index);
    /**
     * @brief setZawodnik
     * metoda nadpisuje zawodnika w wektorze o podanym indeksie
     * @param index
     * @param zaw zawodnik
     * @return
     * zwraca powodzenie lub nie
     */
    bool setZawodnik(int index, Zawodnik zaw);
    /**
     * @brief getZawodnikId
     * metoda zwraca zawodnika o podanym identyfikatorze
     * @param id
     * @return zawodnik
     */
    Zawodnik getZawodnikId(int id);
    /**
     * @brief getZawodnik
     * metoda zwraca zawodnika o podanym imieniu i nazwisku
     * @param imie
     * @param nazwisko
     * @return zawodnik
     */
    Zawodnik getZawodnik(string imie, string nazwisko);
    /**
     * @brief sprawdzZawodnika
     * metoda weryfikuje poprawnosc danych uzytkownika
     * @param zawodnik
     * @return poprawne lub nie
     */
    bool sprawdzZawodnika(Zawodnik zawodnik);
    /**
     * @brief ustalNajwiekszyIdZawodnika
     * metoda zwraca najwiekszy obecny identyfikator zawodnika w programie
     * @return najwiekszy identyfikator
     */
    int ustalNajwiekszyIdZawodnika();
    /**
     * @brief getZawodnicy
     * metoda zwraca wektor wszystkich zawodnikow w programie
     * @return
     */
    vector<Zawodnik> getZawodnicy() const;
    /**
     * @brief setZawodnicy
     * metoda nadpisuje wektor zawodnikow nowym wektorem
     * @param value
     */
    void setZawodnicy(const vector<Zawodnik> &value);
};

#endif // KONTENERZAWODNIK_H
