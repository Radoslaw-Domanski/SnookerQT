#include "logowanie.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Logowanie w;
    w.show();
    int x = 5;
    return a.exec();
}
