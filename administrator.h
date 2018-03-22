#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#pragma once
#include <iostream>
#include <string>
#include "Osoba.h"
/**
 * @brief The Administrator class
 * klasa przechowuje dane administratora
 */
class Administrator : public Osoba
{
private:
    /**
     * @brief login administratora
     */
    string login;
    /**
     * @brief haslo administratora
     */
    string haslo;
public:
    /**
     * @brief getLogin
     * @return zwracany jest login administratora
     */
    string getLogin();
    /**
     * @brief setLogin
     * @param login nadpisywany jest login administratora
     */
    void setLogin(string login);
    /**
     * @brief getHaslo
     * @return zwracane jest haslo administratora
     */
    string getHaslo();
    /**
     * @brief setHaslo
     * @param haslo nadpisywane jest haslo administratora
     */
    void setHaslo(string haslo);
    /**
     * @brief Administrator domyslny konstruktor
     */
    Administrator();
    /**
     * @brief ~Administrator domyslny destruktor
     */
    ~Administrator();
    /**
     * @brief Administrator podstawowy konstruktor
     * @param login
     * @param haslo
     */
    Administrator(string login, string haslo);
    /**
     * @brief Administrator konstruktor przyjmujacy wszystkie dane administratora
     * @param imie
     * @param nazwisko
     * @param login
     * @param haslo
     */
    Administrator(string imie, string nazwisko,string login, string haslo);
};

#endif
