#ifndef DODANIEADMINAPOWODZENIE_H
#define DODANIEADMINAPOWODZENIE_H

#include <QDialog>

namespace Ui {
class DodanieAdminaPowodzenie;
}

class DodanieAdminaPowodzenie : public QDialog
{
    Q_OBJECT

public:
    explicit DodanieAdminaPowodzenie(QWidget *parent = 0);
    ~DodanieAdminaPowodzenie();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DodanieAdminaPowodzenie *ui;
};

#endif // DODANIEADMINAPOWODZENIE_H
