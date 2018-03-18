#include "zalogowany.h"
#include "ui_zalogowany.h"
#include "dodanieadminapowodzenie.h"

Zalogowany::Zalogowany(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Zalogowany)
{
    ui->setupUi(this);
    ui->administratorFrame->setVisible(false);
    ui->zawodnikFrame->setVisible(false);
    this->kontenerAdministratorzy = KontenerAdministrator();    
    this->dodajAdministratorowDoListy();
    this->kontenerTurniej = KontenerTurniej();
    this->kontenerZawodnicy = KontenerZawodnik();
    this->dodajZawodnikowDoListy();
    this->dodajTurniejeDoListy();
    ui->najwyzszyBrejkZawodnikLineEdit->setEnabled(false);
    ui->brejkiStupunktoweZawodnikLineEdit->setEnabled(false);
    ui->brejkiMaksymalneZawodnikLineEdit->setEnabled(false);
    ui->zarobkiZawodnikLineEdit->setEnabled(false);
    ui->turniejFrame->setVisible(false);
    ui->liczbaZawodnikowTurniejLineEdit->setEnabled(false);
    ui->najwyzszyBrejkTurniejLineEdit->setEnabled(false);
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

bool Zalogowany::walidujTurniej(Turniej turniej)
{
    if(turniej.getNazwa().length() < 3){
        return false;
    }
    if(turniej.getSponsor().length() < 3){
        return false;
    }
    if(turniej.getZawodnicy().size() != turniej.getLiczbaZawodnikow()){
        return false;
    }
    return true;
}

void Zalogowany::dodajAdministratorowDoListy(){
    vector<Administrator> admini = this->kontenerAdministratorzy.getAdministratorzy();
    for(int i=0;i<admini.size();i++){
        QString qstr = QString::fromStdString(admini[i].getImie() + " " + admini[i].getNazwisko());
        this->ui->administratorzyListWidget->addItem(qstr);
    }
}

void Zalogowany::dodajZawodnikowDoListy(){
    vector<Zawodnik> zawodnicy = this->kontenerZawodnicy.getZawodnicy();
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
    Zawodnik zawodnik = this->kontenerZawodnicy.getZawodnik(currentRow);
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
    int id = this->kontenerZawodnicy.ustalNajwiekszyIdZawodnika() + 1;
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
        if(this->kontenerZawodnicy.setZawodnik(this->zawodnikIndex,zaw)){
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
        if(this->kontenerZawodnicy.dodajZawodnika(zaw)){
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

void Zalogowany::dodajTurniejeDoListy(){
    this->ui->turniejeListWidget->clear();
    for(int i = 0; i < this->kontenerTurniej.getTurnieje().size();i++){
       ui->turniejeListWidget->addItem(QString::fromStdString(this->kontenerTurniej.getTurniej(i).getSponsor() + " " + this->kontenerTurniej.getTurniej(i).getNazwa()));
    }
}

void Zalogowany::dodajZawodnikowTurnieju(int indexTurnieju){
    Turniej turniej = this->kontenerTurniej.getTurniej(indexTurnieju);
    vector<int> zawodnicy = turniej.getZawodnicy();
    for(int i = 0; i < zawodnicy.size(); i++){
        Zawodnik zaw = this->kontenerZawodnicy.getZawodnikId(zawodnicy[i]);
        ui->zawodnicyTurniejListWidget->addItem(QString::fromStdString(zaw.getImie() + " " + zaw.getNazwisko()));
    }
}

void Zalogowany::dodajMeczeTurnieju(int indexTurnieju)
{
    Turniej turniej = this->kontenerTurniej.getTurniej(indexTurnieju);
    vector<Mecz> mecze = turniej.getMecze();
    for(int i = 0; i < mecze.size(); i++){
        Zawodnik zaw1 = this->kontenerZawodnicy.getZawodnikId(mecze[i].getZawodnik1());
        Zawodnik zaw2 = this->kontenerZawodnicy.getZawodnikId(mecze[i].getZawodnik2());
        string w1 = to_string(mecze[i].getWynik1());
        string w2 = to_string(mecze[i].getWynik2());
        QString qStr = QString::fromStdString(zaw1.getNazwisko() + " " + w1 + ":" + w2 + " " + zaw2.getNazwisko());
        ui->meczeListWidget->addItem(qStr);
    }
}

void Zalogowany::dodajPartieMeczu(int indexTurnieju, int indexMeczu)
{
    Turniej turniej = this->kontenerTurniej.getTurniej(indexTurnieju);
    vector<Partia> partie = turniej.getMecz(indexMeczu).getPartie();
    for(int i = 0; i < partie.size();i++){
        string punkty1 = to_string(partie[i].getPunktyZawodnika1());
        string punkty2= to_string(partie[i].getPunktyZawodnika2());
        ui->partieListWidget->addItem(QString::fromStdString(punkty1 + ":" + punkty2));
    }
}

void Zalogowany::wyswietlTurniej()
{
    Turniej turniej = this->kontenerTurniej.getTurniej(this->getTurniejIndex());
    ui->nazwaTurniejLineEdit->setText(QString::fromStdString(turniej.getNazwa()));
    ui->sponsorTurniejLineEdit->setText(QString::fromStdString(turniej.getSponsor()));
    ui->miejsceTurniejLineEdit->setText(QString::fromStdString(turniej.getMiejsce()));
    string pula = to_string(turniej.getPulaNagrod());
    int kropkaIndex = pula.find(".");
    pula = pula.substr(0,kropkaIndex+3);
    ui->pulaNagrodTurniejLineEdit->setText(QString::fromStdString(pula));
    ui->najwyzszyBrejkTurniejLineEdit->setText(QString::fromStdString(to_string(turniej.getNajwyzszyBrejkTurnieju())));
    ui->liczbaZawodnikowTurniejLineEdit->setText(QString::fromStdString(to_string(turniej.getLiczbaZawodnikow())));
}

void Zalogowany::schowajTurniej()
{
    ui->turniejFrame->setVisible(false);
}

void Zalogowany::on_turniejeListWidget_currentRowChanged(int currentRow)
{
    this->setMeczIndex(-1);
    this->setPartiaIndex(-1);
    ui->meczeListWidget->clear();
    ui->zawodnicyTurniejListWidget->clear();
    ui->partieListWidget->clear();
    this->dodajZawodnikowTurnieju(currentRow);
    this->dodajMeczeTurnieju(currentRow);
    this->setTurniejIndex(currentRow);
    this->wyswietlTurniej();
    ui->turniejFrame->setVisible(true);
    ui->dodajZawodnikaListWidget->setEnabled(false);
    ui->dodajZawodnikaPushButton->setEnabled(false);
    ui->liczbaZawodnikowTurniejLineEdit->setEnabled(false);
    ui->najwyzszyBrejkTurniejLineEdit->setEnabled(false);
    ui->edytujTurniejButton->setText("Edytuj");
}

int Zalogowany::getTurniejIndex() const
{
    return turniejIndex;
}

void Zalogowany::setTurniejIndex(int value)
{
    turniejIndex = value;
}

void Zalogowany::on_meczeListWidget_currentRowChanged(int currentRow)
{
    this->setMeczIndex(currentRow);
    this->setPartiaIndex(-1);
    this->dodajPartieMeczu(this->getTurniejIndex(),currentRow);
    this->schowajTurniej();
}

int Zalogowany::getPartiaIndex() const
{
    return partiaIndex;
}

void Zalogowany::setPartiaIndex(int value)
{
    partiaIndex = value;
}

int Zalogowany::getMeczIndex() const
{
    return meczIndex;
}

void Zalogowany::setMeczIndex(int value)
{
    meczIndex = value;
}

void Zalogowany::on_partieListWidget_currentRowChanged(int currentRow)
{
    this->setPartiaIndex(currentRow);
    this->schowajTurniej();
}


void Zalogowany::on_dodajTurniejButton_clicked()
{
    this->turniejTmp = Turniej();
    ui->nazwaTurniejLineEdit->setText("");
    ui->sponsorTurniejLineEdit->setText("");
    ui->miejsceTurniejLineEdit->setText("");
    ui->pulaNagrodTurniejLineEdit->setText("");
    ui->najwyzszyBrejkTurniejLineEdit->setText("");
    ui->liczbaZawodnikowTurniejLineEdit->setText("");
    ui->turniejFrame->setVisible(true);
    ui->liczbaZawodnikowTurniejLineEdit->setEnabled(true);
    ui->dodajZawodnikaListWidget->setEnabled(true);
    ui->dodajZawodnikaPushButton->setEnabled(true);
    ui->edytujTurniejButton->setText("Dodaj");
    ui->zawodnicyTurniejListWidget->clear();
    ui->partieListWidget->clear();
    this->setTurniejIndex(-1);
    this->setMeczIndex(-1);
    //ui->meczeListWidget->clear();
    ui->turniejFrame->show();

    this->ui->dodajZawodnikaListWidget->clear();
    vector<Zawodnik> zawodnicy = this->kontenerZawodnicy.getZawodnicy();
    for(int i =0; i < zawodnicy.size();i++){
        ui->dodajZawodnikaListWidget->addItem(QString::fromStdString(zawodnicy[i].getImie()+ " " + zawodnicy[i].getNazwisko()));
    }
}


void ustalZawodnikowWLiscie(){

}

void Zalogowany::on_edytujTurniejButton_clicked()
{
    if(ui->edytujTurniejButton->text() == "Dodaj"){
        this->turniejTmp.setNazwa(ui->nazwaTurniejLineEdit->text().toStdString());
        this->turniejTmp.setSponsor(ui->sponsorTurniejLineEdit->text().toStdString());
        this->turniejTmp.setMiejsce(ui->miejsceTurniejLineEdit->text().toStdString());
        this->turniejTmp.setPulaNagrod(ui->pulaNagrodTurniejLineEdit->text().toDouble());
        this->turniejTmp.setNajwyzszyBrejkTurnieju(0);
        this->turniejTmp.setId(this->kontenerTurniej.ustalNajwiekszyIdTurnieju() + 1);
        this->turniejTmp.setLiczbaZawodnikow(ui->liczbaZawodnikowTurniejLineEdit->text().toInt());
        if(this->walidujTurniej(this->turniejTmp)){
            this->turniejTmp.losujDrabinkeTurnieju();
            this->kontenerTurniej.dodajTurniej(this->turniejTmp);
            this->turniejTmp = Turniej();
            dodajTurniejeDoListy();
        }
    }
}

void Zalogowany::on_dodajZawodnikaListWidget_currentRowChanged(int currentRow)
{
    this->dodawanyZawodnikIndex = currentRow;
}

void Zalogowany::on_dodajZawodnikaPushButton_clicked()
{
    if(this->dodawanyZawodnikIndex != -1){
        vector<int> zawodnicy = this->turniejTmp.getZawodnicy();
        bool jest = false;
        for(int i = 0; i < zawodnicy.size();i++){
            if(zawodnicy[i] == this->dodawanyZawodnikIndex + 1){
                jest = true;
            }
        }
        if(!jest){
            this->turniejTmp.dodajZawodnika(this->dodawanyZawodnikIndex + 1);
            this->ui->zawodnicyTurniejListWidget->clear();
            vector<int> zawodnicy = turniejTmp.getZawodnicy();
            for(int i = 0; i < zawodnicy.size(); i++){
                Zawodnik zaw = this->kontenerZawodnicy.getZawodnikId(zawodnicy[i]);
                ui->zawodnicyTurniejListWidget->addItem(QString::fromStdString(zaw.getImie() + " " + zaw.getNazwisko()));
            }
        }
    }
}
