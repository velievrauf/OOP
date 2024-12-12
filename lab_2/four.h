#ifndef FOUR_H
#define FOUR_H

#include <vector>
#include <stdexcept>
#include <iostream>

class Four {
public:
    Four();  
    Four(const std::vector<unsigned char>& digits);  
    Four(unsigned int number); 

    Four operator+(const Four& other) const;
    Four operator-(const Four& other) const;
    Four& operator=(const Four& other);

    bool operator==(const Four& other) const;
    bool operator!=(const Four& other) const;
    bool operator<(const Four& other) const;
    bool operator>(const Four& other) const;
    bool operator<=(const Four& other) const;
    bool operator>=(const Four& other) const;

    void print() const;

private:
    std::vector<unsigned char> digits;

    void normalize();  
};

#endif 
