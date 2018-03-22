#ifndef ZALOGOWANY_H
#define ZALOGOWANY_H

#include <QMainWindow>
#include "konteneradministrator.h"
#include "kontenerturniej.h"
#include "kontenerzawodnik.h"

namespace Ui {
class Zalogowany;
}
/**
 * @brief The Zalogowany class
 * klasa odpowiada za wyswietlanie danych dla zalogowanych uzytkownikow
 * przechowuje wszystkie elementy, ktore sluza do edycji i przegladania danych
 */
class Zalogowany : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Zalogowany
     * domyslny konstruktor
     * @param parent
     */
    explicit Zalogowany(QWidget *parent = 0);
    /**
     * @brief dodajAdministratorowDoListy
     * dodaje wszystkich administratorow do listy wyswietlanej
     */
    void dodajAdministratorowDoListy();
    /**
     * @brief dodajZawodnikowDoListy
     * dodaje wszystkich zawodnikow do listy wyswietlanej
     */
    void dodajZawodnikowDoListy();
    /**
     * @brief dodajTurniejeDoListy
     * dodaje wszystkie turnieje do listy wyswietlanej
     */
    void dodajTurniejeDoListy();
    /**
     * @brief dodajZawodnikowTurnieju
     * dodaje zawodnikow bioracych udzial w turnieju o wybranym indeksie do listy wyswietlanej
     * @param indexTurnieju
     */
    void dodajZawodnikowTurnieju(int indexTurnieju);
    /**
     * @brief dodajMeczeTurnieju
     * dodaje mecze w turnieju o wybranym indeksie do listy wyswietlanej
     * @param indexTurnieju
     */
    void dodajMeczeTurnieju(int indexTurnieju);
    /**
     * @brief setAdministratorIndex
     * ustala index wybranego administratora z listy
     * @param index
     */
    void setAdministratorIndex(int index);
    /**
     * @brief dodajPartieMeczu
     * dodaje partie meczu o wybranym indeksie turnieju i meczu do listy wyswietlanej
     * @param indexTurnieju
     * @param indexMeczu
     */
    void dodajPartieMeczu(int indexTurnieju, int indexMeczu);
    /**
     * @brief wyswietlTurniej
     * wyswietla dane wybranego turnieju
     */
    void wyswietlTurniej();
    /**
     * @brief schowajTurniej
     * ukrywa elementy wyswietlajace dane o wybranym turnieju
     */
    void schowajTurniej();
    /**
     * @brief getAdministratorIndex
     * zwraca index wybranego administratora
     * @return
     */
    int getAdministratorIndex();
    /**
     * @brief zaladujPartie
     * wyswietla dane dla wybranej partii
     */
    void zaladujPartie();
    /**
     * @brief zaladujMecze
     * wyswietla dane dla wybranego meczu
     */
    void zaladujMecze();
    /**
     * @brief aktualizujDanePartii
     * aktualizuje dane dla aktualnie wybranej partii
     */
    void aktualizujDanePartii();
    /**
     * @brief odblokujZawodnika
     * odblokowuje elementy edycji w partii dla podanego uzytkownika
     * @param pierwszy
     * czy zawodnik nr 1
     */
    void odblokujZawodnika(bool pierwszy);
    /**
     * @brief odblokujKolory
     * odblokowuje elementy edycji bil kolorowych w partii dla danego uzytkownika
     * @param pierwszy
     * czy zawodnik nr 1
     */
    void odblokujKolory(bool pierwszy);
    /**
     * @brief zablokujZawodnika
     * blokuje elementy w partii dla danego uzytkownika
     * @param pierwszy
     * czy zawodnik nr 1
     */
    void zablokujZawodnika(bool pierwszy);
    /**
     * @brief walidujTurniej
     * waliduje poprawnosc danych w turnieju
     * @param turniej
     * @return
     * poprawne lub nie
     */
    bool walidujTurniej(Turniej turniej);
    /**
     * @brief ustawPozostaleKolory
     * ustawia odblokowany element odpowiadajacy kolejnej bili dla danego uzytkownika
     * @param pierwszy
     * czy zawodnik nr 1
     */
    void ustawPozostaleKolory(bool pierwszy);
    /**
     * @brief zakonczPartie
     * konczy obecna partie
     */
    void zakonczPartie();
    /**
      * @brief ~Zalogowany
      * domyslny destruktor
      */
    ~Zalogowany();

    /**
     * @brief getZawodnikIndex
     * zwraca index wybranego zawodnika z listy
     * @return
     */
    int getZawodnikIndex() const;
    /**
     * @brief setZawodnikIndex
     * ustala index wybranego zawodnika z listy
     * @param value
     */
    void setZawodnikIndex(int value);

    /**
     * @brief getTurniejIndex
     * zwraca index wybranego turnieju z listy
     * @return
     */
    int getTurniejIndex() const;
    /**
     * @brief setTurniejIndex
     * ustala index wybranego turnieju z listy
     * @param value
     */
    void setTurniejIndex(int value);

    /**
     * @brief getMeczIndex
     * zwraca index wybranego meczu z listy
     * @return
     */
    int getMeczIndex() const;
    /**
     * @brief setMeczIndex
     * ustala index wybranego meczu z listy
     * @param value
     */
    void setMeczIndex(int value);

    /**
     * @brief getPartiaIndex
     * zwraca index wybranej partii z listy
     * @return
     */
    int getPartiaIndex() const;
    /**
     * @brief setPartiaIndex
     * ustala index wybranej partii z listy
     * @param value
     */
    void setPartiaIndex(int value);

private slots:
    /**
     * @brief on_dodajAdministratora_clicked
     * zdarzenie klikniecie w przycisk do dodania administratora (czyszczenie pol)
     */
    void on_dodajAdministratora_clicked();
    /**
     * @brief on_edycjaAdministratora_clicked
     * zdarzenie klikniecia w przycisk do dodania nowego/edycji obecnego administratora
     */
    void on_edycjaAdministratora_clicked();

    /**
     * @brief on_administratorzyListWidget_currentRowChanged
     * zdarzenie zmiany indeksu wybranego administratora
     * @param currentRow
     */
    void on_administratorzyListWidget_currentRowChanged(int currentRow);

    /**
     * @brief on_administratorzyListWidget_currentRowChanged
     * zdarzenie klikniecia w przycisk do dodania zawodnika
     * @param currentRow
     */
    void on_pushButton_clicked();

    /**
     * @brief on_zawodnicyListWidget_currentRowChanged
     * zdarzenie zmiany indeksu wybranego zawodnika
     * @param currentRow
     */
    void on_zawodnicyListWidget_currentRowChanged(int currentRow);

    /**
     * @brief on_edytujZawodnikaButton_clicked
     * zdarzenie klikniecia w przycisk do dodania nowego/edycji zawodnika
     */
    void on_edytujZawodnikaButton_clicked();

    /**
     * @brief on_turniejeListWidget_currentRowChanged
     * zdarzenie zmiany indeksu wybranego turnieju
     * @param currentRow
     */
    void on_turniejeListWidget_currentRowChanged(int currentRow);

    /**
     * @brief on_meczeListWidget_currentRowChanged
     * zdarzenie zmiany indeksu wybranego meczu
     * @param currentRow
     */
    void on_meczeListWidget_currentRowChanged(int currentRow);

    /**
     * @brief on_partieListWidget_currentRowChanged
     * zdarzenie zmiany indeksu wybranej partii
     * @param currentRow
     */
    void on_partieListWidget_currentRowChanged(int currentRow);

    /**
     * @brief on_dodajTurniejButton_clicked
     * zdarzenie dodania turnieju (czyszczenie pol)
     */
    void on_dodajTurniejButton_clicked();

    /**
     * @brief on_edytujTurniejButton_clicked
     * zdarzenie dodania nowego/edycji wybranego turnieju
     */
    void on_edytujTurniejButton_clicked();

    /**
     * @brief on_dodajZawodnikaListWidget_currentRowChanged
     * zdarzenie zmiany indeksu wybranego zawodnika w turnieju
     * @param currentRow
     */
    void on_dodajZawodnikaListWidget_currentRowChanged(int currentRow);

    /**
     * @brief on_dodajZawodnikaPushButton_clicked
     * zdarzenie dodania zawodnika z listy do turnieju
     */
    void on_dodajZawodnikaPushButton_clicked();

    /**
     * @brief on_rozegrajPartiePushButton_clicked
     * zdarzenie klikniecia w przycisk do rozgrywania partii
     */
    void on_rozegrajPartiePushButton_clicked();

    /**
     * @brief on_dodajPartiePushButton_clicked
     * zdarzenie klikniecia w przycisk do dodania nowej partii
     */
    void on_dodajPartiePushButton_clicked();

    /**
     * @brief on_wbijCzerwona1PushButton_clicked
     * zdarzenie klikniecia w przycisk wbicia bili czerwonej przez zawodnika 1
     */
    void on_wbijCzerwona1PushButton_clicked();

    /**
     * @brief on_wbijKolorowa2PushButton_clicked
     * zdarzenie klikniecia w przycisk wbicia bili zoltej przez zawodnika 1
     */
    void on_wbijKolorowa2PushButton_clicked();

    /**
     * @brief on_wbijKolorowa3PushButton_clicked
     * zdarzenie klikniecia w przycisk wbicia bili zielonej przez zawodnika 1
     */
    void on_wbijKolorowa3PushButton_clicked();

    /**
     * @brief on_wbijKolorowa4PushButton_clicked
     * zdarzenie klikniecia w przycisk wbicia bili brazowej przez zawodnika 1
     */
    void on_wbijKolorowa4PushButton_clicked();

    /**
     * @brief on_wbijKolorowa5PushButton_clicked
     * zdarzenie klikniecia w przycisk wbicia bili niebieskiej przez zawodnika 1
     */
    void on_wbijKolorowa5PushButton_clicked();

    /**
     * @brief on_wbijKolorowa6PushButton_clicked
     * zdarzenie klikniecia w przycisk wbicia bili rozowej przez zawodnika 1
     */
    void on_wbijKolorowa6PushButton_clicked();

    /**
     * @brief on_wbijKolorowa7PushButton_clicked
     * zdarzenie klikniecia w przycisk wbicia bili czarnej przez zawodnika 1
     */
    void on_wbijKolorowa7PushButton_clicked();

    /**
     * @brief on_zakonczBrejkaPushButton_clicked
     * zdarzenie klikniecia w przycisk zakonczenia podejscia punktowego przez aktualnego zawodnika
     */
    void on_zakonczBrejkaPushButton_clicked();

    /**
     * @brief on_wbijCzerwona1PushButton2_clicked
     * zdarzenie klikniecia w przycisk wbicia bili czerwonej przez zawodnika 2
     */
    void on_wbijCzerwona1PushButton2_clicked();

    /**
     * @brief on_faul4PushButton_clicked
     * zdarzenie klikniecia w przycisk faulu zawodnika 1 za 5 punktow
     */
    void on_faul4PushButton_clicked();

    /**
     * @brief on_faul5PushButton_clicked
     * zdarzenie klikniecia w przycisk faulu zawodnika 1 za 5 punktow
     */
    void on_faul5PushButton_clicked();

    /**
     * @brief on_faul6PushButton_clicked
     * zdarzenie klikniecia w przycisk faulu zawodnika 1 za 6 punktow
     */
    void on_faul6PushButton_clicked();

    /**
     * @brief on_faul7PushButton_clicked
     * zdarzenie klikniecia w przycisk faulu zawodnika 1 za 7 punktow
     */
    void on_faul7PushButton_clicked();

    /**
     * @brief on_wbijKolorowa2PushButton2_clicked
     * zdarzenie klikniecia w przycisk wbicia bili zoltej przez zawodnika 2
     */
    void on_wbijKolorowa2PushButton2_clicked();

    /**
     * @brief on_wbijKolorowa3PushButton2_clicked
     * zdarzenie klikniecia w przycisk wbicia bili zielonej przez zawodnika 2
     */
    void on_wbijKolorowa3PushButton2_clicked();

    /**
     * @brief on_wbijKolorowa4PushButton2_clicked
     * zdarzenie klikniecia w przycisk wbicia bili brazowej przez zawodnika 2
     */
    void on_wbijKolorowa4PushButton2_clicked();

    /**
     * @brief on_wbijKolorowa5PushButton2_clicked
     * zdarzenie klikniecia w przycisk wbicia bili niebieskiej przez zawodnika 2
     */
    void on_wbijKolorowa5PushButton2_clicked();

    /**
     * @brief on_wbijKolorowa6PushButton2_clicked
     * zdarzenie klikniecia w przycisk wbicia bili rozowej przez zawodnika 2
     */
    void on_wbijKolorowa6PushButton2_clicked();

    /**
     * @brief on_wbijKolorowa7PushButton2_clicked
     * zdarzenie klikniecia w przycisk wbicia bili czarnej przez zawodnika 2
     */
    void on_wbijKolorowa7PushButton2_clicked();

    /**
     * @brief on_faul4PushButton2_clicked
     * zdarzenie klikniecia w przycisk faulu zawodnika 2 za 4 punkty
     */
    void on_faul4PushButton2_clicked();

    /**
     * @brief on_faul5PushButton2_clicked
     * zdarzenie klikniecia w przycisk faulu zawodnika 2 za 5 punktow
     */
    void on_faul5PushButton2_clicked();

    /**
     * @brief on_faul6PushButton2_clicked
     * zdarzenie klikniecia w przycisk faulu zawodnika 2 za 6 punktow
     */
    void on_faul6PushButton2_clicked();

    /**
     * @brief on_faul7PushButton2_clicked
     * zdarzenie klikniecia w przycisk faulu zawodnika 2 za 7 punktow
     */
    void on_faul7PushButton2_clicked();

    /**
     * @brief on_zakonczPartiePushButton_clicked
     * zdarzenie klikniecia w przycisk zakonczenia obecnie rozgrywanej partii
     */
    void on_zakonczPartiePushButton_clicked();

    /**
     * @brief on_nastepnaRundaPushButton_clicked
     * zdarzenie klikniecia w przycisk ustalania nastepnej rundy w turnieju
     */
    void on_nastepnaRundaPushButton_clicked();

private:
    /**
     * @brief ui
     * posiada wszystkie elementy wizualne
     */
    Ui::Zalogowany *ui;
    /**
     * @brief kontenerAdministratorzy
     * obiekt klasy KontenerAdministrator, posiada wszystkich administratorow
     */
    KontenerAdministrator kontenerAdministratorzy;
    /**
     * @brief kontenerZawodnicy
     * obiekt klasy KontenerZawodnik, posiada wszystkich zawodnikow
     */
    KontenerZawodnik kontenerZawodnicy;
    /**
     * @brief kontenerTurniej
     * obiekt klasy KontenerTurniej, posiada wszystkie turnieje
     */
    KontenerTurniej kontenerTurniej;
    /**
     * @brief turniejTmp
     * turniej pomocniczy, sluzacy do dokonywania operacji
     */
    Turniej turniejTmp;
    /**
     * @brief administratorIndex
     * index wybranego administratora
     */
    int administratorIndex;
    /**
     * @brief zawodnikIndex
     * index wybranego zawodnika
     */
    int zawodnikIndex;
    /**
     * @brief turniejIndex
     * index wybranego turnieju
     */
    int turniejIndex;
    /**
     * @brief meczIndex
     * index wybranego meczu
     */
    int meczIndex;
    /**
     * @brief partiaIndex
     * index wybranej partii
     */
    int partiaIndex;
    /**
     * @brief dodawanyZawodnikIndex
     * index dodawanego zawodnika do turnieju
     */
    int dodawanyZawodnikIndex;
    /**
     * @brief wybranaPartia
     * wybrana partia pomocnicza
     */
    Partia wybranaPartia;
};

#endif // ZALOGOWANY_H
