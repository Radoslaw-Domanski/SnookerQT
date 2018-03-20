#ifndef MECZ_H
#define MECZ_H
#include "ctime"
#include "vector"
#include "partia.h"
#include "zawodnik.h"

class Mecz
{
private:
    int wynik1;
    int wynik2;
    int liczbaPartii;
    tm dataMeczu;
    vector<Partia> partie;
    int zawodnik1;
    int zawodnik2;
    bool zakonczony;
    int nr;
public:
    Mecz();
    Mecz(int zawodnik1, int zawodnik2, tm dataMeczu, int liczbaPartii,
         int wynik1 = 0, int wynik2 = 0, int nr = 0);
    ~Mecz();
    int getWynik1();
    void setWynik1(int wynik1);
    int getWynik2();
    void setWynik2(int wynik2);
    int getLiczbaPartii();
    void setLiczbaPartii(int liczbaPartii);
    tm getDataMeczu();
    void setDataMeczu(tm dataMeczu);
    vector<Partia> getPartie();
    int getNr() const;
    void setNr(int value);

    void dodajPartie(Partia partia);
    void dodajWynik(int zawodnik);
    void zakonczMecz();
    Partia getPartia(int index);
    void setPartia(int index, Partia partia);
    int getZwyciezca();
    vector<int> getBrejkiStupunktoweGracza1();
    vector<int> getBrejkiStupunktoweGracza2();

    int getZawodnik1() const;
    void setZawodnik1(int value);
    int getZawodnik2() const;
    void setZawodnik2(int value);
    bool getZakonczony() const;
    void setZakonczony(bool value);
};

#endif // MECZ_H
