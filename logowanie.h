#ifndef LOGOWANIE_H
#define LOGOWANIE_H

#include <QMainWindow>

namespace Ui {
class Logowanie;
}

class Logowanie : public QMainWindow
{
    Q_OBJECT

public:
    explicit Logowanie(QWidget *parent = 0);
    ~Logowanie();

private:
    Ui::Logowanie *ui;
};

#endif // LOGOWANIE_H
