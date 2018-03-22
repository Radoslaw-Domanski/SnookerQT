#ifndef PARTIA_H
#define PARTIA_H

/**
 * @brief The Partia class
 * klasa przechowuje i zarzadza informacjami o partii meczu
 */
class Partia
{
private:
    /**
     * @brief punktyZawodnika1
     * punkty zdobyte przez zawodnika 1
     */
    int punktyZawodnika1;
    /**
     * @brief punktyZawodnika2
     * punkty zdobyte przez zawodnika 2
     */
    int punktyZawodnika2;
    /**
     * @brief aktualnyBrejk
     * aktualny brejk zawodnika przy stole
     */
    int aktualnyBrejk;
    /**
     * @brief dostepnePunkty
     * dostepne punkty do zdobycia na stole
     */
    int dostepnePunkty;
    /**
     * @brief dostepneBileCzerwone
     * ilosc bil czerwonych na stole
     */
    int dostepneBileCzerwone;
    /**
     * @brief aktualnyZawodnik
     * aktualny zawodnik przy stole true = zawodnik1, false = zawodnik2
     */
    bool aktualnyZawodnik;
    /**
     * @brief zakonczona
     * czy partia zakonczona
     */
    bool zakonczona;
    /**
     * @brief nr
     * nr partii w meczu
     */
    int nr;
    /**
     * @brief tylkoKolory
     * czy wszystkie bile czerwone zostaly wbite
     */
    bool tylkoKolory;
public:
    /**
     * @brief Partia
     * domyslny konstruktor
     */
    Partia();
    /**
     * @brief Partia
     * konstruktor przyjmujacy wszystkie parametry dla partii
     * @param punkty1
     * @param punkty2
     * @param aktualnyBrejk
     * @param dostepnePunkty
     * @param dostepneBileCzerwone
     * @param aktualnyZawodnik
     * @param zakonczona
     * @param nr
     */
    Partia(int punkty1, int punkty2, int aktualnyBrejk, int dostepnePunkty, int dostepneBileCzerwone, bool aktualnyZawodnik, bool zakonczona, int nr = 1 );
    /**
     * @brief getPunktyZawodnika1
     * zwraca punkty zawodnika 1
     * @return
     */
    int getPunktyZawodnika1();
    /**
     * @brief getPunktyZawodnika2
     * zwraca punkty zawodnika 2
     * @return
     */
    int getPunktyZawodnika2();
    /**
     * @brief getAktualnyBrejk
     * zwraca aktualny brejk zawodnika przy stole
     * @return
     */
    int getAktualnyBrejk();
    /**
     * @brief getDostepnePunkty
     * zwraca dostepne punkty na stole
     * @return
     */
    int getDostepnePunkty();
    /**
     * @brief getDostepneBileCzerwone
     * zwraca ilosc bil czerwonych na stole
     * @return
     */
    int getDostepneBileCzerwone();
    /**
     * @brief getAktualnyZawodnik
     * zwraca aktualnego zawodnika przy stole
     * @return
     */
    bool getAktualnyZawodnik();
    /**
     * @brief getZakonczona
     * zwraca czy partia jest zakonczona
     * @return
     */
    bool getZakonczona();
    /**
     * @brief setPunktyZawodnika1
     * ustala punkty zawodnika 1
     * @param punkty
     */
    void setPunktyZawodnika1(int punkty);
    /**
     * @brief setPunktyZawodnika2
     * ustala punkty zawodnika 2
     * @param punkty
     */
    void setPunktyZawodnika2(int punkty);
    /**
     * @brief setAktualnyBrejk
     * ustala aktualny brejk zawodnika przy stole
     * @param punkty
     */
    void setAktualnyBrejk(int punkty);
    /**
     * @brief setDostepnePunkty
     * ustala dostepne punkty do zdobycia na stole
     * @param punkty
     */
    void setDostepnePunkty(int punkty);
    /**
     * @brief setDostepneBileCzerwone
     * ustala ilosc dostepnych bil czerwonych
     * @param bile
     */
    void setDostepneBileCzerwone(int bile);
    /**
     * @brief setAktualnyZawodnik
     * ustala aktualnego zawodnika przy stole
     * @param zawodnik
     */
    void setAktualnyZawodnik(bool zawodnik);
    /**
     * @brief setZakonczona
     * ustala czy partia zostala zakonczona
     * @param zakonczona
     */
    void setZakonczona(bool zakonczona);
    /**
     * @brief getNr
     * zwraca nr partii w meczu
     * @return
     */
    int getNr() const;
    /**
     * @brief setNr
     * ustala nr partii w meczu
     * @param value
     */
    void setNr(int value);

    /**
     * @brief zmienZawodnika
     * metoda zmiena zawodnika przy stole
     */
    void zmienZawodnika();
    /**
     * @brief wbijBileCzerwona
     * metoda zmniejsza ilosc bil czerwonych na stole i dodaje punkty dla obecnego zawodnika
     */
    void wbijBileCzerwona();
    /**
     * @brief wbijBileKolorowa
     * metoda dodaje punkty dla obecnego zawodnika za bile kolorowa
     * @param punkty
     */
    void wbijBileKolorowa(int punkty);
    /**
     * @brief faul
     * metoda zwieksza ilosc punktow dla przeciwnego zawodnika niz jest przy stole
     * @param punkty
     */
    void faul(int punkty);
    /**
     * @brief zakonczPartie
     * metoda konczy partie
     */
    void zakonczPartie();
    /**
     * @brief edytujPartie
     * metoda nadpisuje wartosci aktualnej partii z partii podanej w parametrze
     * @param partia
     */
    void edytujPartie(Partia partia);
    /**
     * @brief ~Partia
     * domyslny destruktor
     */
    ~Partia();

    /**
     * @brief getTylkoKolory
     * metoda zwraca czy zostaly juz wbite wszystkie czerwone
     * @return
     */
    bool getTylkoKolory() const;
    /**
     * @brief setTylkoKolory
     * metoda ustala czy zostaly juz wbite wszystkie czerwone
     * @param value
     */
    void setTylkoKolory(bool value);
};

#endif // PARTIA_H
