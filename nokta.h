#ifndef NOKTA_H
#define NOKTA_H

#include <string>

class Nokta {
private:
    double x;
    double y;

public:
    Nokta();
    Nokta(double val);
    Nokta(double x_val, double y_val);
    Nokta(const Nokta& other);
    Nokta(const Nokta& other, double ofset_x, double ofset_y);
    double mesafe(const Nokta& diger) const {
        double dx = x - diger.x;
        double dy = y - diger.y;
        return sqrt(dx * dx + dy * dy);
    }
    void setX(double x_val);
    double getX() const;
    void setY(double y_val);
    double getY() const;
    void set(double x_val, double y_val);
    std::string toString() const;
    void yazdir() const;
};

#endif // NOKTA_H
