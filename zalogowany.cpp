#include "zalogowany.h"
#include "ui_zalogowany.h"
#include "dodanieadminapowodzenie.h"

Zalogowany::Zalogowany(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Zalogowany)
{
    ui->setupUi(this);
    ui->frame->setVisible(false);
    this->dane = Kontener();
    dodajAdministratorowDoListy();
    //ui->administratorzyListView->setModel(QStringListModel);
}

Zalogowany::~Zalogowany()
{
    this->dane.zapiszAdministratorow();
    delete ui;
}

void Zalogowany::setAdministratorIndex(int index){
    this->administratorIndex = index;
}

int Zalogowany::getAdministratorIndex(){
    return this->administratorIndex;
}

void Zalogowany::dodajAdministratorowDoListy(){
    vector<Administrator> admini = this->dane.getAdministratorzy();
    for(int i=0;i<admini.size();i++){
        QString qstr = QString::fromStdString(admini[i].getLogin() + " " + admini[i].getHaslo());
        this->ui->listWidget->addItem(qstr);
    }
}

void Zalogowany::on_listWidget_currentRowChanged(int currentRow)
{
    ui->loginText->setEnabled(false);
    Administrator admin = this->dane.getAdministrator(currentRow);
    ui->loginText->setText(QString::fromStdString(admin.getLogin()));
    ui->hasloText->setText(QString::fromStdString(admin.getHaslo()));
    ui->imieText->setText(QString::fromStdString(admin.getImie()));
    ui->nazwiskoText->setText(QString::fromStdString(admin.getNazwisko()));
    ui->errorLabel->setText("");
    ui->edycjaAdministratora->setText("Edytuj");
    setAdministratorIndex(currentRow);
}

void Zalogowany::on_dodajAdministratora_clicked()
{
    ui->frame->setVisible(true);
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
        if(this->dane.dodajAdministratora(adm)){
            DodanieAdminaPowodzenie *powodzenie = new DodanieAdminaPowodzenie(this);
            powodzenie->show();
            this->ui->listWidget->addItem(QString::fromStdString(imie + " " + nazwisko));
            ui->errorLabel->setText("");
        }
        else{
            ui->errorLabel->setText("Błąd. Sprawdź poprawność danych.");
        }
    }
    else{
        if(this->dane.edytujAdministratora(this->getAdministratorIndex(),adm)){
            DodanieAdminaPowodzenie *powodzenie = new DodanieAdminaPowodzenie(this);
            powodzenie->show();
            this->ui->listWidget->item(this->getAdministratorIndex())->setText(QString::fromStdString(adm.getImie() + " " + adm.getNazwisko()));
            ui->errorLabel->setText("");
        }
        else{
            ui->errorLabel->setText("Błąd. Sprawdź poprawność danych.");
        }
    }
}
