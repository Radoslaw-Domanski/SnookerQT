#include "logowanie.h"
#include "ui_logowanie.h"
#include "administrator.h"

Logowanie::Logowanie(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Logowanie)
{
    ui->setupUi(this);
    this->administratorzy = vector<Administrator>();
}

Logowanie::~Logowanie()
{
    delete ui;
}

void Logowanie::on_pushButton_clicked()
{

}

void Logowanie::pobierzAdministratorow(){

}
