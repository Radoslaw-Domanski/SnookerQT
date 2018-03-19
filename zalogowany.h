#ifndef ZALOGOWANY_H
#define ZALOGOWANY_H

#include <QMainWindow>
#include "konteneradministrator.h"
#include "kontenerturniej.h"
#include "kontenerzawodnik.h"

namespace Ui {
class Zalogowany;
}

class Zalogowany : public QMainWindow
{
    Q_OBJECT

public:
    explicit Zalogowany(QWidget *parent = 0);
    void dodajAdministratorowDoListy();
    void dodajZawodnikowDoListy();
    void dodajTurniejeDoListy();
    void dodajZawodnikowTurnieju(int indexTurnieju);
    void dodajMeczeTurnieju(int indexTurnieju);
    void setAdministratorIndex(int index);
    void dodajPartieMeczu(int indexTurnieju, int indexMeczu);
    void wyswietlTurniej();
    void schowajTurniej();
    void ustalZawodnikowWLiscie();
    int getAdministratorIndex();
    void zaladujPartie();
    void zaladujMecze();
    bool walidujTurniej(Turniej turniej);
    ~Zalogowany();

    int getZawodnikIndex() const;
    void setZawodnikIndex(int value);

    int getTurniejIndex() const;
    void setTurniejIndex(int value);

    int getMeczIndex() const;
    void setMeczIndex(int value);

    int getPartiaIndex() const;
    void setPartiaIndex(int value);

private slots:
    void on_dodajAdministratora_clicked();
    void on_edycjaAdministratora_clicked();

    void on_administratorzyListWidget_currentRowChanged(int currentRow);

    void on_pushButton_clicked();

    void on_zawodnicyListWidget_currentRowChanged(int currentRow);

    void on_edytujZawodnikaButton_clicked();

    void on_turniejeListWidget_currentRowChanged(int currentRow);

    void on_meczeListWidget_currentRowChanged(int currentRow);

    void on_partieListWidget_currentRowChanged(int currentRow);

    void on_dodajTurniejButton_clicked();

    void on_edytujTurniejButton_clicked();

    void on_dodajZawodnikaListWidget_currentRowChanged(int currentRow);

    void on_dodajZawodnikaPushButton_clicked();

    void on_rozegrajPartiePushButton_clicked();

private:
    Ui::Zalogowany *ui;
    KontenerAdministrator kontenerAdministratorzy;
    KontenerZawodnik kontenerZawodnicy;
    KontenerTurniej kontenerTurniej;
    Turniej turniejTmp;
    int administratorIndex;
    int zawodnikIndex;
    int turniejIndex;
    int meczIndex;
    int partiaIndex;
    int dodawanyZawodnikIndex;
};

#endif // ZALOGOWANY_H
