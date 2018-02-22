#include "zalogowany.h"
#include "ui_zalogowany.h"

Zalogowany::Zalogowany(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Zalogowany)
{
    ui->setupUi(this);
    ui->frame->setVisible(false);
    this->dane = Kontener();
    //ui->administratorzyListView->setModel(QStringListModel);
}

Zalogowany::~Zalogowany()
{
    delete ui;
}

void Zalogowany::on_pushButton_clicked()
{
    ui->frame->setVisible(true);
}

void Zalogowany::on_pushButton_2_clicked()
{
    //this->dane;
    string login = ui->loginText->text().toStdString();
    string haslo = ui->hasloText->text().toStdString();
    string imie = ui->imieText->text().toStdString();
    string nazwisko = ui->nazwiskoText->text().toStdString();

}
