#ifndef KONTENERADMINISTRATOR_H
#define KONTENERADMINISTRATOR_H
#include "vector"
#include "administrator.h"
#include "rapidxml/rapidxml.hpp"
#include "rapidxml/rapidxml_utils.hpp"
#include "rapidxml/rapidxml_print.hpp"
#include "rapidxml/rapidxml_iterators.hpp"
#include "fstream"

using namespace rapidxml;

class KontenerAdministrator
{
private:
    vector<Administrator> administratorzy;
public:
    KontenerAdministrator();
    void pobierzAdministratorow();
    bool logujAdministratora(string login, string haslo);
    bool dodajAdministratora(Administrator adm);
    bool sprawdzLoginAdministratora(string login);
    vector<Administrator> getAdministratorzy();
    bool walidujAdministratora(Administrator adm);
    bool edytujAdministratora(int index, Administrator adm);
    void zapiszAdministratorow();
    Administrator getAdministrator(int index);
    Administrator getAdministrator(string login);
};

#endif // KONTENERADMINISTRATOR_H
