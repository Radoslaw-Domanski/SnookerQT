#ifndef KONTENERTURNIEJ_H
#define KONTENERTURNIEJ_H

#include"turniej.h"

class KontenerTurniej
{
private:
    vector<Turniej> turnieje;
public:
    KontenerTurniej();
    ~KontenerTurniej();
    vector<Turniej> getTurnieje() const;
    void setTurnieje(const vector<Turniej> &value);
    void pobierzTurnieje();
    void zapiszTurnieje();
};

#endif // KONTENERTURNIEJ_H
