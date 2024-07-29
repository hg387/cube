#include "gtest/gtest.h"
#include "../face.h"
#include "../face.cpp"


class CubeTest: public testing::Test{
    protected:
        CubeTest(){

        }

        U<3> U{};
        D<3> D{};
        F<3> F{};
        B<3> B{};
        L<3> L{};
        R<3> R{};
};

TEST_F(CubeTest, UpRotationTest) {
    U.rotateClockwise(B, R, F, L);
    U.rotateAntiClockwise(B, R, F, L);
    std::cout << U;
    std::cout << L;
    std::cout << F;
    std::cout << R;
    std::cout << B;
    std::cout << D;
    EXPECT_EQ(0, 0);
}

TEST_F(CubeTest, DownRotationTest) {
    D.rotateClockwise(F, R, B, L);
    D.rotateAntiClockwise(F, R, B, L);
    std::cout << U;
    std::cout << L;
    std::cout << F;
    std::cout << R;
    std::cout << B;
    std::cout << D;
    EXPECT_EQ(0, 0);
}

TEST_F(CubeTest, FrontRotationTest) {
    F.rotateClockwise(U, R, D, L);
    F.rotateAntiClockwise(U, R, D, L);
    std::cout << U;
    std::cout << L;
    std::cout << F;
    std::cout << R;
    std::cout << B;
    std::cout << D;
    EXPECT_EQ(0, 0);
}

TEST_F(CubeTest, LeftRotationTest) {
    L.rotateClockwise(U, F, D, B);
    L.rotateAntiClockwise(U, F, D, B);
    std::cout << U;
    std::cout << L;
    std::cout << F;
    std::cout << R;
    std::cout << B;
    std::cout << D;
    EXPECT_EQ(0, 0);
}

TEST_F(CubeTest, RightRotationTest) {
    R.rotateClockwise(U, B, D, F);
    R.rotateAntiClockwise(U, B, D, F);
    std::cout << U;
    std::cout << L;
    std::cout << F;
    std::cout << R;
    std::cout << B;
    std::cout << D;
    EXPECT_EQ(0, 0);
}