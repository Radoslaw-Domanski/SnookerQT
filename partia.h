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
public:
    Partia();
    int getPunktyZawodnika1();
    int getPunktyZawodnika2();
    void zmienZawodnika();
    void zerujBrejk();
    void wbijBileCzerwona();
    void wbijBileKolorowa(int punkty);
    void faul(int punkty);
    void zakonczPartie();
    ~Partia();
};

#endif // PARTIA_H
