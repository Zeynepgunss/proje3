#include "Nokta.h"
#include <iostream>

Nokta::Nokta() : x(0.0), y(0.0) {}

Nokta::Nokta(double val) : x(val), y(val) {}

Nokta::Nokta(double x_val, double y_val) : x(x_val), y(y_val) {}

Nokta::Nokta(const Nokta& other) : x(other.x), y(other.y) {}

Nokta::Nokta(const Nokta& other, double ofset_x, double ofset_y) : x(other.x + ofset_x), y(other.y + ofset_y) {}

void Nokta::setX(double x_val) { x = x_val; }
double Nokta::getX() const { return x; }

void Nokta::setY(double y_val) { y = y_val; }
double Nokta::getY() const { return y; }

void Nokta::set(double x_val, double y_val) {
    x = x_val;
    y = y_val;
}

std::string Nokta::toString() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

void Nokta::yazdir() const {
    std::cout << "Koordinatlar: " << toString() << std::endl;
}