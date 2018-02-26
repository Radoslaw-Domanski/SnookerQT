#include "konteneradministrator.h"

KontenerAdministrator::KontenerAdministrator()
{
    this->administratorzy = vector<Administrator>();
    this->pobierzAdministratorow();
}

void KontenerAdministrator::pobierzAdministratorow(){
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

bool KontenerAdministrator::logujAdministratora(string login, string haslo){
    bool znaleziony = false;
    for(int i = 0; i < this->administratorzy.size();i++){
        if(this->administratorzy[i].getLogin() == login &&
           this->administratorzy[i].getHaslo() == haslo ){
            znaleziony = true;
        }
    }
    return znaleziony;
}

bool KontenerAdministrator::dodajAdministratora(Administrator adm){
    if(!walidujAdministratora(adm)){
        return false;
    }
    else if(!sprawdzLoginAdministratora(adm.getLogin())){
        this->administratorzy.push_back(adm);
        return true;
    }
    else
        return false;
}

bool KontenerAdministrator::sprawdzLoginAdministratora(string login){
    bool znaleziony = false;
    for(int i = 0; i < this->administratorzy.size();i++){
        if(this->administratorzy[i].getLogin() == login){
            znaleziony = true;
        }
    }
    return znaleziony;
}

vector<Administrator> KontenerAdministrator::getAdministratorzy(){
    return this->administratorzy;
}

bool KontenerAdministrator::walidujAdministratora(Administrator adm){
    if(adm.getLogin().length() < 5 ||
       adm.getHaslo().length() < 5 ||
       adm.getImie().length() < 3 ||
       adm.getNazwisko().length() < 3){
        return false;
    }
    return true;
}

Administrator KontenerAdministrator::getAdministrator(int index){
    return this->administratorzy[index];
}

Administrator KontenerAdministrator::getAdministrator(string login){
    Administrator adm = Administrator();
    for(int i =0; i < this->administratorzy.size();i++){
        if(this->administratorzy[i].getLogin() == login){
            adm = this->administratorzy[i];
        }
    }
    return adm;
}

bool KontenerAdministrator::edytujAdministratora(int index, Administrator adm){
    if(walidujAdministratora(adm)){
        this->administratorzy[index].setHaslo(adm.getHaslo());
        this->administratorzy[index].setImie(adm.getImie());
        this->administratorzy[index].setNazwisko(adm.getNazwisko());
        return true;
    }
    else
        return false;
}

void KontenerAdministrator::zapiszAdministratorow(){
    xml_document<> doc;
    xml_node<>* decl = doc.allocate_node(node_declaration);
    decl->append_attribute(doc.allocate_attribute("version", "1.0"));
    decl->append_attribute(doc.allocate_attribute("encoding", "UTF-8"));
    doc.append_node(decl);

    xml_node<> *files = doc.allocate_node(node_element, "administratorzy");
    doc.append_node(files);

    for(int i = 0;i < this->administratorzy.size();i++){
        xml_node<> *admin = doc.allocate_node(node_element, "administrator");
        files->append_node(admin);
        Administrator adm = this->getAdministrator(i);

        string log = adm.getLogin();
        char * logPtr = new char[log.size() + 1];
        copy(log.begin(), log.end(), logPtr);
        logPtr[log.size()] = '\0';
        xml_node<> *login = doc.allocate_node(node_element, "login", logPtr);
        admin->append_node(login);

        string pwd = adm.getHaslo();
        char * pwdPtr = new char[pwd.size() + 1];
        copy(pwd.begin(), pwd.end(), pwdPtr);
        pwdPtr[pwd.size()] = '\0';
        xml_node<> *haslo = doc.allocate_node(node_element, "haslo",pwdPtr);
        admin->append_node(haslo);

        string name = adm.getImie();
        char * namePtr = new char[name.size() + 1];
        copy(name.begin(), name.end(), namePtr);
        namePtr[name.size()] = '\0';
        xml_node<> *imie = doc.allocate_node(node_element, "imie",namePtr);
        admin->append_node(imie);

        string sur = adm.getNazwisko();
        char * surPtr = new char[sur.size() + 1];
        copy(sur.begin(), sur.end(), surPtr);
        surPtr[sur.size()] = '\0';
        xml_node<> *nazwisko = doc.allocate_node(node_element, "nazwisko",surPtr);
        admin->append_node(nazwisko);
    }

    std::ofstream myfile("administratorzy.xml");
    myfile << doc;
    myfile.close();
    doc.clear();
}
