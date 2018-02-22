#ifndef KONTENER_H
#define KONTENER_H
#include "vector"
#include "administrator.h"
#include "rapidxml/rapidxml.hpp"
#include "fstream"

using namespace rapidxml;

class Kontener
{
private:
    vector<Administrator> administratorzy;
public:
    Kontener();
    void pobierzAdministratorow();
    bool logujAdministratora(string login, string haslo);
    bool dodajAdministratora(Administrator adm);
    bool sprawdzLoginAdministratora(string login);
};

#endif // KONTENER_H
