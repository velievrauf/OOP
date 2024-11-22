#include "pentagon.h"
#include <cmath>

std::pair<double, double> Pentagon::getCenter() const {
    double x = 0, y = 0;
    for (const auto& vertex : vertices) {
        x += vertex.first;
        y += vertex.second;
    }
    return {x / vertices.size(), y / vertices.size()};
}

double Pentagon::getArea() const {
    if (vertices.size() != 5) return 0;
    double area = 0;
    for (size_t i = 0; i < vertices.size(); ++i) {
        auto& p1 = vertices[i];
        auto& p2 = vertices[(i + 1) % vertices.size()];
        area += p1.first * p2.second - p2.first * p1.second;
    }
    return std::abs(area) / 2.0;
}

void Pentagon::print(std::ostream& os) const {
    os << "Pentagon vertices: ";
    for (const auto& vertex : vertices) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
}

void Pentagon::read(std::istream& is) {
    vertices.clear();
    std::cout << "Enter 5 vertices of the pentagon (x y): ";
    for (int i = 0; i < 5; ++i) {
        double x, y;
        is >> x >> y;
        vertices.emplace_back(x, y);
    }
}

void Pentagon::scale(double factor) {
    auto center = getCenter();
    for (auto& vertex : vertices) {
        vertex.first = center.first + (vertex.first - center.first) * factor;
        vertex.second = center.second + (vertex.second - center.second) * factor;
    }
}
