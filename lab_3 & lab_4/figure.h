#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <utility>

class Figure {
public:
    virtual ~Figure() = default;
    virtual std::pair<double, double> getCenter() const = 0;
    virtual double getArea() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
    virtual void scale(double factor) = 0;
};

#endif // FIGURE_H
