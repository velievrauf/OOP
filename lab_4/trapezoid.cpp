#include "trapezoid.h"
#include <cmath>
#include <iostream>

std::pair<double, double> Trapezoid::getCenter() const {
    double x = 0, y = 0;
    for (const auto& vertex : vertices) {
        x += vertex.first;
        y += vertex.second;
    }
    return {x / 4, y / 4};
}

double Trapezoid::getArea() const {
    if (vertices.size() != 4) return 0;
    double area = 0.0;
    area += vertices[0].first * vertices[1].second - vertices[1].first * vertices[0].second;
    area += vertices[1].first * vertices[2].second - vertices[2].first * vertices[1].second;
    area += vertices[2].first * vertices[3].second - vertices[3].first * vertices[2].second;
    area += vertices[3].first * vertices[0].second - vertices[0].first * vertices[3].second;
    return std::abs(area) / 2.0;
}

void Trapezoid::print(std::ostream& os) const {
    os << "Trapezoid vertices: ";
    for (const auto& vertex : vertices) {
        os << "(" << vertex.first << ", " << vertex.second << ") ";
    }
}

void Trapezoid::read(std::istream& is) {
    vertices.clear();
    std::cout << "Enter 4 vertices of the trapezoid (x y): ";
    for (int i = 0; i < 4; ++i) {
        double x, y;
        is >> x >> y;
        vertices.emplace_back(x, y);
    }
}

void Trapezoid::scale(double factor) {
    auto center = getCenter();
    for (auto& vertex : vertices) {
        vertex.first = center.first + (vertex.first - center.first) * factor;
        vertex.second = center.second + (vertex.second - center.second) * factor;
    }
}
