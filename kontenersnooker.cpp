#include "kontenersnooker.h"

KontenerSnooker::KontenerSnooker()
{
    this->turnieje = vector<Turniej>();
    this->zawodnicy = vector<Zawodnik>();
    this->pobierzZawodnikow();
    //this->pobierzTurnieje();
}

KontenerSnooker::~KontenerSnooker(){
    this->zapiszZawodnikow();
    //this->zapiszTurnieje();
}

vector<Turniej> KontenerSnooker::getTurnieje() const
{
    return turnieje;
}

void KontenerSnooker::setTurnieje(const vector<Turniej> &value)
{
    turnieje = value;
}

void KontenerSnooker::pobierzTurnieje()
{
    xml_document<> doc;
    xml_node<> * root_node;
    ifstream plik("turnieje.xml");
    vector<char> buffer((istreambuf_iterator<char>(plik)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    doc.parse<0>(&buffer[0]);
    root_node = doc.first_node("turnieje");
    xml_node<> * turniej_node = root_node->first_node("turniej");
    for (turniej_node; turniej_node; turniej_node = turniej_node->next_sibling())
    {
        int id = atoi(turniej_node->first_attribute("id")->value());
        string nazwa = turniej_node->first_node("nazwa")->value();
        string sponsor = turniej_node->first_node("sponsor")->value();
        string miejsce = turniej_node->first_node("miejsce")->value();
        int najwyzszyBrejkTurnieju = atoi(turniej_node->first_node("najwyzszyBrejkTurnieju")->value());
        int liczbaZawodnikow = atoi(turniej_node->first_node("liczbaZawodnikow")->value());
        double pulaNagrod = stod(turniej_node->first_node("pulaNagrod")->value());
        this->dodajTurniej(Turniej(nazwa,sponsor,miejsce,pulaNagrod,najwyzszyBrejkTurnieju,liczbaZawodnikow,id));
        xml_node<> * zawodnicy = turniej_node->first_node("zawodnicy");
        //->first_node("zawodnik");
        /*xml_node<> * turniej_node = root_node->first_node("turniej");
        for (zawodnik_node; zawodnik_node; zawodnik_node = zawodnik_node->next_sibling()){
            int id_zaw = atoi(zawodnik_node->first_node("zawodnik")->value());
            this->turnieje[turnieje.size()-1].dodajZawodnika(this->getZawodnikId(id_zaw));
        }*/
    }
}

Turniej KontenerSnooker::getTurniej(int index){
    return this->turnieje[index];
}

void KontenerSnooker::zapiszTurnieje()
{
    xml_document<> doc;
    xml_node<>* decl = doc.allocate_node(node_declaration);
    decl->append_attribute(doc.allocate_attribute("version", "1.0"));
    decl->append_attribute(doc.allocate_attribute("encoding", "UTF-8"));
    doc.append_node(decl);

    xml_node<> *files = doc.allocate_node(node_element, "turnieje");
    doc.append_node(files);

    for(int i = 0;i < this->turnieje.size();i++){
        xml_node<> *turniej = doc.allocate_node(node_element, "turniej");
        files->append_node(turniej);
        Turniej tur = this->getTurniej(i);

        string id = to_string(tur.getId());
        char * idPtr = new char[id.size() + 1];
        copy(id.begin(), id.end(), idPtr);
        idPtr[id.size()] = '\0';
        xml_attribute<> *attr = doc.allocate_attribute("id", idPtr);
        turniej->append_attribute(attr);

        string name = tur.getNazwa();
        char * namePtr = new char[name.size() + 1];
        copy(name.begin(), name.end(), namePtr);
        namePtr[name.size()] = '\0';
        xml_node<> *nazwa = doc.allocate_node(node_element, "nazwa",namePtr);
        turniej->append_node(nazwa);

        string sur = tur.getSponsor();
        char * surPtr = new char[sur.size() + 1];
        copy(sur.begin(), sur.end(), surPtr);
        surPtr[sur.size()] = '\0';
        xml_node<> *sponsor = doc.allocate_node(node_element, "sponsor",surPtr);
        turniej->append_node(sponsor);

        string miej = tur.getMiejsce();
        char * miejPtr = new char[miej.size() + 1];
        copy(miej.begin(), miej.end(), miejPtr);
        miejPtr[miej.size()] = '\0';
        xml_node<> *miejsce = doc.allocate_node(node_element, "miejsce",miejPtr);
        turniej->append_node(miejsce);

        string zarobki = to_string(tur.getPulaNagrod());
        int pozycja = zarobki.find(".");
        zarobki = zarobki.substr(0,pozycja+3);
        char * zarobkiPtr = new char[zarobki.size() + 1];
        copy(zarobki.begin(), zarobki.end(), zarobkiPtr);
        zarobkiPtr[zarobki.size()] = '\0';
        xml_node<> *pula = doc.allocate_node(node_element, "pulaNagrod",zarobkiPtr);
        turniej->append_node(pula);

        string brejk = to_string(tur.getNajwyzszyBrejkTurnieju());
        char * brejkPtr = new char[brejk.size() + 1];
        copy(brejk.begin(), brejk.end(), brejkPtr);
        brejkPtr[brejk.size()] = '\0';
        xml_node<> *maxBrejk = doc.allocate_node(node_element, "najwyzszyBrejkTurnieju",brejkPtr);
        turniej->append_node(maxBrejk);

        string licz = to_string(tur.getLiczbaZawodnikow());
        char * liczPtr = new char[licz.size() + 1];
        copy(licz.begin(), licz.end(), liczPtr);
        liczPtr[licz.size()] = '\0';
        xml_node<> *liczba = doc.allocate_node(node_element, "liczbaZawodnikow",liczPtr);
        turniej->append_node(liczba);

    }

    std::ofstream myfile("turniejeTest.xml");
    myfile << doc;
    myfile.close();
    doc.clear();
}

void KontenerSnooker::dodajTurniej(Turniej turniej){
   this->turnieje.push_back(turniej);
}

int KontenerSnooker::ustalNajwiekszyIdTurnieju()
{
    int id = 0;
    for(int i = 0; i < this->turnieje.size(); i++){
        if(this->turnieje[i].getId() > id){
            id = this->turnieje[i].getId();
        }
    }
    return id;
}

bool KontenerSnooker::dodajZawodnika(Zawodnik zawodnik){
    if(!this->sprawdzZawodnika(zawodnik) && this->walidujZawodnika(zawodnik)){
        zawodnik.setId(this->ustalNajwiekszyIdZawodnika() + 1);
        this->zawodnicy.push_back(zawodnik);
        return true;
    }
    else{
       return false;
    }
}

Zawodnik KontenerSnooker::getZawodnikId(int id){
    Zawodnik zaw = Zawodnik();
    for(int i = 0; i < this->zawodnicy.size(); i++){
        if(this->zawodnicy[i].getId() == id){
            zaw = zawodnicy[i];
        }
    }
    return zaw;
}

void KontenerSnooker::pobierzZawodnikow(){
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

void KontenerSnooker::zapiszZawodnikow(){
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

vector<Zawodnik> KontenerSnooker::getZawodnicy(){
    return this->zawodnicy;
}

bool KontenerSnooker::walidujZawodnika(Zawodnik zawodnik){
    if(zawodnik.getImie().length() > 2 &&
       zawodnik.getNazwisko().length() > 2 &&
       zawodnik.getNarodowosc().length() > 2 &&
       zawodnik.getDataUrodzenia().tm_mday != NULL &&
       zawodnik.getDataUrodzenia().tm_mon != NULL &&
       zawodnik.getDataUrodzenia().tm_year != NULL){
        return true;
    }
    else{
       return false;
    }
}

bool KontenerSnooker::sprawdzZawodnika(Zawodnik zawodnik){
    bool jest = false;
    for(int i = 0; i < this->zawodnicy.size();i++){
        if(this->zawodnicy[i].getImie() == zawodnik.getImie() &&
           this->zawodnicy[i].getNazwisko() == zawodnik.getNazwisko()){
            jest = true;
        }
    }
    return jest;
}

int KontenerSnooker::ustalNajwiekszyIdZawodnika()
{
    int id = 0;
    for(int i = 0; i< this->zawodnicy.size(); i++){
        if(this->zawodnicy[i].getId() > id){
            id = zawodnicy[i].getId();
        }
    }
    return id;
}

Zawodnik KontenerSnooker::getZawodnik(int index){
    return this->zawodnicy[index];
}

Zawodnik KontenerSnooker::getZawodnik(string imie,string nazwisko){
    Zawodnik zawodnik = Zawodnik();
    for(int i = 0; i < this->zawodnicy.size();i++){
        if(this->zawodnicy[i].getImie() == imie && this->zawodnicy[i].getNazwisko() == nazwisko){
            zawodnik = this->zawodnicy[i];
        }
    }
    return zawodnik;
}

bool KontenerSnooker::setZawodnik(int index, Zawodnik zaw){
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
