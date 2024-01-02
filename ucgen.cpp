#include "Ucgen.h"
#include <cmath>
#define M_PI 3.14159265358979323846

Ucgen::Ucgen(const Nokta& n1, const Nokta& n2, const Nokta& n3)
    : nokta1(n1), nokta2(n2), nokta3(n3) {}

void Ucgen::setNokta1(const Nokta& nokta) { nokta1 = nokta; }
Nokta Ucgen::getNokta1() const { return nokta1; }
void Ucgen::setNokta2(const Nokta& nokta) { nokta2 = nokta; }
Nokta Ucgen::getNokta2() const { return nokta2; }
void Ucgen::setNokta3(const Nokta& nokta) { nokta3 = nokta; }
Nokta Ucgen::getNokta3() const { return nokta3; }

std::string Ucgen::toString() const {
    return "��gen; Nokta1: " + nokta1.toString() + ", Nokta2: " + nokta2.toString() + ", Nokta3: " + nokta3.toString();
}

double Ucgen::alan() const {
    // ��genin alan�n� hesaplama i�lemini buraya ekleyebilirsiniz.
    // Dikkat: Bu hesaplama i�in Nokta s�n�f�n�n metotlar�n� ve ��genin alan form�l�n� kullanabilirsiniz.
    double a = nokta1.mesafe(nokta2);
    double b = nokta2.mesafe(nokta3);
    double c = nokta3.mesafe(nokta1);
    double s = (a + b + c) / 2; // ��genin yar� �evresi

    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double Ucgen::cevre() const {
    // ��genin �evresini hesaplama i�lemini buraya ekleyebilirsiniz.
    // Dikkat: Bu hesaplama i�in DogruParcasi s�n�f�n�n metotlar�n� kullanabilirsiniz.
    double cevre = 0.0;

    DogruParcasi dp1(nokta1, nokta2);
    DogruParcasi dp2(nokta2, nokta3);
    DogruParcasi dp3(nokta3, nokta1);

    cevre += dp1.uzunluk();
    cevre += dp2.uzunluk();
    cevre += dp3.uzunluk();

    return cevre;
}

double* Ucgen::acilar() const {
    // ��genin a��lar�n� hesaplama i�lemini buraya ekleyebilirsiniz.
    // Dikkat: Bu hesaplama i�in trigonometrik fonksiyonlar� kullanabilirsiniz.
    // A��lar� hesaplarken derece ya da radyan olarak hesaplayabilirsiniz.
    double* aciDizisi = new double[3]; // 3 elemanl� bir dizi

    double a = nokta1.mesafe(nokta2);
    double b = nokta2.mesafe(nokta3);
    double c = nokta3.mesafe(nokta1);

    double acosA = acos((b * b + c * c - a * a) / (2 * b * c)); // A��lar�n kosin�slerini bulmak i�in cosin�s teoremi
    double acosB = acos((c * c + a * a - b * b) / (2 * c * a));
    double acosC = acos((a * a + b * b - c * c) / (2 * a * b));

    aciDizisi[0] = acosA * 180 / M_PI; // Radyan� dereceye �evirme
    aciDizisi[1] = acosB * 180 / M_PI;
    aciDizisi[2] = acosC * 180 / M_PI;

    return aciDizisi;
}