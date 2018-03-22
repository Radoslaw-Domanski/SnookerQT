#ifndef MECZ_H
#define MECZ_H
#include "ctime"
#include "vector"
#include "partia.h"
#include "zawodnik.h"
/**
 * @brief The Mecz class
 * klasa przechowujaca i zarzadzajaca informacjami o meczu
 * */
class Mecz
{

private:
    /**
     * @brief wynik1
     * liczba wygranych partii przez zawodnika 1
     */
    int wynik1;
    /**
     * @brief wynik2
     * liczba wygranych partii przez zawodnika 2
     */
    int wynik2;
    /**
     * @brief liczbaPartii
     * maksymalna liczba partii do rozegrania
     */
    int liczbaPartii;
    /**
     * @brief dataMeczu
     * data rozegrania meczu
     */
    tm dataMeczu;
    /**
     * @brief partie
     * wektor przechowujacy rozegrane partie w meczu
     */
    vector<Partia> partie;
    /**
     * @brief zawodnik1
     * identyfikator zawodnika 1
     */
    int zawodnik1;
    /**
     * @brief zawodnik2
     * identyfikator zawodnika 2
     */
    int zawodnik2;
    /**
     * @brief nr
     * nr meczu w turnieju
     */
    int nr;
public:
    /**
     * @brief Mecz
     * domyslny konstruktor
     */
    Mecz();
    /**
     * @brief Mecz
     * konstruktor przyjmujacy identyfikatory zawodnikow, date meczu, liczbe partii, nr meczu w turnieju i wynik meczu
     * @param zawodnik1
     * @param zawodnik2
     * @param dataMeczu
     * @param liczbaPartii
     * @param wynik1
     * @param wynik2
     * @param nr
     */
    Mecz(int zawodnik1, int zawodnik2, tm dataMeczu, int liczbaPartii,
         int wynik1 = 0, int wynik2 = 0, int nr = 0);
    /**
     * @brief ~Mecz
     * domyslny destruktor
     */
    ~Mecz();
    /**
     * @brief getWynik1
     * metoda zwraca liczbe partii zdobytych przez zawodnika 1
     * @return
     */
    int getWynik1();
    /**
     * @brief setWynik1
     * metoda ustawia liczbe partii zdobytych przez zawodnika 1
     * @param wynik1
     */
    void setWynik1(int wynik1);
    /**
     * @brief getWynik2
     * metoda zwraca liczbe partii zdobytych przez zawodnika 2
     * @return
     */
    int getWynik2();
    /**
     * @brief setWynik2
     * metoda ustala liczbe partii zdobytych przez zawodnika 2
     * @param wynik2
     */
    void setWynik2(int wynik2);
    /**
     * @brief getLiczbaPartii
     * metoda pobiera maksymalna liczbe partii do rozegrania
     * @return
     */
    int getLiczbaPartii();
    /**
     * @brief setLiczbaPartii
     * metoda ustala maksymalna liczbe partii do rozegrania
     * @param liczbaPartii
     */
    void setLiczbaPartii(int liczbaPartii);
    /**
     * @brief getDataMeczu
     * metoda pobiera date rozegrania meczu
     * @return
     */
    tm getDataMeczu();
    /**
     * @brief setDataMeczu
     * metoda nadpisuje date rozegrania meczu
     * @param dataMeczu
     */
    void setDataMeczu(tm dataMeczu);
    /**
     * @brief getPartie
     * metoda zwraca wektor rozegranych partii w meczu
     * @return
     */
    vector<Partia> getPartie();
    /**
     * @brief getNr
     * metoda zwraca nr meczu w turnieju
     * @return
     */
    int getNr() const;
    /**
     * @brief setNr
     * metoda ustala nr meczu w turnieju
     * @param value
     */
    void setNr(int value);

    /**
     * @brief dodajPartie
     * metoda dodaje nowa partie do meczu
     * @param partia
     */
    void dodajPartie(Partia partia);
    /**
     * @brief dodajWynik
     * metoda wieksza liczbe wygranych partii dla podanego zawodnika
     * @param zawodnik identyfikator zawodnika
     */
    void dodajWynik(int zawodnik);

    /**
     * @brief getPartia
     * metoda zwraca partie z wektora o okreslonym indeksie
     * @param index
     * @return
     */
    Partia getPartia(int index);
    /**
     * @brief setPartia
     * metoda nadpisuje partie o okreslonym indeksie
     * @param index
     * @param partia
     */
    void setPartia(int index, Partia partia);
    /**
     * @brief getZwyciezca
     * metoda zwraca identyfikator zawodnika, ktory zwyciezyl
     * @return
     */
    int getZwyciezca();
    /**
     * @brief getBrejkiStupunktoweGracza1
     * metoda zwraca wektor z brejkami stupunktowymi dla zawodnika 1
     * @return
     */

    vector<int> getBrejkiStupunktoweGracza1();
    /**
     * @brief getBrejkiStupunktoweGracza2
     * metoda zwraca wektor z brejkami stupunktowymi dla zawodnika 2
     * @return
     */
    vector<int> getBrejkiStupunktoweGracza2();

    /**
     * @brief getZawodnik1
     * metoda zwraca identyfikator zawodnika 1
     * @return
     */
    int getZawodnik1() const;
    /**
     * @brief setZawodnik1
     * metoda ustala identyfikator zawodnika 1
     * @param value
     */
    void setZawodnik1(int value);
    /**
     * @brief getZawodnik2
     * metoda zwraca identyfikator zawodnika 2
     * @return
     */
    int getZawodnik2() const;
    /**
     * @brief setZawodnik2
     * metoda ustala identyfikator zawodnika 2
     * @param value
     */
    void setZawodnik2(int value);
};

#endif // MECZ_H
