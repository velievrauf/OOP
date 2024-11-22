#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"
#include <vector>

class Rhombus : public Figure {
private:
    std::vector<std::pair<double, double>> vertices;

public:
    Rhombus() = default;

    std::pair<double, double> getCenter() const override;
    double getArea() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    void scale(double factor) override;
};

#endif
