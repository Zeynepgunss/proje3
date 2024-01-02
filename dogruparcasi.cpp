// DogruParcasi.cpp dosyasý
#include "DogruParcasi.h"
#include <iostream>
#include <cmath>
#include "Nokta.h"


DogruParcasi::DogruParcasi() : p1(Nokta()), p2(Nokta()) {}

DogruParcasi::DogruParcasi(const Nokta& nokta1, const Nokta& nokta2) : p1(nokta1), p2(nokta2) {}

DogruParcasi::DogruParcasi(const DogruParcasi& other) : p1(other.p1), p2(other.p2) {}

DogruParcasi::DogruParcasi(const Nokta& ortaNokta, double uzunluk, double egim) {
    double x2 = ortaNokta.getX() + uzunluk * cos(egim);
    double y2 = ortaNokta.getY() + uzunluk * sin(egim);
    p1.set(ortaNokta.getX() - (x2 - ortaNokta.getX()), ortaNokta.getY() - (y2 - ortaNokta.getY()));
    p2.set(x2, y2);
}

void DogruParcasi::setP1(const Nokta& nokta) { p1 = nokta; }
Nokta DogruParcasi::getP1() const { return p1; }
void DogruParcasi::setP2(const Nokta& nokta) { p2 = nokta; }
Nokta DogruParcasi::getP2() const { return p2; }

double DogruParcasi::uzunluk() const {
    double dx = p2.getX() - p1.getX();
    double dy = p2.getY() - p1.getY();
    return sqrt(dx * dx + dy * dy);
}

Nokta DogruParcasi::kesisimNoktasi(const Nokta& nokta) const {
    // Dogru parçasý p1 ile p2 arasýndaki denklemi oluþturmak için iki nokta arasýndaki doðru eðimini hesaplayýn.
    double egim_p1_p2 = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());

    // Verilen noktadan doðru parçasýna dik olarak bir doðru denklemi oluþturun.
    // Y = mX + C
    // C = Y - mX
    double egim_dik = -1 / egim_p1_p2; // Doðruya dik eðim
    double c_dik = nokta.getY() - egim_dik * nokta.getX(); // Doðruya dik olan çizginin sabiti

    // Ýki doðrunun kesiþim noktasýnýn X ve Y koordinatlarýný hesaplayýn
    // Y = mX + C ve Y = mX + C_dik
    // mX + C = mX + C_dik
    // C = C_dik
    // mX = C_dik - C
    // X = (C_dik - C) / (m)

    double kesisim_x = (c_dik - 0) / (egim_p1_p2 - egim_dik); // X koordinatý
    double kesisim_y = egim_p1_p2 * kesisim_x; // Y koordinatý

    return Nokta(kesisim_x, kesisim_y); // Kesiþim noktasýný oluþturup döndürün
}


Nokta DogruParcasi::ortaNokta() const {
    double ortaX = (p1.getX() + p2.getX()) / 2.0;
    double ortaY = (p1.getY() + p2.getY()) / 2.0;
    return Nokta(ortaX, ortaY);
}

std::string DogruParcasi::toString() const {
    return "P1: " + p1.toString() + ", P2: " + p2.toString();
}

void DogruParcasi::yazdir() const {
    std::cout << toString() << std::endl;
}