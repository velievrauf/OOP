#include <iostream>
#include <vector>
#include "four.h"

int main() {
    try {
        std::cout << "Enter the first unsigned integer (in decimal): ";
        unsigned int num1;
        std::cin >> num1;
        Four fourNum1(num1);

        std::cout << "Enter the second unsigned integer (in decimal): ";
        unsigned int num2;
        std::cin >> num2;
        Four fourNum2(num2);

        // Сложение
        Four sum = fourNum1 + fourNum2;
        std::cout << "Sum in quaternary: ";
        sum.print();

        // Вычитание
        try {
            Four diff = fourNum1 - fourNum2;
            std::cout << "Difference in quaternary: ";
            diff.print();
        } catch (const std::exception& e) {
            std::cerr << "Subtraction error: " << e.what() << std::endl;
        }

        // Сравнение
        std::cout << "Comparison results:" << std::endl;
        std::cout << "First > Second: " << (fourNum1 > fourNum2 ? "Yes" : "No") << std::endl;
        std::cout << "First < Second: " << (fourNum1 < fourNum2 ? "Yes" : "No") << std::endl;
        std::cout << "First == Second: " << (fourNum1 == fourNum2 ? "Yes" : "No") << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
