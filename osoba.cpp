#include <string>
#include "Osoba.h"

template <typename T>
Osoba<T>::Osoba()
{
    this->setImie("");
    this->setNazwisko("");
}
template <typename T>
Osoba<T>::Osoba(T imie, T nazwisko)
{
    this->setImie(imie);
    this->setNazwisko(nazwisko);
}
template <typename T>
Osoba<T>::~Osoba()
{

}
template <typename T>
T Osoba<T>::getImie() {
    return this->imie;
}
template <typename T>
void Osoba<T>::setImie(T imie) {
    this->imie = imie;
}
template <typename T>
T Osoba<T>::getNazwisko() {
    return this->nazwisko;
}
template <typename T>
void Osoba<T>::setNazwisko(T nazwisko) {
    this->nazwisko = nazwisko;
}
