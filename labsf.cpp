#include <iostream>
#include <string>
#include <set>

int countVowels(const std::string& input) {
    std::set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    int vowelCount = 0;
    
    for (char ch : input) {
        if (vowels.count(ch)) {
            vowelCount++;
        }
    }
    
    return vowelCount;
}

int main() {
    std::string input;
    
    std::cout << "Enter your string: ";
    std::getline(std::cin, input);
    
    int vowelCount = countVowels(input);
    
    std::cout << "The number of vowels: " << vowelCount << std::endl;
    
    return 0;
}
