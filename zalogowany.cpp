#include "zalogowany.h"
#include "ui_zalogowany.h"
#include "dodanieadminapowodzenie.h"
#include <kontenersnooker.h>

Zalogowany::Zalogowany(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Zalogowany)
{
    ui->setupUi(this);
    ui->administratorFrame->setVisible(false);
    ui->zawodnikFrame->setVisible(false);
    this->kontenerAdministratorzy = KontenerAdministrator();
    this->dodajAdministratorowDoListy();
    this->dodajZawodnikowDoListy();

    ui->najwyzszyBrejkZawodnikLineEdit->setEnabled(false);
    ui->brejkiStupunktoweZawodnikLineEdit->setEnabled(false);
    ui->brejkiMaksymalneZawodnikLineEdit->setEnabled(false);
    ui->zarobkiZawodnikLineEdit->setEnabled(false);
}

Zalogowany::~Zalogowany()
{
    this->kontenerAdministratorzy.zapiszAdministratorow();
    delete ui;
}

void Zalogowany::setAdministratorIndex(int index){
    this->administratorIndex = index;
}

int Zalogowany::getAdministratorIndex(){
    return this->administratorIndex;
}

void Zalogowany::dodajAdministratorowDoListy(){
    vector<Administrator> admini = this->kontenerAdministratorzy.getAdministratorzy();
    for(int i=0;i<admini.size();i++){
        QString qstr = QString::fromStdString(admini[i].getLogin() + " " + admini[i].getHaslo());
        this->ui->administratorzyListWidget->addItem(qstr);
    }
}

void Zalogowany::dodajZawodnikowDoListy(){
    vector<Zawodnik> zawodnicy = this->kontenerSnooker.getZawodnicy();
    for(int i=0;i<zawodnicy.size();i++){
        QString qstr = QString::fromStdString(zawodnicy[i].getImie() + " " + zawodnicy[i].getNazwisko());
        this->ui->zawodnicyListWidget->addItem(qstr);
    }
}

void Zalogowany::on_dodajAdministratora_clicked()
{
    ui->administratorFrame->setVisible(true);
    ui->loginText->setText("");
    ui->hasloText->setText("");
    ui->imieText->setText("");
    ui->nazwiskoText->setText("");
    ui->loginText->setEnabled(true);
    ui->edycjaAdministratora->setText("Dodaj");
    ui->errorLabel->setText("");
}

void Zalogowany::on_edycjaAdministratora_clicked()
{
    string login = ui->loginText->text().toStdString();
    string haslo = ui->hasloText->text().toStdString();
    string imie = ui->imieText->text().toStdString();
    string nazwisko = ui->nazwiskoText->text().toStdString();
    Administrator adm = Administrator(imie,nazwisko,login,haslo);
    if(ui->edycjaAdministratora->text() == "Dodaj"){
        if(this->kontenerAdministratorzy.dodajAdministratora(adm)){
            DodanieAdminaPowodzenie *powodzenie = new DodanieAdminaPowodzenie(this);
            powodzenie->show();
            this->ui->administratorzyListWidget->addItem(QString::fromStdString(imie + " " + nazwisko));
            ui->errorLabel->setText("");
        }
        else{
            ui->errorLabel->setText("Błąd. Sprawdź poprawność danych.");
        }
    }
    else{
        if(this->kontenerAdministratorzy.edytujAdministratora(this->getAdministratorIndex(),adm)){
            DodanieAdminaPowodzenie *powodzenie = new DodanieAdminaPowodzenie(this);
            powodzenie->show();
            this->ui->administratorzyListWidget->item(this->getAdministratorIndex())->setText(QString::fromStdString(adm.getImie() + " " + adm.getNazwisko()));
            ui->errorLabel->setText("");
        }
        else{
            ui->errorLabel->setText("Błąd. Sprawdź poprawność danych.");
        }
    }
}

int Zalogowany::getZawodnikIndex() const
{
    return zawodnikIndex;
}

void Zalogowany::setZawodnikIndex(int value)
{
    zawodnikIndex = value;
}

void Zalogowany::on_administratorzyListWidget_currentRowChanged(int currentRow)
{
    ui->loginText->setEnabled(false);
    ui->administratorFrame->setVisible(true);
    Administrator admin = this->kontenerAdministratorzy.getAdministrator(currentRow);
    ui->loginText->setText(QString::fromStdString(admin.getLogin()));
    ui->hasloText->setText(QString::fromStdString(admin.getHaslo()));
    ui->imieText->setText(QString::fromStdString(admin.getImie()));
    ui->nazwiskoText->setText(QString::fromStdString(admin.getNazwisko()));
    ui->errorLabel->setText("");
    ui->edycjaAdministratora->setText("Edytuj");
    setAdministratorIndex(currentRow);
}

void Zalogowany::on_pushButton_clicked()
{
    ui->zawodnikFrame->setVisible(true);
    ui->dataUrodzeniaDateEdit->setDate(QDate::currentDate());
    ui->edytujZawodnikaButton->setText("Dodaj");
    ui->zarobkiZawodnikLineEdit->setText("0.00");
    ui->brejkiMaksymalneZawodnikLineEdit->setText("0");
    ui->brejkiStupunktoweZawodnikLineEdit->setText("0");
    ui->najwyzszyBrejkZawodnikLineEdit->setText("0");
    ui->imieZawodnikLineEdit->setText("");
    ui->nazwiskoZawodnikLineEdit->setText("");
    ui->narodowoscZawodnikLineEdit->setText("");
    QDate qdate = QDate(1950,1,1);
    ui->dataUrodzeniaDateEdit->setDate(qdate);
    ui->errorZawodnikLabel->setText("");
}

void Zalogowany::on_zawodnicyListWidget_currentRowChanged(int currentRow)
{
    this->setZawodnikIndex(currentRow);
    ui->zawodnikFrame->setVisible(true);
    Zawodnik zawodnik = this->kontenerSnooker.getZawodnik(currentRow);
    ui->imieZawodnikLineEdit->setText(QString::fromStdString(zawodnik.getImie()));
    ui->nazwiskoZawodnikLineEdit->setText(QString::fromStdString(zawodnik.getNazwisko()));
    string zarobki = to_string(zawodnik.getZarobki());
    int index = zarobki.find(".");
    string zarobkiForm = zarobki.substr(0,index+3);
    ui->zarobkiZawodnikLineEdit->setText(QString::fromStdString(zarobkiForm));
    ui->narodowoscZawodnikLineEdit->setText(QString::fromStdString(zawodnik.getNarodowosc()));
    ui->brejkiMaksymalneZawodnikLineEdit->setText(QString::fromStdString(to_string(zawodnik.getBrejkiMaksymalne())));
    ui->brejkiStupunktoweZawodnikLineEdit->setText(QString::fromStdString(to_string(zawodnik.getBrejkiStupunktowe())));
    ui->najwyzszyBrejkZawodnikLineEdit->setText(QString::fromStdString(to_string(zawodnik.getNajwyzszyBrejk())));
    tm data = zawodnik.getDataUrodzenia();
    QDate qdate = QDate(data.tm_year + 1900,data.tm_mon + 1,data.tm_mday);
    ui->dataUrodzeniaDateEdit->setDate(qdate);
    ui->edytujZawodnikaButton->setText("Edytuj");
    ui->errorZawodnikLabel->setText("");
}

void Zalogowany::on_edytujZawodnikaButton_clicked()
{
    int id = this->kontenerSnooker.ustalNajwiekszyIdZawodnika() + 1;
    int rok = ui->dataUrodzeniaDateEdit->date().year();
    int miesiac = ui->dataUrodzeniaDateEdit->date().month();
    int dzien = ui->dataUrodzeniaDateEdit->date().day();
    string imie = ui->imieZawodnikLineEdit->text().toStdString();
    string nazwisko = ui->nazwiskoZawodnikLineEdit->text().toStdString();
    string narodowosc = ui->narodowoscZawodnikLineEdit->text().toStdString();
    tm data = tm();
    data.tm_mon = miesiac - 1;
    data.tm_mday = dzien;
    data.tm_year = rok - 1900;
    if(ui->edytujZawodnikaButton->text() == "Edytuj"){
        Zawodnik zaw = Zawodnik(imie,nazwisko,narodowosc,data,0,0,0,0.0,0);
        if(this->kontenerSnooker.setZawodnik(this->zawodnikIndex,zaw)){
            DodanieAdminaPowodzenie *powodzenie = new DodanieAdminaPowodzenie(this);
            powodzenie->show();
            ui->errorZawodnikLabel->setText("");
            ui->zawodnicyListWidget->item(this->getZawodnikIndex())->setText(QString::fromStdString(imie + " " + nazwisko));
        }
        else{
            ui->errorZawodnikLabel->setText("Sprawdź poprawność danych");
        }
    }
    else if(ui->edytujZawodnikaButton->text() == "Dodaj"){
        Zawodnik zaw = Zawodnik(imie,nazwisko,narodowosc,data,0,0,0,0.0,id);
        if(this->kontenerSnooker.dodajZawodnika(zaw)){
            DodanieAdminaPowodzenie *powodzenie = new DodanieAdminaPowodzenie(this);
            powodzenie->show();
            ui->zawodnicyListWidget->addItem(QString::fromStdString(imie + " " + nazwisko));
            ui->errorZawodnikLabel->setText("");
        }
        else{
            ui->errorZawodnikLabel->setText("Sprawdź poprawność danych");
        }
    }
}
