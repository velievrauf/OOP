#ifndef FOUR_H
#define FOUR_H

#include <vector>
#include <stdexcept>
#include <iostream>

class Four {
public:
    Four();  // Конструктор по умолчанию
    Four(const std::vector<unsigned char>& digits);  // Конструктор из вектора цифр
    Four(unsigned int number);  // Конструктор из целого числа

    // Арифметические операции
    Four operator+(const Four& other) const;
    Four operator-(const Four& other) const;
    Four& operator=(const Four& other);

    // Операции сравнения
    bool operator==(const Four& other) const;
    bool operator!=(const Four& other) const;
    bool operator<(const Four& other) const;
    bool operator>(const Four& other) const;
    bool operator<=(const Four& other) const;
    bool operator>=(const Four& other) const;

    // Метод для вывода
    void print() const;

private:
    std::vector<unsigned char> digits;

    void normalize();  // Вспомогательный метод для нормализации числа
};

#endif // FOUR_H
