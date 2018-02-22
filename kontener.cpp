#include "kontener.h"

Kontener::Kontener()
{
    this->administratorzy = vector<Administrator>();
    this->pobierzAdministratorow();
}

void Kontener::pobierzAdministratorow(){
    xml_document<> doc;
    xml_node<> * root_node;
    ifstream plik("administratorzy.xml");
    vector<char> buffer((istreambuf_iterator<char>(plik)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    doc.parse<0>(&buffer[0]);
    root_node = doc.first_node("administratorzy");
    xml_node<> * brewery_node = root_node->first_node("administrator");
    for (brewery_node; brewery_node; brewery_node = brewery_node->next_sibling())
    {
        string imie = brewery_node->first_node("imie")->value();
        string nazwisko = brewery_node->first_node("nazwisko")->value();
        string login = brewery_node->first_node("login")->value();
        string haslo = brewery_node->first_node("haslo")->value();
        this->administratorzy.push_back(Administrator(imie,nazwisko,login,haslo));
    }
}

bool Kontener::logujAdministratora(string login, string haslo){
    bool znaleziony = false;
    for(int i = 0; i < this->administratorzy.size();i++){
        if(this->administratorzy[i].getLogin() == login &&
           this->administratorzy[i].getHaslo() == haslo ){
            znaleziony = true;
        }
    }
    return znaleziony;
}

bool Kontener::dodajAdministratora(Administrator adm){
    if(!sprawdzLoginAdministratora(adm.getLogin())){
        this->administratorzy.push_back(adm);
        return true;
    }
    else
        return false;
}

bool Kontener::sprawdzLoginAdministratora(string login){
    bool znaleziony = false;
    for(int i = 0; i < this->administratorzy.size();i++){
        if(this->administratorzy[i].getLogin() == login){
            znaleziony = true;
        }
    }
    return znaleziony;
}
