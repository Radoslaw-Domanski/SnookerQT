#ifndef ZALOGOWANY_H
#define ZALOGOWANY_H

#include <QMainWindow>
#include "konteneradministrator.h"
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
    void setAdministratorIndex(int index);
    int getAdministratorIndex();
    ~Zalogowany();

private slots:
    void on_listWidget_currentRowChanged(int currentRow);
    void on_dodajAdministratora_clicked();
    void on_edycjaAdministratora_clicked();

private:
    Ui::Zalogowany *ui;
    KontenerAdministrator kontenerAdministratorzy;
    KontenerZawodnik kontenerZawodnicy;
    int administratorIndex;
};

#endif // ZALOGOWANY_H
