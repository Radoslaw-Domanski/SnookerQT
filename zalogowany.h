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
    void setAdministratorIndex(int index);
    int getAdministratorIndex();
    ~Zalogowany();

    int getZawodnikIndex() const;
    void setZawodnikIndex(int value);

private slots:
    void on_dodajAdministratora_clicked();
    void on_edycjaAdministratora_clicked();

    void on_administratorzyListWidget_currentRowChanged(int currentRow);

    void on_pushButton_clicked();

    void on_zawodnicyListWidget_currentRowChanged(int currentRow);

    void on_edytujZawodnikaButton_clicked();

private:
    Ui::Zalogowany *ui;
    KontenerAdministrator kontenerAdministratorzy;
    //KontenerZawodnik kontenerZawodnicy;
    KontenerSnooker kontenerSnooker;
    int administratorIndex;
    int zawodnikIndex;
};

#endif // ZALOGOWANY_H
