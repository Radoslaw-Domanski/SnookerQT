#include "logowanie.h"
#include "ui_logowanie.h"
#include "administrator.h"
#include "rapidxml/rapidxml.hpp"
#include "fstream"
#include "QXmlStreamReader"
#include "QFile"
#include "zalogowany.h"

using namespace rapidxml;
using namespace std;

Logowanie::Logowanie(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Logowanie)
{
    ui->setupUi(this);
    this->dane = KontenerAdministrator();
}

Logowanie::~Logowanie()
{
    delete ui;
}

void Logowanie::on_pushButton_clicked()
{
    string login = ui->loginText->text().toStdString();
    string haslo = ui->hasloText->text().toStdString();
    if(this->dane.logujAdministratora(login,haslo)){
        Zalogowany *zalogowany = new Zalogowany(this);
        this->hide();
        zalogowany->show();
    }
    else{
        ui->errorLabel->setText("Niepoprawny login lub hasło !");
    }
}
