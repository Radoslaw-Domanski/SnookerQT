#include "kontenerturniej.h"

vector<Turniej> KontenerTurniej::getTurnieje() const
{
    return turnieje;
}

void KontenerTurniej::setTurnieje(const vector<Turniej> &value)
{
    turnieje = value;
}

KontenerTurniej::KontenerTurniej()
{
    this->turnieje = vector<Turniej>();
    this->pobierzTurnieje();
}

KontenerTurniej::~KontenerTurniej()
{
    this->zapiszTurnieje();
}


void KontenerTurniej::pobierzTurnieje()
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
        xml_node<> * zawodnicy_node = turniej_node->first_node("zawodnicy");
        for(xml_node<> *zawodnik = zawodnicy_node->first_node("zawodnik");zawodnik;zawodnik=zawodnik->next_sibling()){
            this->turnieje[this->turnieje.size() - 1].dodajZawodnika(atoi(zawodnik->value()));
        }
        this->pobierzMecze(id);
    }
}

Turniej KontenerTurniej::getTurniej(int index){
    return this->turnieje[index];
}

void KontenerTurniej::zapiszTurnieje()
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

        xml_node<> *zawodnicy = doc.allocate_node(node_element, "zawodnicy");
        turniej->append_node(zawodnicy);

        vector<int> listaZawodnikow = tur.getZawodnicy();
        for(int i = 0; i < listaZawodnikow.size();i++){
            string id = to_string(listaZawodnikow[i]);
            char * idPtr = new char[id.size() + 1];
            copy(id.begin(), id.end(), idPtr);
            idPtr[id.size()] = '\0';
            xml_node<> *idik = doc.allocate_node(node_element, "zawodnik",idPtr);
            zawodnicy->append_node(idik);
        }
    }

    std::ofstream myfile("turniejeTest.xml");
    myfile << doc;
    myfile.close();
    doc.clear();
}

void KontenerTurniej::dodajTurniej(Turniej turniej){
   this->turnieje.push_back(turniej);
}

int KontenerTurniej::ustalNajwiekszyIdTurnieju()
{
    int id = 0;
    for(int i = 0; i < this->turnieje.size(); i++){
        if(this->turnieje[i].getId() > id){
            id = this->turnieje[i].getId();
        }
    }
    return id;
}

void KontenerTurniej::pobierzMecze(int idTurnieju)
{
    xml_document<> doc;
    xml_node<> * root_node;
    ifstream plik("mecze" + to_string(idTurnieju) + ".xml");
    vector<char> buffer((istreambuf_iterator<char>(plik)), istreambuf_iterator<char>());
    buffer.push_back('\0');
    doc.parse<0>(&buffer[0]);
    root_node = doc.first_node("mecze");
    xml_node<> * mecz_node = root_node->first_node("mecz");
    for (mecz_node; mecz_node; mecz_node = mecz_node->next_sibling())
    {
        int id = atoi(mecz_node->first_attribute("nr")->value());
        tm data = tm();
        int zawodnik1 = atoi(mecz_node->first_node("zawodnik1")->value());
        int zawodnik2 = atoi(mecz_node->first_node("zawodnik2")->value());
        int liczbaPartii = atoi(mecz_node->first_node("liczbaPartii")->value());
        int wynik1 = atoi(mecz_node->first_node("wynik1")->value());
        int wynik2 = atoi(mecz_node->first_node("wynik2")->value());
        string dataMeczuStr = mecz_node->first_node("dataMeczu")->value();
        int dzien = atoi(dataMeczuStr.substr(0,2).c_str());
        int miesiac = atoi(dataMeczuStr.substr(3,2).c_str());
        int rok = atoi(dataMeczuStr.substr(6,4).c_str());
        data.tm_mday = dzien;
        data.tm_mon = miesiac - 1;
        data.tm_year = rok - 1900;
        //Zawodnik zaw1 = this->getZawodnikId(zawodnik1);
        //Zawodnik zaw2 = this->getZawodnikId(zawodnik2);
        Mecz mecz = Mecz(zawodnik1,zawodnik2,data,liczbaPartii,wynik1,wynik2,id);
        cout << mecz.getPartie().size();
        xml_node<> *partie = mecz_node->first_node("partie");
        xml_node<> * partia = partie->first_node("partia");
        for (partia; partia; partia = partia->next_sibling())
        {
            int nr = atoi(partia->first_attribute("nr")->value());
            int punktyZawodnika1 = atoi(partia->first_node("punktyZawodnika1")->value());
            int punktyZawodnika2 = atoi(partia->first_node("punktyZawodnika2")->value());
            int aktualnyBrejk = atoi(partia->first_node("aktualnyBrejk")->value());
            int dostepnePunkty = atoi(partia->first_node("dostepnePunkty")->value());
            int dostepneBileCzerwone = atoi(partia->first_node("dostepneBileCzerwone")->value());
            int aktualnyGracz = atoi(partia->first_node("aktualnyGracz")->value());
            mecz.dodajPartie(Partia(punktyZawodnika1,punktyZawodnika2,aktualnyBrejk,dostepnePunkty,dostepneBileCzerwone,aktualnyGracz,true,nr));
        }
        cout << mecz.getPartie().size();
        this->turnieje[idTurnieju - 1].dodajMecz(mecz);
    }
}
