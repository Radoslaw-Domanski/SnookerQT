#include "kontenerturniej.h"

vector<Turniej> KontenerTurniej::getTurnieje() const
{
    return turnieje;
}

void KontenerTurniej::setTurnieje(const vector<Turniej> &value)
{
    turnieje = value;
}

void KontenerTurniej::pobierzTurnieje()
{

}

void KontenerTurniej::zapiszTurnieje()
{

}

int KontenerTurniej::ustalNajwiekszyId()
{
    int id = 0;
    for(int i = 0; i < this->turnieje.size(); i++){
        if(this->turnieje[i].getId() > id){
            id = this->turnieje[i].getId();
        }
    }
    return id;
}


KontenerTurniej::KontenerTurniej()
{
    this->turnieje = vector<Turniej>();
}

KontenerTurniej::~KontenerTurniej()
{

}

