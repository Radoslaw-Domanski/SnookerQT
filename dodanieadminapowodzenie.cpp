#include "dodanieadminapowodzenie.h"
#include "ui_dodanieadminapowodzenie.h"

DodanieAdminaPowodzenie::DodanieAdminaPowodzenie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodanieAdminaPowodzenie)
{
    ui->setupUi(this);
}

DodanieAdminaPowodzenie::~DodanieAdminaPowodzenie()
{
    delete ui;
}

void DodanieAdminaPowodzenie::on_pushButton_clicked()
{
    this->close();
}
