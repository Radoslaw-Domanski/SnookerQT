#include "kontenerzawodnik.h"

vector<Zawodnik> KontenerZawodnik::getZawodnicy() const
{
    return zawodnicy;
}

void KontenerZawodnik::setZawodnicy(const vector<Zawodnik> &value)
{
    zawodnicy = value;
}

KontenerZawodnik::KontenerZawodnik()
{
    this->zawodnicy = vector<Zawodnik>();
    this->pobierzZawodnikow();
}

KontenerZawodnik::~KontenerZawodnik()
{
    this->zapiszZawodnikow();
}


bool KontenerZawodnik::dodajZawodnika(Zawodnik zawodnik){
    if(!this->sprawdzZawodnika(zawodnik) && this->walidujZawodnika(zawodnik)){
        zawodnik.setId(this->ustalNajwiekszyIdZawodnika() + 1);
        this->zawodnicy.push_back(zawodnik);
        return true;
    }
    else{
       return false;
    }
}

Zawodnik KontenerZawodnik::getZawodnikId(int id){
    Zawodnik zaw = Zawodnik();
    for(int i = 0; i < this->zawodnicy.size(); i++){
        if(this->zawodnicy[i].getId() == id){
            zaw = zawodnicy[i];
        }
    }
    return zaw;
}

void KontenerZawodnik::pobierzZawodnikow(){
    xml_document<> doc;
    xml_node<> * root_node;
    ifstream plik("zawodnicy.xml");
    vector<char> buffer((istreambuf_iterator<char>(plik)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    doc.parse<0>(&buffer[0]);
    root_node = doc.first_node("zawodnicy");
    xml_node<> * zawodnik_node = root_node->first_node("zawodnik");
    for (zawodnik_node; zawodnik_node; zawodnik_node = zawodnik_node->next_sibling())
    {
        int id = atoi(zawodnik_node->first_attribute("id")->value());
        tm data = tm();
        string imie = zawodnik_node->first_node("imie")->value();
        string nazwisko = zawodnik_node->first_node("nazwisko")->value();
        string narodowosc = zawodnik_node->first_node("narodowosc")->value();
        string dataUrodzeniaStr = zawodnik_node->first_node("dataUrodzenia")->value();
        int dzien = atoi(dataUrodzeniaStr.substr(0,2).c_str());
        int miesiac = atoi(dataUrodzeniaStr.substr(3,2).c_str());
        int rok = atoi(dataUrodzeniaStr.substr(6,4).c_str());
        data.tm_mday = dzien;
        data.tm_mon = miesiac - 1;
        data.tm_year = rok - 1900;
        int najwyzszyBrejk = atoi(zawodnik_node->first_node("najwyzszyBrejk")->value());
        int iloscBrejkowMaksymalnych = atoi(zawodnik_node->first_node("brejkiMaksymalne")->value());
        int iloscBrejkowStupunktowych = atoi(zawodnik_node->first_node("brejkiStupunktowe")->value());
        double lacznaWygrana = stod(zawodnik_node->first_node("zarobki")->value());
        this->zawodnicy.push_back(Zawodnik(imie,nazwisko,narodowosc,data,najwyzszyBrejk,iloscBrejkowMaksymalnych,
                                           iloscBrejkowStupunktowych,lacznaWygrana,id));
    }
}

void KontenerZawodnik::zapiszZawodnikow(){
    xml_document<> doc;
    xml_node<>* decl = doc.allocate_node(node_declaration);
    decl->append_attribute(doc.allocate_attribute("version", "1.0"));
    decl->append_attribute(doc.allocate_attribute("encoding", "UTF-8"));
    doc.append_node(decl);

    xml_node<> *files = doc.allocate_node(node_element, "zawodnicy");
    doc.append_node(files);

    for(int i = 0;i < this->zawodnicy.size();i++){
        xml_node<> *zawodnik = doc.allocate_node(node_element, "zawodnik");
        files->append_node(zawodnik);
        Zawodnik zaw = this->getZawodnik(i);

        string id = to_string(zaw.getId());
        char * idPtr = new char[id.size() + 1];
        copy(id.begin(), id.end(), idPtr);
        idPtr[id.size()] = '\0';
        xml_attribute<> *attr = doc.allocate_attribute("id", idPtr);
        zawodnik->append_attribute(attr);

        string name = zaw.getImie();
        char * namePtr = new char[name.size() + 1];
        copy(name.begin(), name.end(), namePtr);
        namePtr[name.size()] = '\0';
        xml_node<> *imie = doc.allocate_node(node_element, "imie",namePtr);
        zawodnik->append_node(imie);

        string sur = zaw.getNazwisko();
        char * surPtr = new char[sur.size() + 1];
        copy(sur.begin(), sur.end(), surPtr);
        surPtr[sur.size()] = '\0';
        xml_node<> *nazwisko = doc.allocate_node(node_element, "nazwisko",surPtr);
        zawodnik->append_node(nazwisko);

        string maksy = to_string(zaw.getBrejkiMaksymalne());
        char * maksyPtr = new char[maksy.size() + 1];
        copy(maksy.begin(), maksy.end(), maksyPtr);
        maksyPtr[maksy.size()] = '\0';
        xml_node<> *maksymalneBrejki = doc.allocate_node(node_element, "brejkiMaksymalne",maksyPtr);
        zawodnik->append_node(maksymalneBrejki);

        string setki = to_string(zaw.getBrejkiStupunktowe());
        char * setkiPtr = new char[setki.size() + 1];
        copy(setki.begin(), setki.end(), setkiPtr);
        setkiPtr[setki.size()] = '\0';
        xml_node<> *setkiBrejki = doc.allocate_node(node_element, "brejkiStupunktowe",setkiPtr);
        zawodnik->append_node(setkiBrejki);

        string najwyzszy = to_string(zaw.getNajwyzszyBrejk());
        char * najwyzszyPtr = new char[najwyzszy.size() + 1];
        copy(najwyzszy.begin(), najwyzszy.end(), najwyzszyPtr);
        najwyzszyPtr[najwyzszy.size()] = '\0';
        xml_node<> *najwyzszyBrejk = doc.allocate_node(node_element, "najwyzszyBrejk",najwyzszyPtr);
        zawodnik->append_node(najwyzszyBrejk);

        string zarobki = to_string(zaw.getZarobki());
        int pozycja = zarobki.find(".");
        zarobki = zarobki.substr(0,pozycja+3);
        char * zarobkiPtr = new char[zarobki.size() + 1];
        copy(zarobki.begin(), zarobki.end(), zarobkiPtr);
        zarobkiPtr[zarobki.size()] = '\0';
        xml_node<> *zarobkiNode = doc.allocate_node(node_element, "zarobki",zarobkiPtr);
        zawodnik->append_node(zarobkiNode);

        string narodowosc = zaw.getNarodowosc();
        char * narodowoscPtr = new char[narodowosc.size() + 1];
        copy(narodowosc.begin(), narodowosc.end(), narodowoscPtr);
        narodowoscPtr[narodowosc.size()] = '\0';
        xml_node<> *narodowoscNode = doc.allocate_node(node_element, "narodowosc",narodowoscPtr);
        zawodnik->append_node(narodowoscNode);

        tm data = zaw.getDataUrodzenia();
        string dzien=to_string(data.tm_mday);
        if(dzien.length() == 1){
            dzien = "0" + dzien;
        }
        string miesiac = to_string(data.tm_mon + 1);
        if(miesiac.length() == 1){
            miesiac = "0" + miesiac;
        }
        string dataUr = dzien + "-" + miesiac + "-" + to_string(data.tm_year + 1900);
        char * dataUrPtr = new char[dataUr.size() + 1];
        copy(dataUr.begin(), dataUr.end(), dataUrPtr);
        dataUrPtr[dataUr.size()] = '\0';
        xml_node<> *dataUrodzenia = doc.allocate_node(node_element, "dataUrodzenia",dataUrPtr);
        zawodnik->append_node(dataUrodzenia);
    }

    std::ofstream myfile("zawodnicy.xml");
    myfile << doc;
    myfile.close();
    doc.clear();
}

bool KontenerZawodnik::walidujZawodnika(Zawodnik zawodnik){
    if(zawodnik.getImie().length() > 2 &&
       zawodnik.getNazwisko().length() > 2 &&
       zawodnik.getNarodowosc().length() > 2 &&
       zawodnik.getDataUrodzenia().tm_mday != NULL &&
       zawodnik.getDataUrodzenia().tm_mon >= 0 &&
       zawodnik.getDataUrodzenia().tm_year != NULL){
        return true;
    }
    else{
       return false;
    }
}

bool KontenerZawodnik::sprawdzZawodnika(Zawodnik zawodnik){
    bool jest = false;
    for(int i = 0; i < this->zawodnicy.size();i++){
        if(this->zawodnicy[i].getImie() == zawodnik.getImie() &&
           this->zawodnicy[i].getNazwisko() == zawodnik.getNazwisko()){
            jest = true;
        }
    }
    return jest;
}

int KontenerZawodnik::ustalNajwiekszyIdZawodnika()
{
    int id = 0;
    for(int i = 0; i< this->zawodnicy.size(); i++){
        if(this->zawodnicy[i].getId() > id){
            id = zawodnicy[i].getId();
        }
    }
    return id;
}

Zawodnik KontenerZawodnik::getZawodnik(int index){
    return this->zawodnicy[index];
}

Zawodnik KontenerZawodnik::getZawodnik(string imie,string nazwisko){
    Zawodnik zawodnik = Zawodnik();
    for(int i = 0; i < this->zawodnicy.size();i++){
        if(this->zawodnicy[i].getImie() == imie && this->zawodnicy[i].getNazwisko() == nazwisko){
            zawodnik = this->zawodnicy[i];
        }
    }
    return zawodnik;
}

bool KontenerZawodnik::setZawodnik(int index, Zawodnik zaw){
    if(this->walidujZawodnika(zaw)){
        this->zawodnicy[index].setImie(zaw.getImie());
        this->zawodnicy[index].setNazwisko(zaw.getNazwisko());
        this->zawodnicy[index].setNarodowosc(zaw.getNarodowosc());
        this->zawodnicy[index].setDataUrodzenia(zaw.getDataUrodzenia());
        return true;
    }
    else{
        return false;
    }
}
