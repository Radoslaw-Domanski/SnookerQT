#ifndef LOGOWANIE_H
#define LOGOWANIE_H

#include <QMainWindow>
#include "administrator.h"
#include "vector"

using namespace std;

namespace Ui {
class Logowanie;
}

class Logowanie : public QMainWindow
{
    Q_OBJECT

public:
    explicit Logowanie(QWidget *parent = 0);
    //vector<Administator> getAdministratorzy();
    void pobierzAdministratorow();
    ~Logowanie();

private slots:
    void on_pushButton_clicked();

private:
    vector<Administrator> administratorzy;
    Ui::Logowanie *ui;
};

#endif // LOGOWANIE_H
