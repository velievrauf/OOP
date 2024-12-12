#include <iostream>
#include <string>
#include "labsf.h"

int main() {
    std::string input;
    
    std::cout << "Enter your string: ";
    std::getline(std::cin, input);
    
    int vowelCount = countVowels(input);
    
    std::cout << "The number of vowels: " << vowelCount << std::endl;
    
    return 0;
}
