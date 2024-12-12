#include "rhombus.h"
#include <cmath>

std::pair<double, double> Rhombus::getCenter() const {
    double x = 0, y = 0;
    for (const auto& vertex : vertices) {
        x += vertex.first;
        y += vertex.second;
    }
    return {x / vertices.size(), y / vertices.size()};
}

double Rhombus::getArea() const {
    if (vertices.size() != 4) return 0;
    double d1 = std::hypot(vertices[0].first - vertices[2].first, vertices[0].second - vertices[2].second);
    double d2 = std::hypot(vertices[1].first - vertices[3].first, vertices[1].second - vertices[3].second);
    return 0.5 * d1 * d2;
}

void Rhombus::print(std::ostream& os) const {
    os << "Rhombus vertices: ";
    for (const auto& vertex : vertices) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
}

void Rhombus::read(std::istream& is) {
    vertices.clear();
    std::cout << "Enter 4 vertices of the rhombus (x y): ";
    for (int i = 0; i < 4; ++i) {
        double x, y;
        is >> x >> y;
        vertices.emplace_back(x, y);
    }
}

void Rhombus::scale(double factor) {
    auto center = getCenter();
    for (auto& vertex : vertices) {
        vertex.first = center.first + (vertex.first - center.first) * factor;
        vertex.second = center.second + (vertex.second - center.second) * factor;
    }
}
