#ifndef ZALOGOWANY_H
#define ZALOGOWANY_H

#include <QMainWindow>
#include "konteneradministrator.h"
#include "kontenerturniej.h"
#include "kontenerzawodnik.h"

namespace Ui {
class Zalogowany;
}

class Zalogowany : public QMainWindow
{
    Q_OBJECT

public:
    explicit Zalogowany(QWidget *parent = 0);
    void dodajAdministratorowDoListy();
    void dodajZawodnikowDoListy();
    void dodajTurniejeDoListy();
    void dodajZawodnikowTurnieju(int indexTurnieju);
    void dodajMeczeTurnieju(int indexTurnieju);
    void setAdministratorIndex(int index);
    void dodajPartieMeczu(int indexTurnieju, int indexMeczu);
    void wyswietlTurniej();
    void schowajTurniej();
    void ustalZawodnikowWLiscie();
    int getAdministratorIndex();
    void zaladujPartie();
    void zaladujMecze();
    void aktualizujDanePartii();
    void odblokujZawodnika(bool pierwszy);
    void odblokujKolory(bool pierwszy);
    void zablokujZawodnika(bool pierwszy);
    bool walidujTurniej(Turniej turniej);
    void ustawPozostaleKolory(bool pierwszy);
    void zakonczPartie();
    ~Zalogowany();

    int getZawodnikIndex() const;
    void setZawodnikIndex(int value);

    int getTurniejIndex() const;
    void setTurniejIndex(int value);

    int getMeczIndex() const;
    void setMeczIndex(int value);

    int getPartiaIndex() const;
    void setPartiaIndex(int value);

private slots:
    void on_dodajAdministratora_clicked();
    void on_edycjaAdministratora_clicked();

    void on_administratorzyListWidget_currentRowChanged(int currentRow);

    void on_pushButton_clicked();

    void on_zawodnicyListWidget_currentRowChanged(int currentRow);

    void on_edytujZawodnikaButton_clicked();

    void on_turniejeListWidget_currentRowChanged(int currentRow);

    void on_meczeListWidget_currentRowChanged(int currentRow);

    void on_partieListWidget_currentRowChanged(int currentRow);

    void on_dodajTurniejButton_clicked();

    void on_edytujTurniejButton_clicked();

    void on_dodajZawodnikaListWidget_currentRowChanged(int currentRow);

    void on_dodajZawodnikaPushButton_clicked();

    void on_rozegrajPartiePushButton_clicked();

    void on_dodajPartiePushButton_clicked();

    void on_wbijCzerwona1PushButton_clicked();

    void on_wbijKolorowa2PushButton_clicked();

    void on_wbijKolorowa3PushButton_clicked();

    void on_wbijKolorowa4PushButton_clicked();

    void on_wbijKolorowa5PushButton_clicked();

    void on_wbijKolorowa6PushButton_clicked();

    void on_wbijKolorowa7PushButton_clicked();

    void on_zakonczBrejkaPushButton_clicked();

    void on_wbijCzerwona1PushButton2_clicked();

    void on_faul4PushButton_clicked();

    void on_faul5PushButton_clicked();

    void on_faul6PushButton_clicked();

    void on_faul7PushButton_clicked();

    void on_wbijKolorowa2PushButton2_clicked();

    void on_wbijKolorowa3PushButton2_clicked();

    void on_wbijKolorowa4PushButton2_clicked();

    void on_wbijKolorowa5PushButton2_clicked();

    void on_wbijKolorowa6PushButton2_clicked();

    void on_wbijKolorowa7PushButton2_clicked();

    void on_faul4PushButton2_clicked();

    void on_faul5PushButton2_clicked();

    void on_faul6PushButton2_clicked();

    void on_faul7PushButton2_clicked();

    void on_zakonczPartiePushButton_clicked();

private:
    Ui::Zalogowany *ui;
    KontenerAdministrator kontenerAdministratorzy;
    KontenerZawodnik kontenerZawodnicy;
    KontenerTurniej kontenerTurniej;
    Turniej turniejTmp;
    int administratorIndex;
    int zawodnikIndex;
    int turniejIndex;
    int meczIndex;
    int partiaIndex;
    int dodawanyZawodnikIndex;
    Partia wybranaPartia;
};

#endif // ZALOGOWANY_H
