#ifndef ZAWODNIK_H
#define ZAWODNIK_H
#include "osoba.h"
#include "osoba.cpp"
#include "ctime"
#include <string.h>

/**
 * @brief The Zawodnik class
 * klasa przechowujaca i zarzadzajaca informacjami o zawodnikach
 */
class Zawodnik : public Osoba<std::string>
{
private:
    /**
     * @brief id
     * identyfikator zawodnika
     */
    int id;
    /**
     * @brief narodowosc
     * narodowosc zawodnika
     */
    string narodowosc;
    /**
     * @brief dataUrodzenia
     * data urodzenia zawodnika
     */
    tm dataUrodzenia;
    /**
     * @brief zarobki
     * zarobki zawodnika
     */
    double zarobki;
    /**
     * @brief najwyzszyBrejk
     * najwyzszy brejk zawodnika
     */
    int najwyzszyBrejk;
    /**
     * @brief brejkiMaksymalne
     * ilosc brejkow maksymalnych
     */
    int brejkiMaksymalne;
    /**
     * @brief brejkiStupunktowe
     * ilosc brejkow stupunktowych
     */
    int brejkiStupunktowe;
public:
    /**
     * @brief Zawodnik
     * domyslny konstruktor
     */
    Zawodnik();
    /**
     * @brief Zawodnik
     * konstruktor z danymi klasy Osoba
     * @param imie
     * @param nazwisko
     */
    Zawodnik(string imie, string nazwisko);
    /**
     * @brief Zawodnik
     * konstruktor przyjmujacy podstawowe informacje o zawodniku
     * @param imie
     * @param nazwisko
     * @param narodowosc
     * @param dataUrodzenia
     */
    Zawodnik(string imie, string nazwisko,string narodowosc,tm dataUrodzenia);
    /**
     * @brief Zawodnik
     * konstruktor przyjmujacy wszystkie wartosci
     * @param imie
     * @param nazwisko
     * @param narodowosc
     * @param dataUrodzenia
     * @param najwyzszyBrejk
     * @param brejkiMaksymalne
     * @param brejkiStupunktowe
     * @param zarobki
     * @param id
     */
    Zawodnik(string imie, string nazwisko, string narodowosc, tm dataUrodzenia, int najwyzszyBrejk, int brejkiMaksymalne,
             int brejkiStupunktowe, double zarobki,int id);
    /**
     * @brief getNarodowosc
     * metoda zwraca narodowosc zawodnika
     * @return
     */
    string getNarodowosc();
    /**
     * @brief setNarodowosc
     * metoda ustala narodowosc zawodnika
     * @param narodowosc
     */
    void setNarodowosc(string narodowosc);
    /**
     * @brief getDataUrodzenia
     * metoda zwraca date urodzenia zawodnika
     * @return
     */
    tm getDataUrodzenia();
    /**
     * @brief setDataUrodzenia
     * metoda ustala date urodzenia zawodnika
     * @param dataUrodzenia
     */
    void setDataUrodzenia(tm dataUrodzenia);
    /**
     * @brief getZarobki
     * metoda zwraca zarobki zawodnika
     * @return
     */
    double getZarobki();
    /**
     * @brief setZarobki
     * metoda ustala zarobki zawodnika
     * @param suma
     */
    void setZarobki(double suma);
    /**
     * @brief dodajBrejkStupunktowy
     * metoda dodaje nowy brejk stupunktowy zdobyty przez zawodnika
     * @param wartosc
     */
    void dodajBrejkStupunktowy(int wartosc);
    /**
     * @brief getBrejkiStupunktowe
     * metoda pobiera ilosc brejkow stupunktowych zdobytych przez zawodnika
     * @return
     */
    int getBrejkiStupunktowe();
    /**
     * @brief setBrejkiStupunktowe
     * metoda ustala ilosc brejkow stupunktowych zdobytych przez zawodnika
     * @param wartosc
     */
    void setBrejkiStupunktowe(int wartosc);
    /**
     * @brief getBrejkiMaksymalne
     * metoda zwraca ilosc brejkow maksymalnych zdobytych przez uzytkownika
     * @return
     */
    int getBrejkiMaksymalne();
    /**
     * @brief setBrejkiMaksymalne
     * metoda ustala ilosc brejkow maksymalnych zdobytych przez uzytkownika
     * @param wartosc
     */
    void setBrejkiMaksymalne(int wartosc);
    /**
     * @brief getNajwyzszyBrejk
     * metoda pobiera ilosc brejkow maksymalnych zdobytych przez uzytkownika
     * @return
     */
    int getNajwyzszyBrejk();
    /**
     * @brief setNajwyzszyBrejk
     * metoda ustala ilosc brejkow maksymalnych zdobytych przez uzytkownika
     * @param wartosc
     */
    void setNajwyzszyBrejk(int wartosc);
    /**
     * @brief ~Zawodnik
     * domyslny destruktor
     */
    ~Zawodnik();
    /**
     * @brief getId
     * metoda zwraca identyfikator zawodnika
     * @return
     */
    int getId() const;
    /**
     * @brief setId
     * metoda ustala identyfikator zawodnika
     * @param value
     */
    void setId(int value);
};

#endif // ZAWODNIK_H
