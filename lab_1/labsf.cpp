#include <set>
#include <string>
#include "labsf.h"

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
