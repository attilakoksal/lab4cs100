#include "gtest/gtest.h"
#include "../include/Triangle.h"
using shapes::Triangle;

//getPerimeter() getArea() getKind() are bugged


TEST(TriangleTests, testPerimeter) {
    Triangle *aTriangle = new Triangle(3,3,3);
    EXPECT_EQ (aTriangle->getPerimeter(),9);
}

TEST(TriangleTests, testArea)
{
    Triangle *aTriangle = new Triangle(3, 3, 3);
    EXPECT_EQ (aTriangle->getArea(),1.5*sqrt(11.25));
}
