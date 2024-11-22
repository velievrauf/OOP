#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"
#include <vector>

class Trapezoid : public Figure {
private:
    std::vector<std::pair<double, double>> vertices;

public:
    Trapezoid() = default;

    std::pair<double, double> getCenter() const override;
    double getArea() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    void scale(double factor) override;
};

#endif // TRAPEZOID_H
