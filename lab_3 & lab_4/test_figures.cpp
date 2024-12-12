#include "trapezoid.h"
#include "rhombus.h"
#include "pentagon.h"
#include <iostream>
#include <sstream>
#include <cassert>

void testTrapezoid() {
    Trapezoid trapezoid;
    std::istringstream input("0 0\n4 0\n3 2\n1 2\n");
    trapezoid.read(input);

    assert(std::abs(trapezoid.getArea() - 6.0) < 1e-9);

    auto center = trapezoid.getCenter();
    assert(std::abs(center.first - 2.0) < 1e-9);
    assert(std::abs(center.second - 1.0) < 1e-9);

    trapezoid.scale(2.0);
    center = trapezoid.getCenter(); 
    assert(std::abs(center.first - 2.0) < 1e-9);
    assert(std::abs(center.second - 1.0) < 1e-9);

    std::cout << "Trapezoid tests passed.\n";
}

void testRhombus() {
    Rhombus rhombus;
    std::istringstream input("0 0\n2 2\n4 0\n2 -2\n");
    rhombus.read(input);

    assert(std::abs(rhombus.getArea() - 8.0) < 1e-9);

    auto center = rhombus.getCenter();
    assert(std::abs(center.first - 2.0) < 1e-9);
    assert(std::abs(center.second - 0.0) < 1e-9);

    rhombus.scale(1.5);
    center = rhombus.getCenter(); 
    assert(std::abs(center.first - 2.0) < 1e-9);
    assert(std::abs(center.second - 0.0) < 1e-9);

    std::cout << "Rhombus tests passed.\n";
}

void testPentagon() {
    Pentagon pentagon;
    std::istringstream input("0 0\n2 3\n4 2\n3 -1\n1 -2\n");
    pentagon.read(input);

    assert(std::abs(pentagon.getArea() - 11.5) < 1e-9);

    auto center = pentagon.getCenter();
    assert(std::abs(center.first - 2.0) < 1e-9);
    assert(std::abs(center.second - 0.4) < 1e-9);

    pentagon.scale(0.5);
    center = pentagon.getCenter(); 
    assert(std::abs(center.first - 2.0) < 1e-9);
    assert(std::abs(center.second - 0.4) < 1e-9);

    std::cout << "Pentagon tests passed.\n";
}

int main() {
    testTrapezoid();
    testRhombus();
    testPentagon();
    std::cout << "All tests passed successfully.\n";
    return 0;
}
