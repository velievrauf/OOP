#include <gtest/gtest.h>
#include "labsf.h"  

TEST(VowelCounterTest, HandlesEmptyInput) {
    std::string input = "";
    EXPECT_EQ(countVowels(input), 0);
}

TEST(VowelCounterTest, HandlesNoVowels) {
    std::string input = "bcdfgh";
    EXPECT_EQ(countVowels(input), 0);
}

TEST(VowelCounterTest, HandlesAllVowels) {
    std::string input = "aeiou";
    EXPECT_EQ(countVowels(input), 5);
}

TEST(VowelCounterTest, HandlesMixedInput) {
    std::string input = "hello world";
    EXPECT_EQ(countVowels(input), 3);  
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
