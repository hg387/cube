#include "gtest/gtest.h"
#include "../cube.h"

TEST(CubeTest, DifferentSizeCubeTest){
    //Face<'X',6> f1{};
    Cube<3> c3{};
    //std::cout << f1;
    std::cout << c3;
    EXPECT_TRUE(true);
}