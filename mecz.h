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
    Zawodnik zawodnik1;
    Zawodnik zawodnik2;
    bool zakonczony;
public:
    Mecz();
    Mecz(Zawodnik zawodnik1, Zawodnik zawodnik2, tm dataMeczu, int liczbaPartii,
         int wynik1 = 0, int wynik2 = 0);
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
    Zawodnik getZawodnik1();
    void setZawodnik1(Zawodnik zawodnik1);
    Zawodnik getZawodnik2();
    void setZawodnik2(Zawodnik zawodnik2);
    void dodajPartie(Partia partia);
    void dodajWynik(Zawodnik zawodnik);
    void zakonczMecz();
    Partia getPartia(int index);
    void setPartia(int index, Partia partia);
    Zawodnik getZwyciezca();
    vector<int> getBrejkiStupunktoweGracza1();
    vector<int> getBrejkiStupunktoweGracza2();
};

#endif // MECZ_H
