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
template <typename T>
class Osoba
{
private:
    /**
     * @brief imie
     * imie osoby
     */
    T imie;
    /**
     * @brief nazwisko
     * nazwisko osoby
     */
    T nazwisko;
public:
    /**
     * @brief getImie
     * @return zwracane jest imie osoby
     */
    T getImie();
    /**
     * @brief getNazwisko
     * @return zwracane jest nazwisko osoby
     */
    T getNazwisko();
    /**
     * @brief setImie
     * @param imie
     * metoda nadpisuje imie osoby
     */
    void setImie(T imie);
    /**
     * @brief setNazwisko
     * @param nazwisko
     * metoda nadpisuje nazwisko osoby
     */
    void setNazwisko(T nazwisko);
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
    Osoba(T imie, T nazwisko);
};
#endif
