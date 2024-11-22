#include <iostream>
#include <vector>
#include <memory>
#include "figure.h"
#include "trapezoid.h"
#include "rhombus.h"
#include "pentagon.h"

int main() {
    std::vector<std::shared_ptr<Figure>> figures;

    while (true) {
        std::cout << "Choose a figure to add:\n"
                  << "1. Trapezoid\n"
                  << "2. Rhombus\n"
                  << "3. Pentagon\n"
                  << "4. Scale a figure\n"
                  << "0. Exit\n";

        int choice;
        std::cin >> choice;

        if (choice == 0) break;

        if (choice == 4) {
            std::cout << "Enter the index of the figure to scale (1-" << figures.size() << "): ";
            int index;
            std::cin >> index;

            if (index < 1 || index > figures.size()) {
                std::cout << "Invalid index!\n";
                continue;
            }

            std::cout << "Enter scaling factor: ";
            double factor;
            std::cin >> factor;

            figures[index - 1]->scale(factor);
            std::cout << "Figure scaled successfully.\n";
            continue;
        }

        std::shared_ptr<Figure> figure;

        switch (choice) {
            case 1:
                figure = std::make_shared<Trapezoid>();
                break;
            case 2:
                figure = std::make_shared<Rhombus>();
                break;
            case 3:
                figure = std::make_shared<Pentagon>();
                break;
            default:
                std::cout << "Invalid choice!\n";
                continue;
        }

        figure->read(std::cin);
        figures.push_back(figure);
    }

    std::cout << "\nFigures in the array:\n";
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Figure " << (i + 1) << ":\n";
        figures[i]->print(std::cout);
        std::cout << "\nCenter: (" << figures[i]->getCenter().first << ", " << figures[i]->getCenter().second << ")\n";
        std::cout << "Area: " << figures[i]->getArea() << "\n\n";
    }

    return 0;
}
