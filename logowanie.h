#ifndef LOGOWANIE_H
#define LOGOWANIE_H

#include <QMainWindow>
#include "administrator.h"
#include "vector"
#include "konteneradministrator.h"

using namespace std;

namespace Ui {

class Logowanie;
}
/**
 * @brief The Logowanie class
 * klasa przedstawia ekran do logowania dla uzytkownika o pozwala mu sie zalogowac
 */
class Logowanie : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Logowanie
     * domyslny konstruktor
     * @param parent
     */
    explicit Logowanie(QWidget *parent = 0);
    /**
     * @brief ~Logowanie
     * domyslny destruktor
     */
    ~Logowanie();

private slots:
    /**
     * @brief on_pushButton_clicked
     * zdarzenie klikniecia w przycisk do logowania
     */
    void on_pushButton_clicked();

private:
    /**
     * @brief dane
     * zawiera wszystkich administratorow w systemie
     */
    KontenerAdministrator dane;
    /**
     * @brief ui
     * zawiera wszystkie kontrolki interfejsu
     */
    Ui::Logowanie *ui;
};

#endif // LOGOWANIE_H
