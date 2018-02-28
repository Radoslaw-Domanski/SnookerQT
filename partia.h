#ifndef PARTIA_H
#define PARTIA_H


class Partia
{
private:
    int punktyZawodnika1;
    int punktyZawodnika2;
    int aktualnyBrejk;
    int dostepnePunkty;
    int dostepneBileCzerwone;
    bool aktualnyZawodnik; // jak true to zawodnik1 jak nie to zawodnik2
    bool zakonczona;
    int nr;
public:
    Partia();
    Partia(int punkty1, int punkty2, int aktualnyBrejk, int dostepnePunkty, int dostepneBileCzerwone, bool aktualnyZawodnik, bool zakonczona, int nr = 1 );
    int getPunktyZawodnika1();
    int getPunktyZawodnika2();
    int getAktualnyBrejk();
    int getDostepnePunkty();
    int getDostepneBileCzerwone();
    bool getAktualnyZawodnik();
    bool getZakonczona();

    void setPunktyZawodnika1(int punkty);
    void setPunktyZawodnika2(int punkty);
    void setAktualnyBrejk(int punkty);
    void setDostepnePunkty(int punkty);
    void setDostepneBileCzerwone(int bile);
    void setAktualnyZawodnik(bool zawodnik);
    void setZakonczona(bool zakonczona);

    void zmienZawodnika();
    void wbijBileCzerwona();
    void wbijBileKolorowa(int punkty);
    void faul(int punkty);
    void zakonczPartie();
    void edytujPartie(Partia partia);
    ~Partia();
    int getNr() const;
    void setNr(int value);
};

#endif // PARTIA_H
