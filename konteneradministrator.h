#ifndef KONTENERADMINISTRATOR_H
#define KONTENERADMINISTRATOR_H
#include "vector"
#include "administrator.h"
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_print.hpp"
#include "rapidxml/rapidxml_iterators.hpp"
#include "fstream"

using namespace rapidxml;

/**
 * @brief The KontenerAdministrator class
 * klasa przechowujaca administratorow
 * odpowiada za serializacje i deserializacje danych oraz ich edycje
 */
class KontenerAdministrator
{
private:
    /**
     * @brief administratorzy
     * wektor przechowujacy administratorow programu
     */
    vector<Administrator> administratorzy;
public:
    /**
     * @brief KontenerAdministrator
     * domyslny konstruktor
     */
    KontenerAdministrator();
    /**
     * @brief pobierzAdministratorow
     * metoda pobierajaca administratorow z pliku .xml
     */
    void pobierzAdministratorow();
    /**
     * @brief logujAdministratora
     * metoda sprawdzajaca poprawnosc danych podanych przy logowaniu przez uzytkownika programu
     * @param login
     * @param haslo
     * @return powodzenie lub brak powodzenia
     */
    bool logujAdministratora(string login, string haslo);
    /**
     * @brief dodajAdministratora
     * metoda dodaje uzytkownika do systemu
     * @param adm administrator, ktorego chcemy dodac
     * @return zwracane powodzenie lub jego brak
     */
    bool dodajAdministratora(Administrator adm);
    /**
     * @brief sprawdzLoginAdministratora
     * metoda sprawdza czy wystepuje juz administrator o podanym loginie
     * @param login
     * @return zwraca czy login jest juz wykorzystywany czy nie
     */
    bool sprawdzLoginAdministratora(string login);
    /**
     * @brief getAdministratorzy
     * @return
     * metoda zwraca wszystkich administratorow w programie
     */
    vector<Administrator> getAdministratorzy();
    /**
     * @brief walidujAdministratora
     * metoda waliduje dane administratora
     * @param adm administrator, ktorego walidujemy
     * @return poprawne lub nie
     */
    bool walidujAdministratora(Administrator adm);
    /**
     * @brief edytujAdministratora
     * metoda nadpisuje administratora o podanym indeksie
     * @param index
     * @param adm nowy administrator
     * @return zwraca powodzenie lub nie
     */
    bool edytujAdministratora(int index, Administrator adm);
    /**
     * @brief zapiszAdministratorow
     * metoda zapisuje administratorow do pliku .xml
     */
    void zapiszAdministratorow();
    /**
     * @brief getAdministrator
     * metoda zwraca administratora o podanym indeksie
     * @param index
     * @return administrator
     */
    Administrator getAdministrator(int index);
    /**
     * @brief getAdministrator
     * metoda zwraca administratora o podanym loginie
     * @param login
     * @return administrator
     */
    Administrator getAdministrator(string login);
};

#endif // KONTENERADMINISTRATOR_H
