#ifndef ZALOGOWANY_H
#define ZALOGOWANY_H

#include <QMainWindow>
#include "kontener.h"

namespace Ui {
class Zalogowany;
}

class Zalogowany : public QMainWindow
{
    Q_OBJECT

public:
    explicit Zalogowany(QWidget *parent = 0);
    ~Zalogowany();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Zalogowany *ui;
    Kontener dane;
};

#endif // ZALOGOWANY_H
