#ifndef ZALOGOWANY_H
#define ZALOGOWANY_H

#include <QMainWindow>
#include "konteneradministrator.h"
#include "kontenersnooker.h"

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
    int getAdministratorIndex();
    ~Zalogowany();

    int getZawodnikIndex() const;
    void setZawodnikIndex(int value);

    int getTurniejIndex() const;
    void setTurniejIndex(int value);

private slots:
    void on_dodajAdministratora_clicked();
    void on_edycjaAdministratora_clicked();

    void on_administratorzyListWidget_currentRowChanged(int currentRow);

    void on_pushButton_clicked();

    void on_zawodnicyListWidget_currentRowChanged(int currentRow);

    void on_edytujZawodnikaButton_clicked();

    void on_turniejeListWidget_currentRowChanged(int currentRow);

private:
    Ui::Zalogowany *ui;
    KontenerAdministrator kontenerAdministratorzy;
    //KontenerZawodnik kontenerZawodnicy;
    KontenerSnooker kontenerSnooker;
    int administratorIndex;
    int zawodnikIndex;
    int turniejIndex;
};

#endif // ZALOGOWANY_H
