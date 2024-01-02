// DogruParcasi.h dosyasý
#ifndef DOGRUPARCASI_H
#define DOGRUPARCASI_H

#include "Nokta.h"

class DogruParcasi {
private:
    Nokta p1;
    Nokta p2;

public:
    DogruParcasi();
    DogruParcasi(const Nokta& nokta1, const Nokta& nokta2);
    DogruParcasi(const DogruParcasi& other);
    DogruParcasi(const Nokta& ortaNokta, double uzunluk, double egim);

    void setP1(const Nokta& nokta);
    Nokta getP1() const;
    void setP2(const Nokta& nokta);
    Nokta getP2() const;

    double uzunluk() const;
    Nokta kesisimNoktasi(const Nokta& nokta) const;
    Nokta ortaNokta() const;
    std::string toString() const;
    void yazdir() const;
};

#endif // DOGRUPARCASI_H