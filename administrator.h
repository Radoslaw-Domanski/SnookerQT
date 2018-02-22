#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#pragma once
#include <iostream>
#include <string>
#include "Osoba.h"

class Administrator : public Osoba
{
private:
    string login;
    string haslo;
public:
    string getLogin();
    void setLogin(string login);
    string getHaslo();
    void setHaslo(string haslo);
    Administrator();
    ~Administrator();
    Administrator(string login, string haslo);
    Administrator(string imie, string nazwisko,string login, string haslo);
};

#endif
