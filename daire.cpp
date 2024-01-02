// Daire.cpp dosyasý

#include "Daire.h"
#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846
#include "Nokta.h"

Daire::Daire() : merkez(Nokta()), yaricap(0) {}

Daire::Daire(const Nokta& merkez, double yaricap) : merkez(merkez), yaricap(yaricap) {}

Daire::Daire(const Daire& other) : merkez(other.merkez), yaricap(other.yaricap) {}

Daire::Daire(const Daire& other, double carpan) : merkez(other.merkez), yaricap(other.yaricap* carpan) {}

double Daire::alan() const {
    return M_PI * yaricap * yaricap;
}

double Daire::cevre() const {
    return 2 * M_PI * yaricap;
}

int Daire::kesisim(const Daire& diger) const {
    double merkez_mesafe = sqrt(pow((diger.merkez.getX() - merkez.getX()), 2) + pow((diger.merkez.getY() - merkez.getY()), 2));
    double yaricap_toplam = diger.yaricap + yaricap;

    if (merkez_mesafe == 0 && yaricap == diger.yaricap)
        return 1; // Daireler birbirine eþittir (Tam örtüþme)

    if (merkez_mesafe < yaricap_toplam) {
        if (merkez_mesafe + diger.yaricap > yaricap && merkez_mesafe + yaricap > diger.yaricap) {
            return 2; // Ýki daire de birbirinin içinde
        }
        else {
            return 1; // Ýki daire birbirini kesiyor
        }
    }
    else {
        return 0; // Hiç kesiþim yok
    }
}


std::string Daire::toString() const {
    return "Merkez: " + merkez.toString() + ", Yaricap: " + std::to_string(yaricap);
}

void Daire::yazdir() const {
    std::cout << toString() << std::endl;
}
