#ifndef OSOBA_H
#define OSOBA_H
#include <iostream>
#include <string>

using namespace std;
/**
 * @brief The Osoba class
 * klasa przedstawia podstawowe dane o osobie
 * po niej dziedzicza klasy administrator i zawodnik
 */
class Osoba
{
private:
    /**
     * @brief imie
     * imie osoby
     */
    string imie;
    /**
     * @brief nazwisko
     * nazwisko osoby
     */
    string nazwisko;
public:
    /**
     * @brief getImie
     * @return zwracane jest imie osoby
     */
    string getImie();
    /**
     * @brief getNazwisko
     * @return zwracane jest nazwisko osoby
     */
    string getNazwisko();
    /**
     * @brief setImie
     * @param imie
     * metoda nadpisuje imie osoby
     */
    void setImie(string imie);
    /**
     * @brief setNazwisko
     * @param nazwisko
     * metoda nadpisuje nazwisko osoby
     */
    void setNazwisko(string nazwisko);
    /**
     * @brief Osoba
     * domyslny konstruktor
     */
    Osoba();
    /**
     * @brief ~Osoba
     * domyslny destruktor
     */
    ~Osoba();
    /**
     * @brief Osoba
     * @param imie
     * @param nazwisko
     * konstruktor przyjmujacy imie i nazwisko osoby
     */
    Osoba(string imie, string nazwisko);
};
#endif
