// Daire.h dosyasý
#ifndef DAIRE_H
#define DAIRE_H

#include "Nokta.h"

class Daire {
private:
    Nokta merkez;
    double yaricap;

public:
    Daire();
    Daire(const Nokta& merkez, double yaricap);
    Daire(const Daire& other);
    Daire(const Daire& other, double carpan);

    double alan() const;
    double cevre() const;
    int kesisim(const Daire& diger) const;
    std::string toString() const;
    void yazdir() const;
};

#endif // DAIRE_H
