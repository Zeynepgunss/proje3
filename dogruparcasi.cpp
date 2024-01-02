// DogruParcasi.cpp dosyas�
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
    // Dogru par�as� p1 ile p2 aras�ndaki denklemi olu�turmak i�in iki nokta aras�ndaki do�ru e�imini hesaplay�n.
    double egim_p1_p2 = (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());

    // Verilen noktadan do�ru par�as�na dik olarak bir do�ru denklemi olu�turun.
    // Y = mX + C
    // C = Y - mX
    double egim_dik = -1 / egim_p1_p2; // Do�ruya dik e�im
    double c_dik = nokta.getY() - egim_dik * nokta.getX(); // Do�ruya dik olan �izginin sabiti

    // �ki do�runun kesi�im noktas�n�n X ve Y koordinatlar�n� hesaplay�n
    // Y = mX + C ve Y = mX + C_dik
    // mX + C = mX + C_dik
    // C = C_dik
    // mX = C_dik - C
    // X = (C_dik - C) / (m)

    double kesisim_x = (c_dik - 0) / (egim_p1_p2 - egim_dik); // X koordinat�
    double kesisim_y = egim_p1_p2 * kesisim_x; // Y koordinat�

    return Nokta(kesisim_x, kesisim_y); // Kesi�im noktas�n� olu�turup d�nd�r�n
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