#ifndef TURNIEJ_H
#define TURNIEJ_H
#include "mecz.h"
#include "string"

/**
 * @brief The Turniej class
 * klasa przechowuje i zarzadza danymi dla meczu
 */
class Turniej
{
private:
    /**
     * @brief id
     * identyfikator turnieju
     */
    int id;
    /**
     * @brief nazwa
     * nazwa turnieju
     */
    string nazwa;
    /**
     * @brief sponsor
     * sponsor turnieju
     */
    string sponsor;
    /**
     * @brief miejsce
     * miejsce turnieju
     */
    string miejsce;
    /**
     * @brief pulaNagrod
     * pula nagrod turnieju
     */
    double pulaNagrod;
    /**
     * @brief najwyzszyBrejkTurnieju
     * najwyzszy brejk turnieju
     */
    int najwyzszyBrejkTurnieju;
    /**
     * @brief liczbaZawodnikow
     * liczba zawodnikow w turnieju
     */
    int liczbaZawodnikow;
    /**
     * @brief zawodnicy
     * wektor przechowujacy identyfikatory zawodnikow
     */
    vector<int> zawodnicy;
    /**
     * @brief mecze
     * wektor przechowujacy mecze w turnieju
     */
    vector<Mecz> mecze;
public:
    /**
     * @brief Turniej
     * domyslny konstruktor
     */
    Turniej();
    /**
     * @brief Turniej
     * konstruktor przyjmujacy wszystkie informacje dla turnieju
     * @param nazwa
     * @param sponsor
     * @param miejsce
     * @param pulaNagrod
     * @param najwyzszyBrejkTurnieju
     * @param liczbaZawodnikow
     * @param id
     */
    Turniej(string nazwa,string sponsor, string miejsce, double pulaNagrod,int najwyzszyBrejkTurnieju, int liczbaZawodnikow, int id);
    /**
     * @brief ~Turniej
     * domyslny destruktor
     */
    ~Turniej();
    /**
     * @brief getSponsor
     * metoda pobiera sponsora turnieju
     * @return
     */
    string getSponsor() const;
    /**
     * @brief setSponsor
     * metoda ustala sponsora turnieju
     * @param value
     */
    void setSponsor(const string &value);
    /**
     * @brief getNazwa
     * metoda pobiera nazwe turnieju
     * @return
     */
    string getNazwa() const;
    /**
     * @brief setNazwa
     * metoda ustala nazwe turnieju
     * @param value
     */
    void setNazwa(const string &value);
    /**
     * @brief getMiejsce
     * metoda pobiera miejsce turnieju
     * @return
     */
    string getMiejsce() const;
    /**
     * @brief setMiejsce
     * metoda ustala miejsce turnieju
     * @param value
     */
    void setMiejsce(const string &value);
    /**
     * @brief getPulaNagrod
     * metoda pobiera pule nagrod turnieju
     * @return
     */
    double getPulaNagrod() const;
    /**
     * @brief setPulaNagrod
     * metoda ustala pule nagrod turnieju
     * @param value
     */
    void setPulaNagrod(double value);
    /**
     * @brief getNajwyzszyBrejkTurnieju
     * metoda pobiera najwyzszy brejk turnieju
     * @return
     */
    int getNajwyzszyBrejkTurnieju() const;
    /**
     * @brief setNajwyzszyBrejkTurnieju
     * metoda ustala najwyzszy brejk turnieju
     * @param value
     */
    void setNajwyzszyBrejkTurnieju(int value);
    /**
     * @brief getLiczbaZawodnikow
     * metoda pobiera liczbe zawodnikow turnieju
     * @return
     */
    int getLiczbaZawodnikow() const;
    /**
     * @brief setLiczbaZawodnikow
     * metoda ustala liczbe zawodnikow turnieju
     * @param value
     */
    void setLiczbaZawodnikow(int value);
    /**
     * @brief getMecze
     * metoda zwraca wektor z meczami turnieju
     * @return
     */
    vector<Mecz> getMecze() const;
    /**
     * @brief setMecze
     * metoda ustala wektor z meczami turnieju
     * @param value
     */
    void setMecze(const vector<Mecz> &value);
    /**
     * @brief getId
     * metoda zwraca identyfikator turnieju
     * @return
     */
    int getId() const;
    /**
     * @brief setId
     * metoda ustala identyfikator turnieju
     * @param value
     */
    void setId(int value);

    /**
     * @brief ustalNajwyzszyBrejkTurnieju
     * ustala najwyzszy brejk turnieju
     */
    void ustalNajwyzszyBrejkTurnieju();
    /**
     * @brief dodajMecz
     * dodaje nowy mecz do turnieju
     * @param mecz
     */
    void dodajMecz(Mecz mecz);
    /**
     * @brief getMecz
     * zwraca mecz z wektora o podanym indeksie
     * @param index
     * @return
     */
    Mecz getMecz(int index);
    /**
     * @brief dodajZawodnika
     * dodaj zawodnika o podanym identyfikatorze do turnieju
     * @param id
     */
    void dodajZawodnika(int id);
    /**
     * @brief ustalNajwyzszyNrMeczu
     * ustala najwiekszy nr meczu z dotychczasowych meczy
     * @return
     */
    int ustalNajwyzszyNrMeczu();
    /**
     * @brief losujDrabinkeTurnieju
     * losuje drabinke turnieju z dostepnych zawodnikow
     */
    void losujDrabinkeTurnieju();
    /**
     * @brief losujNastepnaRunde
     * ustala mecze dla kolejnej rundy
     */
    void losujNastepnaRunde();
    /**
     * @brief getZawodnicy
     * zwraca wektor z identyfikatorami zawodnikow bioracych udzial w turnieju
     * @return
     */
    vector<int> getZawodnicy() const;
    /**
     * @brief setZawodnicy
     * nadpisuje wektor z identyfikatorami zawodnikow nowym wektorem
     * @param value
     */
    void setZawodnicy(const vector<int> &value);
    /**
     * @brief aktualizujPartie
     * aktualizuje partie meczu o okreslonym indeksie meczu i partii
     * @param indexMeczu
     * @param indexPartii
     * @param partia
     */
    void aktualizujPartie(int indexMeczu, int indexPartii,Partia partia);
    /**
     * @brief aktualizujWynikMeczu
     * aktualizuje wynik meczu o podanym indeksie na podstawie okreslonej partii
     * @param indexMeczu
     * @param partia
     */
    void aktualizujWynikMeczu(int indexMeczu,Partia partia);
    /**
     * @brief sprawdzNastepnaRunde
     * sprawdza czy wszystkie mecze zostaly zakonczone, co pozwala na ustalenie par kolejnej rundy
     * @return
     */
    bool sprawdzNastepnaRunde();
    /**
     * @brief dodajPartie
     * dodaje nowa partie dla meczu o okreslonym indeksie
     * @param indexMeczu
     */
    void dodajPartie(int indexMeczu);
};

#endif // TURNIEJ_H
