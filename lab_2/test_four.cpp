#include <gtest/gtest.h>
#include "four.h"

TEST(FourTest, ConstructorFromInt) {
    Four num(10);
    EXPECT_EQ(num, Four(std::vector<unsigned char>{2, 2}));
}

TEST(FourTest, Addition) {
    Four a(3);  
    Four b(2);  
    Four expected(5);  
    EXPECT_EQ(a + b, expected);
}

TEST(FourTest, Comparison) {
    Four a(10);
    Four b(20);
    EXPECT_LT(a, b);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
