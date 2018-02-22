#include "Administrator.h"

Administrator::Administrator() : Osoba()
{

}

Administrator::Administrator(string login,string haslo): Osoba() {
    this->login = login;
    this->haslo = haslo;
}

Administrator::Administrator(string imie, string nazwisko, string login, string haslo) : Osoba(imie,nazwisko) {
    this->login = login;
    this->haslo = haslo;
}

Administrator::~Administrator() {

}

string Administrator::getHaslo() {
    return this->haslo;
}

void Administrator::setHaslo(string haslo) {
    this->haslo = haslo;
}

string Administrator::getLogin() {
    return this->login;
}

void Administrator::setLogin(string login) {
    this->login=login;
}
