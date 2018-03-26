#include "zalogowany.h"
#include "ui_zalogowany.h"

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
    //ui->turniejFrame->setVisible(false);
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

void Zalogowany::zaladujPartie()
{
    Mecz m = this->kontenerTurniej.getTurniej(this->turniejIndex).getMecz(this->meczIndex);
    Zawodnik z1 = this->kontenerZawodnicy.getZawodnikId(m.getZawodnik1());
    Zawodnik z2 = this->kontenerZawodnicy.getZawodnikId(m.getZawodnik2());
    Partia partia = this->kontenerTurniej.getTurniej(this->turniejIndex).getMecz(this->meczIndex).getPartia(this->partiaIndex);
    this->ui->zawodnik1Label->setText(QString::fromStdString(z1.getImie()));
    this->ui->zawodnik11Label->setText(QString::fromStdString(z1.getNazwisko()));
    this->ui->zawodnik2Label->setText(QString::fromStdString(z2.getImie()));
    this->ui->zawodnik22Label->setText(QString::fromStdString(z2.getNazwisko()));
    this->ui->partiaLabel->setText(QString::fromStdString(to_string(partia.getNr())));
    this->ui->czerwoneLabel->setText(QString::fromStdString(to_string(partia.getDostepneBileCzerwone())));
    this->ui->punktyLabel->setText(QString::fromStdString(to_string(partia.getDostepnePunkty())));
    this->ui->punkty1Label->setText(QString::fromStdString(to_string(partia.getPunktyZawodnika1())));
    this->ui->punkty2Label->setText(QString::fromStdString(to_string(partia.getPunktyZawodnika2())));
    if(partia.getAktualnyZawodnik()){
        this->ui->aktualny1Label->setText("X");
        this->ui->aktualny2Label->setText("");
    }
    else{
        this->ui->aktualny1Label->setText("");
        this->ui->aktualny2Label->setText("X");
    }
}

void Zalogowany::zaladujMecze()
{
    Mecz m = this->kontenerTurniej.getTurniej(this->turniejIndex).getMecz(this->meczIndex);
    Zawodnik z1 = this->kontenerZawodnicy.getZawodnikId(m.getZawodnik1());
    Zawodnik z2 = this->kontenerZawodnicy.getZawodnikId(m.getZawodnik2());

    this->ui->meczZawodnik1Label->setText(QString::fromStdString(z1.getImie()));
    this->ui->meczZawodnik11Label->setText(QString::fromStdString(z1.getNazwisko()));
    this->ui->meczZawodnik2Label->setText(QString::fromStdString(z2.getImie()));
    this->ui->meczZawodnik22Label->setText(QString::fromStdString(z2.getNazwisko()));
    this->ui->meczPartieLabel->setText(QString::fromStdString("(" + to_string(m.getLiczbaPartii()) + ")"));
    this->ui->meczWynik1Label->setText(QString::fromStdString(to_string(m.getWynik1())));
    this->ui->meczWynik2Label->setText(QString::fromStdString(to_string(m.getWynik2())));
}

void Zalogowany::aktualizujDanePartii()
{
    //Partia partia = this->kontenerTurniej.getTurniej(this->turniejIndex).getMecz(this->meczIndex).getPartia(this->partiaIndex);
    this->ui->czerwoneLabel->setText(QString::fromStdString(to_string(this->wybranaPartia.getDostepneBileCzerwone())));
    this->ui->punktyLabel->setText(QString::fromStdString(to_string(this->wybranaPartia.getDostepnePunkty())));
    this->ui->punkty1Label->setText(QString::fromStdString(to_string(this->wybranaPartia.getPunktyZawodnika1())));
    this->ui->punkty2Label->setText(QString::fromStdString(to_string(this->wybranaPartia.getPunktyZawodnika2())));
    this->ui->aktualnyBrejkLiczbaLabel->setText(QString::fromStdString(to_string(this->wybranaPartia.getAktualnyBrejk())));
    if(this->wybranaPartia.getAktualnyZawodnik()){
        this->ui->aktualny1Label->setText("X");
        this->ui->aktualny2Label->setText("");
    }
    else{
        this->ui->aktualny1Label->setText("");
        this->ui->aktualny2Label->setText("X");
    }
}

void Zalogowany::odblokujZawodnika(bool pierwszy)
{
    this->zablokujZawodnika(!pierwszy);
    this->zablokujZawodnika(pierwszy);
    if(pierwszy){
        if(this->wybranaPartia.getDostepneBileCzerwone() > 0){
            this->ui->wbijCzerwona1PushButton->setEnabled(true);
        }
        else if(this->wybranaPartia.getDostepnePunkty() == 27 && !this->wybranaPartia.getTylkoKolory()){
            this->wybranaPartia.setTylkoKolory(true);
            this->ustawPozostaleKolory(pierwszy);
        }
        else if(this->wybranaPartia.getTylkoKolory()){
            this->ustawPozostaleKolory(pierwszy);
        }

        if(this->wybranaPartia.getDostepnePunkty() >= 7){
           this->ui->faul7PushButton->setEnabled(true);
            if(this->wybranaPartia.getDostepnePunkty() >= 13){
                this->ui->faul6PushButton->setEnabled(true);
                if(this->wybranaPartia.getDostepnePunkty() >= 18){
                    this->ui->faul5PushButton->setEnabled(true);
                    if(this->wybranaPartia.getDostepnePunkty() >= 22){
                       this->ui->faul4PushButton->setEnabled(true);
                    }
                    else{
                       this->ui->faul4PushButton->setEnabled(false);
                    }
                }
                else{
                    this->ui->faul5PushButton->setEnabled(false);
                }
            }
            else{
               this->ui->faul6PushButton->setEnabled(false);
            }
        }
        else{
            this->ui->faul7PushButton->setEnabled(false);
        }
    }
    else{
        if(this->wybranaPartia.getDostepneBileCzerwone() > 0){
            this->ui->wbijCzerwona1PushButton2->setEnabled(true);
        }
        else if(this->wybranaPartia.getDostepnePunkty() == 27 && !this->wybranaPartia.getTylkoKolory()){
            this->wybranaPartia.setTylkoKolory(true);
            this->ustawPozostaleKolory(pierwszy);
        }
        else if(this->wybranaPartia.getTylkoKolory()){
            this->ustawPozostaleKolory(pierwszy);
        }
        if(this->wybranaPartia.getDostepnePunkty() >= 7){
           this->ui->faul7PushButton2->setEnabled(true);
            if(this->wybranaPartia.getDostepnePunkty() >= 13){
                this->ui->faul6PushButton2->setEnabled(true);
                if(this->wybranaPartia.getDostepnePunkty() >= 18){
                    this->ui->faul5PushButton2->setEnabled(true);
                    if(this->wybranaPartia.getDostepnePunkty() >= 22){
                       this->ui->faul4PushButton2->setEnabled(true);
                    }
                    else{
                       this->ui->faul4PushButton2->setEnabled(false);
                    }
                }
                else{
                    this->ui->faul5PushButton2->setEnabled(false);
                }
            }
            else{
               this->ui->faul6PushButton2->setEnabled(false);
            }
        }
        else{
            this->ui->faul7PushButton2->setEnabled(false);
        }
    }
}

void Zalogowany::odblokujKolory(bool pierwszy)
{
    if(pierwszy){
        this->ui->wbijCzerwona1PushButton->setEnabled(false);
        this->ui->wbijKolorowa2PushButton->setEnabled(true);
        this->ui->wbijKolorowa3PushButton->setEnabled(true);
        this->ui->wbijKolorowa4PushButton->setEnabled(true);
        this->ui->wbijKolorowa5PushButton->setEnabled(true);
        this->ui->wbijKolorowa6PushButton->setEnabled(true);
        this->ui->wbijKolorowa7PushButton->setEnabled(true);
    }
    else{
        this->ui->wbijCzerwona1PushButton2->setEnabled(false);
        this->ui->wbijKolorowa2PushButton2->setEnabled(true);
        this->ui->wbijKolorowa3PushButton2->setEnabled(true);
        this->ui->wbijKolorowa4PushButton2->setEnabled(true);
        this->ui->wbijKolorowa5PushButton2->setEnabled(true);
        this->ui->wbijKolorowa6PushButton2->setEnabled(true);
        this->ui->wbijKolorowa7PushButton2->setEnabled(true);
    }
}

void Zalogowany::zablokujZawodnika(bool pierwszy)
{
    if(pierwszy){
        this->ui->wbijCzerwona1PushButton->setEnabled(false);
        this->ui->wbijKolorowa2PushButton->setEnabled(false);
        this->ui->wbijKolorowa3PushButton->setEnabled(false);
        this->ui->wbijKolorowa4PushButton->setEnabled(false);
        this->ui->wbijKolorowa5PushButton->setEnabled(false);
        this->ui->wbijKolorowa6PushButton->setEnabled(false);
        this->ui->wbijKolorowa7PushButton->setEnabled(false);
        this->ui->faul4PushButton->setEnabled(false);
        this->ui->faul5PushButton->setEnabled(false);
        this->ui->faul6PushButton->setEnabled(false);
        this->ui->faul7PushButton->setEnabled(false);
    }
    else{
        this->ui->wbijCzerwona1PushButton2->setEnabled(false);
        this->ui->wbijKolorowa2PushButton2->setEnabled(false);
        this->ui->wbijKolorowa3PushButton2->setEnabled(false);
        this->ui->wbijKolorowa4PushButton2->setEnabled(false);
        this->ui->wbijKolorowa5PushButton2->setEnabled(false);
        this->ui->wbijKolorowa6PushButton2->setEnabled(false);
        this->ui->wbijKolorowa7PushButton2->setEnabled(false);
        this->ui->faul4PushButton2->setEnabled(false);
        this->ui->faul5PushButton2->setEnabled(false);
        this->ui->faul6PushButton2->setEnabled(false);
        this->ui->faul7PushButton2->setEnabled(false);
    }
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
    if(turniej.getLiczbaZawodnikow() != 2 || turniej.getLiczbaZawodnikow() != 4 || turniej.getLiczbaZawodnikow() != 8 || turniej.getLiczbaZawodnikow() != 16){
        return false;
    }
    return true;
}

void Zalogowany::ustawPozostaleKolory(bool pierwszy)
{
    int punkty = this->wybranaPartia.getDostepnePunkty();
    if(pierwszy){
        switch(punkty){
        case 27:
            this->ui->wbijKolorowa2PushButton->setEnabled(true);
            break;
        case 25:
            this->ui->wbijKolorowa3PushButton->setEnabled(true);
            break;
        case 22:
            this->ui->wbijKolorowa4PushButton->setEnabled(true);
            break;
        case 18:
            this->ui->wbijKolorowa5PushButton->setEnabled(true);
            break;
        case 13:
            this->ui->wbijKolorowa6PushButton->setEnabled(true);
            break;
        case 7:
            this->ui->wbijKolorowa7PushButton->setEnabled(true);
            break;
        case 0:
            this->zakonczPartie();
            break;
        default:
            break;
        }
    }
    else{
        switch(punkty){
        case 27:
            this->ui->wbijKolorowa2PushButton2->setEnabled(true);
            break;
        case 25:
            this->ui->wbijKolorowa3PushButton2->setEnabled(true);
            break;
        case 22:
            this->ui->wbijKolorowa4PushButton2->setEnabled(true);
            break;
        case 18:
            this->ui->wbijKolorowa5PushButton2->setEnabled(true);
            break;
        case 13:
            this->ui->wbijKolorowa6PushButton2->setEnabled(true);
            break;
        case 7:
            this->ui->wbijKolorowa7PushButton2->setEnabled(true);
            break;
        case 0:
            this->zakonczPartie();
            break;
        default:
            break;
        }
    }
}

void Zalogowany::zakonczPartie()
{
    this->kontenerTurniej.aktualizujWynikMeczu(this->turniejIndex,this->meczIndex,this->wybranaPartia);
    this->kontenerTurniej.aktualizujPartie(this->turniejIndex,this->meczIndex,this->partiaIndex,this->wybranaPartia);
    this->ui->partiaFrame->setVisible(false);
    int index = this->meczIndex;
    this->ui->meczeListWidget->clear();
    this->dodajMeczeTurnieju(this->turniejIndex);
    this->ui->meczeListWidget->setCurrentRow(index);
    this->ui->partieListWidget->clear();
    this->meczIndex = index;
    this->dodajPartieMeczu(this->turniejIndex,this->meczIndex);
    this->kontenerTurniej.ustalNajwiekszyBrejkTurnieju(this->turniejIndex);
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
            this->ui->administratorzyListWidget->addItem(QString::fromStdString(imie + " " + nazwisko));
            ui->errorLabel->setText("");
        }
        else{
            ui->errorLabel->setText("Błąd. Sprawdź poprawność danych.");
        }
    }
    else{
        if(this->kontenerAdministratorzy.edytujAdministratora(this->getAdministratorIndex(),adm)){
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

    if(turniej.sprawdzNastepnaRunde()){
        this->ui->nastepnaRundaPushButton->setEnabled(true);
    }
    else{
        this->ui->nastepnaRundaPushButton->setEnabled(false);
    }
    if(turniej.getMecze().size() % 2 != 0){
        this->ui->nastepnaRundaPushButton->setText("Turniej Zakończony");
        this->ui->nastepnaRundaPushButton->setEnabled(false);
    }
    else{
        this->ui->nastepnaRundaPushButton->setText("Nastepna Runda");
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
    //ui->turniejFrame->setVisible(false);
}

void Zalogowany::on_turniejeListWidget_currentRowChanged(int currentRow)
{
    this->setTurniejIndex(currentRow);
    this->setMeczIndex(0);
    this->setPartiaIndex(-1);
    ui->partieListWidget->clear();
    ui->zawodnicyTurniejListWidget->clear();
    ui->meczeListWidget->clear();        
    this->dodajZawodnikowTurnieju(currentRow);
    this->dodajMeczeTurnieju(currentRow);
    this->wyswietlTurniej();
    if(this->turniejIndex != -1)
        this->ui->TurniejStackedWidget->setCurrentIndex(0);
    //ui->turniejFrame->setVisible(true);
    ui->dodajZawodnikaListWidget->setEnabled(false);
    ui->dodajZawodnikaPushButton->setEnabled(false);
    ui->liczbaZawodnikowTurniejLineEdit->setEnabled(false);
    ui->najwyzszyBrejkTurniejLineEdit->setEnabled(false);
    ui->pulaNagrodTurniejLineEdit->setEnabled(false);
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
    this->ui->partieListWidget->clear();
    if(currentRow != -1)
    {
        this->ui->TurniejStackedWidget->setCurrentIndex(1);
        this->dodajPartieMeczu(this->getTurniejIndex(),currentRow);
        this->zaladujMecze();
        Mecz m = this->kontenerTurniej.getTurniej(this->turniejIndex).getMecz(this->meczIndex);
        vector<Partia> partie = m.getPartie();
        if( ( m.getPartie().size() < m.getLiczbaPartii() ) && ( m.getWynik1() < ( ceil(m.getLiczbaPartii()/2) + 1 )) && ( m.getWynik2() < (ceil(m.getLiczbaPartii()/2)+ 1 )) ){
            if(partie.size() == 0){
                this->ui->dodajPartiePushButton->setEnabled(true);
            }
            else if(!(partie[partie.size() - 1].getPunktyZawodnika1() == 0 && partie[partie.size() - 1].getPunktyZawodnika2() == 0)){
                this->ui->dodajPartiePushButton->setEnabled(true);
            }
            else{
               this->ui->dodajPartiePushButton->setEnabled(false);
            }
        }
        else{
           this->ui->dodajPartiePushButton->setEnabled(false);
        }
    }
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
    if(this->partiaIndex != -1){
        this->ui->TurniejStackedWidget->setCurrentIndex(2);
        this->zaladujPartie();
        Partia p = this->kontenerTurniej.getTurniej(this->turniejIndex).getMecz(this->meczIndex).getPartia(currentRow);
        this->ui->partiaFrame->setVisible(false);
        if(p.getPunktyZawodnika1() == 0 && p.getPunktyZawodnika2() == 0){
            this->ui->rozegrajPartiePushButton->setEnabled(true);
            this->ui->dodajPartiePushButton->setEnabled(false);
        }
        else{
            this->ui->rozegrajPartiePushButton->setEnabled(false);
        }
    }
    else{
        this->ui->rozegrajPartiePushButton->setEnabled(false);
    }
}


void Zalogowany::on_dodajTurniejButton_clicked()
{
    this->ui->TurniejStackedWidget->setCurrentIndex(0);
    this->turniejTmp = Turniej();
    ui->nazwaTurniejLineEdit->setText("");
    ui->sponsorTurniejLineEdit->setText("");
    ui->miejsceTurniejLineEdit->setText("");
    ui->pulaNagrodTurniejLineEdit->setText("");
    ui->najwyzszyBrejkTurniejLineEdit->setText("");
    ui->pulaNagrodTurniejLineEdit->setEnabled(true);
    ui->liczbaZawodnikowTurniejLineEdit->setText("");
    //ui->turniejFrame->setVisible(true);
    ui->liczbaZawodnikowTurniejLineEdit->setEnabled(true);
    ui->dodajZawodnikaListWidget->setEnabled(true);
    ui->dodajZawodnikaPushButton->setEnabled(true);
    ui->edytujTurniejButton->setText("Dodaj");
    ui->zawodnicyTurniejListWidget->clear();
    ui->partieListWidget->clear();
    this->setTurniejIndex(-1);
    this->setMeczIndex(-1);
    //ui->meczeListWidget->clear();
    //ui->turniejFrame->show();

    this->ui->dodajZawodnikaListWidget->clear();
    vector<Zawodnik> zawodnicy = this->kontenerZawodnicy.getZawodnicy();
    for(int i =0; i < zawodnicy.size();i++){
        ui->dodajZawodnikaListWidget->addItem(QString::fromStdString(zawodnicy[i].getImie()+ " " + zawodnicy[i].getNazwisko()));
    }
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
    else if(ui->edytujTurniejButton->text() == "Edytuj"){
        string nazwa = ui->nazwaTurniejLineEdit->text().toStdString();
        string sponsor = ui->sponsorTurniejLineEdit->text().toStdString();
        string miejsce = ui->miejsceTurniejLineEdit->text().toStdString();
        if(nazwa.length() > 2 && sponsor.length() > 2 && miejsce.length() > 2){
            this->kontenerTurniej.edytujTurniej(this->turniejIndex,nazwa,miejsce,sponsor);
            this->ui->turniejeListWidget->item(this->turniejIndex)->setText(QString::fromStdString(sponsor) + " " + QString::fromStdString(nazwa));
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

void Zalogowany::on_rozegrajPartiePushButton_clicked()
{
    if(this->partiaIndex != -1){
       this->wybranaPartia = this->kontenerTurniej.getTurniej(this->turniejIndex).getMecz(this->meczIndex).getPartia(this->partiaIndex);
       if(this->wybranaPartia.getPunktyZawodnika1() == 0 && this->wybranaPartia.getPunktyZawodnika2() == 0){
           this->ui->partiaFrame->setVisible(true);
           this->odblokujZawodnika(true);
       }
       else{
           this->ui->partiaFrame->setVisible(false);
       }
    }
}

void Zalogowany::on_dodajPartiePushButton_clicked()
{
    this->kontenerTurniej.dodajPartie(this->turniejIndex,this->meczIndex);
    this->ui->partieListWidget->clear();
    this->dodajPartieMeczu(this->turniejIndex,this->meczIndex);
}

void Zalogowany::on_wbijCzerwona1PushButton_clicked()
{
    this->wybranaPartia.wbijBileCzerwona();
    this->odblokujKolory(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_wbijKolorowa2PushButton_clicked()
{
    this->wybranaPartia.wbijBileKolorowa(2);
    this->odblokujZawodnika(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_wbijKolorowa3PushButton_clicked()
{
    this->wybranaPartia.wbijBileKolorowa(3);
    this->odblokujZawodnika(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_wbijKolorowa4PushButton_clicked()
{
    this->wybranaPartia.wbijBileKolorowa(4);
    this->odblokujZawodnika(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_wbijKolorowa5PushButton_clicked()
{
    this->wybranaPartia.wbijBileKolorowa(5);
    this->odblokujZawodnika(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_wbijKolorowa6PushButton_clicked()
{
    this->wybranaPartia.wbijBileKolorowa(6);
    this->odblokujZawodnika(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_wbijKolorowa7PushButton_clicked()
{
    this->wybranaPartia.wbijBileKolorowa(7);
    this->odblokujZawodnika(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_zakonczBrejkaPushButton_clicked()
{
    this->wybranaPartia.setAktualnyBrejk(0);
    this->wybranaPartia.setAktualnyZawodnik(!this->wybranaPartia.getAktualnyZawodnik());
    this->odblokujZawodnika(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_wbijCzerwona1PushButton2_clicked()
{
    this->wybranaPartia.wbijBileCzerwona();
    this->odblokujKolory(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_faul4PushButton_clicked()
{
    this->wybranaPartia.faul(4);
    this->odblokujZawodnika(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_faul5PushButton_clicked()
{
    this->wybranaPartia.faul(5);
    this->odblokujZawodnika(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_faul6PushButton_clicked()
{
    this->wybranaPartia.faul(6);
    this->odblokujZawodnika(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_faul7PushButton_clicked()
{
    this->wybranaPartia.faul(7);
    this->odblokujZawodnika(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_wbijKolorowa2PushButton2_clicked()
{
    this->wybranaPartia.wbijBileKolorowa(2);
    this->odblokujZawodnika(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_wbijKolorowa3PushButton2_clicked()
{
    this->wybranaPartia.wbijBileKolorowa(3);
    this->odblokujZawodnika(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_wbijKolorowa4PushButton2_clicked()
{
    this->wybranaPartia.wbijBileKolorowa(4);
    this->odblokujZawodnika(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_wbijKolorowa5PushButton2_clicked()
{
    this->wybranaPartia.wbijBileKolorowa(5);
    this->odblokujZawodnika(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_wbijKolorowa6PushButton2_clicked()
{
    this->wybranaPartia.wbijBileKolorowa(6);
    this->odblokujZawodnika(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_wbijKolorowa7PushButton2_clicked()
{
    this->wybranaPartia.wbijBileKolorowa(7);
    this->odblokujZawodnika(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_faul4PushButton2_clicked()
{
    this->wybranaPartia.faul(4);
    this->odblokujZawodnika(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_faul5PushButton2_clicked()
{
    this->wybranaPartia.faul(5);
    this->odblokujZawodnika(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_faul6PushButton2_clicked()
{
    this->wybranaPartia.faul(6);
    this->odblokujZawodnika(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_faul7PushButton2_clicked()
{
    this->wybranaPartia.faul(7);
    this->odblokujZawodnika(this->wybranaPartia.getAktualnyZawodnik());
    this->aktualizujDanePartii();
}

void Zalogowany::on_zakonczPartiePushButton_clicked()
{
    this->zakonczPartie();
}

void Zalogowany::on_nastepnaRundaPushButton_clicked()
{
    if(this->ui->nastepnaRundaPushButton->text() == "Nastepna Runda"){
        this->kontenerTurniej.losujNastepnaRunde(this->turniejIndex);
        this->ui->meczeListWidget->clear();
        this->dodajMeczeTurnieju(this->turniejIndex);
    }
    else{
        this->kontenerTurniej.losujNastepnaRunde(this->turniejIndex);
    }
}
