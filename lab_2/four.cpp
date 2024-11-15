#include "four.h"
#include <algorithm>
#include <stdexcept>

Four::Four() : digits(1, 0) {}

Four::Four(const std::vector<unsigned char>& digits) : digits(digits) {
    normalize();
}

Four::Four(unsigned int number) {
    while (number > 0) {
        digits.push_back(number % 4);
        number /= 4;
    }
    if (digits.empty()) {
        digits.push_back(0);
    }
}

Four Four::operator+(const Four& other) const {
    Four result;
    result.digits.clear();
    unsigned char carry = 0;
    size_t maxSize = std::max(digits.size(), other.digits.size());

    for (size_t i = 0; i < maxSize || carry; ++i) {
        unsigned char sum = carry;
        if (i < digits.size()) sum += digits[i];
        if (i < other.digits.size()) sum += other.digits[i];
        result.digits.push_back(sum % 4);  
        carry = sum / 4;  
    }

    result.normalize(); 
    return result;
}

Four Four::operator-(const Four& other) const {
    if (*this < other) throw std::invalid_argument("Result would be negative");

    Four result;
    result.digits.clear();
    unsigned char borrow = 0;

    for (size_t i = 0; i < digits.size(); ++i) {
        int diff = digits[i] - borrow - (i < other.digits.size() ? other.digits[i] : 0);
        borrow = diff < 0;
        result.digits.push_back((diff + 4) % 4);
    }

    result.normalize();
    return result;
}

Four& Four::operator=(const Four& other) {
    digits = other.digits;
    return *this;
}

bool Four::operator==(const Four& other) const {
    return digits == other.digits;
}

bool Four::operator!=(const Four& other) const {
    return !(*this == other);
}

bool Four::operator<(const Four& other) const {
    if (digits.size() != other.digits.size())
        return digits.size() < other.digits.size();
    for (size_t i = digits.size(); i-- > 0; ) {
        if (digits[i] != other.digits[i])
            return digits[i] < other.digits[i];
    }
    return false;
}

bool Four::operator>(const Four& other) const {
    return other < *this;
}

bool Four::operator<=(const Four& other) const {
    return !(other < *this);
}

bool Four::operator>=(const Four& other) const {
    return !(*this < other);
}

void Four::print() const {
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
        std::cout << static_cast<int>(*it);
    }
    std::cout << std::endl;
}

void Four::normalize() {
    while (digits.size() > 1 && digits.back() == 0) {
        digits.pop_back();
    }
}
