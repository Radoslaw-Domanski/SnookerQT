#include "kontenerturniej.h"

vector<Turniej> KontenerTurniej::getTurnieje() const
{
    return turnieje;
}

void KontenerTurniej::setTurnieje(const vector<Turniej> &value)
{
    turnieje = value;
}

void KontenerTurniej::aktualizujPartie(int indexTurnieju, int indexMeczu, int indexPartii,Partia partia)
{
    this->turnieje[indexTurnieju].aktualizujPartie(indexMeczu,indexPartii,partia);
}

void KontenerTurniej::aktualizujWynikMeczu(int indexTurnieju, int indexMeczu, Partia partia)
{
    this->turnieje[indexTurnieju].aktualizujWynikMeczu(indexMeczu,partia);
}

void KontenerTurniej::dodajPartie(int indexTurnieju, int indexMeczu)
{
    this->turnieje[indexTurnieju].dodajPartie(indexMeczu);
}

void KontenerTurniej::losujNastepnaRunde(int indexTurnieju)
{
    this->turnieje[indexTurnieju].losujNastepnaRunde();
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
        //vector<Mecz> mecze = tur.getMecze();
        this->zapiszMecze(i);
    }

    std::ofstream myfile("turnieje.xml");
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
        this->turnieje[idTurnieju - 1].dodajMecz(mecz);
    }
}

void KontenerTurniej::zapiszMecze(int indexTurnieju)
{
    Turniej tur = this->getTurniej(indexTurnieju);
    int idTurnieju = tur.getId();
    vector<Mecz> mecze = tur.getMecze();

    xml_document<> doc;
    xml_node<>* decl = doc.allocate_node(node_declaration);
    decl->append_attribute(doc.allocate_attribute("version", "1.0"));
    decl->append_attribute(doc.allocate_attribute("encoding", "UTF-8"));
    doc.append_node(decl);

    xml_node<> *files = doc.allocate_node(node_element, "mecze");
    doc.append_node(files);

    for(int i = 0;i < mecze.size();i++){
        xml_node<> *mecz = doc.allocate_node(node_element, "mecz");
        files->append_node(mecz);
        Mecz m = tur.getMecz(i);

        string id = to_string(m.getNr());
        char * idPtr = new char[id.size() + 1];
        copy(id.begin(), id.end(), idPtr);
        idPtr[id.size()] = '\0';
        xml_attribute<> *attr = doc.allocate_attribute("nr", idPtr);
        mecz->append_attribute(attr);

        string zawodnik1 = to_string(m.getZawodnik1());
        char * zawodnik1Ptr = new char[zawodnik1.size() + 1];
        copy(zawodnik1.begin(), zawodnik1.end(), zawodnik1Ptr);
        zawodnik1Ptr[zawodnik1.size()] = '\0';
        xml_node<> *zaw1 = doc.allocate_node(node_element, "zawodnik1",zawodnik1Ptr);
        mecz->append_node(zaw1);

        string zawodnik2 = to_string(m.getZawodnik2());
        char * zawodnik2Ptr = new char[zawodnik2.size() + 1];
        copy(zawodnik2.begin(), zawodnik2.end(), zawodnik2Ptr);
        zawodnik2Ptr[zawodnik2.size()] = '\0';
        xml_node<> *zaw2 = doc.allocate_node(node_element, "zawodnik2",zawodnik2Ptr);
        mecz->append_node(zaw2);

        string liczPartii = to_string(m.getLiczbaPartii());
        char * liczPartiiPtr = new char[liczPartii.size() + 1];
        copy(liczPartii.begin(), liczPartii.end(), liczPartiiPtr);
        liczPartiiPtr[liczPartii.size()] = '\0';
        xml_node<> *liczPartiiNode = doc.allocate_node(node_element, "liczbaPartii",liczPartiiPtr);
        mecz->append_node(liczPartiiNode);

        string wynik1 = to_string(m.getWynik1());
        char * wynik1Ptr = new char[wynik1.size() + 1];
        copy(wynik1.begin(), wynik1.end(), wynik1Ptr);
        wynik1Ptr[wynik1.size()] = '\0';
        xml_node<> *wynik1Node = doc.allocate_node(node_element, "wynik1",wynik1Ptr);
        mecz->append_node(wynik1Node);

        string wynik2 = to_string(m.getWynik2());
        char * wynik2Ptr = new char[wynik2.size() + 1];
        copy(wynik2.begin(), wynik2.end(), wynik2Ptr);
        wynik2Ptr[wynik2.size()] = '\0';
        xml_node<> *wynik2Node = doc.allocate_node(node_element, "wynik2",wynik2Ptr);
        mecz->append_node(wynik2Node);

        tm dataTm = m.getDataMeczu();
        string dzien = to_string(dataTm.tm_mday);
        string miesiac = to_string(dataTm.tm_mon + 1);
        string rok = to_string(dataTm.tm_year + 1900);
        if(dzien.length() < 2){
            dzien = "0" + dzien;
        }
        if(miesiac.length() < 2){
            miesiac = "0" + miesiac;
        }
        string dataStr = dzien + "-" + miesiac + "-" + rok;
        char * dataPtr = new char[dataStr.size() + 1];
        copy(dataStr.begin(), dataStr.end(), dataPtr);
        dataPtr[dataStr.size()] = '\0';
        xml_node<> *dataNode = doc.allocate_node(node_element, "dataMeczu",dataPtr);
        mecz->append_node(dataNode);

        xml_node<> *partie = doc.allocate_node(node_element, "partie");
        mecz->append_node(partie);

        vector<Partia> vPartie = m.getPartie();

        for(int i = 0; i < vPartie.size();i++){
            xml_node<> *partia = doc.allocate_node(node_element, "partia");
            partie->append_node(partia);

            string nr = to_string(vPartie[i].getNr());
            char *nrPtr = new char[nr.size() + 1];
            copy(nr.begin(), nr.end(), nrPtr);
            nrPtr[nr.size()] = '\0';
            xml_attribute<> *attr = doc.allocate_attribute("nr", nrPtr);
            partia->append_attribute(attr);

            string punkty1 = to_string(vPartie[i].getPunktyZawodnika1());
            char * punkty1Ptr = new char[punkty1.size() + 1];
            copy(punkty1.begin(), punkty1.end(), punkty1Ptr);
            punkty1Ptr[punkty1.size()] = '\0';
            xml_node<> *punkty1Node = doc.allocate_node(node_element, "punktyZawodnika1",punkty1Ptr);
            partia->append_node(punkty1Node);

            string punkty2 = to_string(vPartie[i].getPunktyZawodnika2());
            char * punkty2Ptr = new char[punkty2.size() + 1];
            copy(punkty2.begin(), punkty2.end(), punkty2Ptr);
            punkty2Ptr[punkty2.size()] = '\0';
            xml_node<> *punkty2Node = doc.allocate_node(node_element, "punktyZawodnika2",punkty2Ptr);
            partia->append_node(punkty2Node);

            string brejk = to_string(vPartie[i].getAktualnyBrejk());
            char * brejkPtr = new char[brejk.size() + 1];
            copy(brejk.begin(), brejk.end(), brejkPtr);
            brejkPtr[brejk.size()] = '\0';
            xml_node<> *brejkNode = doc.allocate_node(node_element, "aktualnyBrejk",brejkPtr);
            partia->append_node(brejkNode);

            string dostepnePunkty = to_string(vPartie[i].getDostepnePunkty());
            char * dostepnePunktyPtr = new char[dostepnePunkty.size() + 1];
            copy(dostepnePunkty.begin(), dostepnePunkty.end(), dostepnePunktyPtr);
            dostepnePunktyPtr[dostepnePunkty.size()] = '\0';
            xml_node<> *dostepnePunktyNode = doc.allocate_node(node_element, "dostepnePunkty",dostepnePunktyPtr);
            partia->append_node(dostepnePunktyNode);

            string dostepneBileCzerwone = to_string(vPartie[i].getDostepneBileCzerwone());
            char * dostepneBileCzerwonePtr = new char[dostepneBileCzerwone.size() + 1];
            copy(dostepneBileCzerwone.begin(), dostepneBileCzerwone.end(), dostepneBileCzerwonePtr);
            dostepneBileCzerwonePtr[dostepneBileCzerwone.size()] = '\0';
            xml_node<> *dostepneBileCzerwoneNode = doc.allocate_node(node_element, "dostepneBileCzerwone",dostepneBileCzerwonePtr);
            partia->append_node(dostepneBileCzerwoneNode);

            string aktualnyGracz = "0";
            if(vPartie[i].getAktualnyZawodnik() == true){
                aktualnyGracz = "1";
            }
            char * aktualnyGraczPtr = new char[aktualnyGracz.size() + 1];
            copy(aktualnyGracz.begin(), aktualnyGracz.end(), aktualnyGraczPtr);
            aktualnyGraczPtr[aktualnyGracz.size()] = '\0';
            xml_node<> *aktualnyGraczNode = doc.allocate_node(node_element, "aktualnyGracz",aktualnyGraczPtr);
            partia->append_node(aktualnyGraczNode);
        }


    }
    string str = "mecze" + to_string(idTurnieju) + ".xml";
    std::ofstream myfile(str);
    myfile << doc;
    myfile.close();
    doc.clear();
}
