#include "gtest/gtest.h"
#include "../include/Hailstone.h"
using sequence::satisfiesHailstone;

TEST(HailstoneTests,ifHailstoneEqualtoZero){
    EXPECT_FALSE(satisfiesHailstone(0));
}

TEST(HailstoneTests,ifHailstoneEqualtoOne){
    EXPECT_TRUE(satisfiesHailstone(1));
}

TEST(HailstoneTests,ifHailstoneEven){
    EXPECT_TRUE(satisfiesHailstone(4));
}

TEST(HailstoneTests,ifHailstoneOdd){
    EXPECT_TRUE(satisfiesHailstone(3));
}