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

        ::U<3> UInit{};
        ::D<3> DInit{};
        ::F<3> FInit{};
        ::B<3> BInit{};
        ::L<3> LInit{};
        ::R<3> RInit{};
};

TEST_F(CubeTest, UpRotationTest) {
    U.rotateClockwise(B, R, F, L);
    U.rotateAntiClockwise(B, R, F, L);
    EXPECT_TRUE(UInit==U);
    EXPECT_TRUE(LInit==L);
    EXPECT_TRUE(FInit==F);
    EXPECT_TRUE(RInit==R);
    EXPECT_TRUE(BInit==B);
    EXPECT_TRUE(DInit==D);
}

TEST_F(CubeTest, DownRotationTest) {
    D.rotateClockwise(F, R, B, L);
    D.rotateAntiClockwise(F, R, B, L);
    EXPECT_TRUE(UInit==U);
    EXPECT_TRUE(LInit==L);
    EXPECT_TRUE(FInit==F);
    EXPECT_TRUE(RInit==R);
    EXPECT_TRUE(BInit==B);
    EXPECT_TRUE(DInit==D);
}

TEST_F(CubeTest, FrontRotationTest) {
    F.rotateClockwise(U, R, D, L);
    F.rotateAntiClockwise(U, R, D, L);
    EXPECT_TRUE(UInit==U);
    EXPECT_TRUE(LInit==L);
    EXPECT_TRUE(FInit==F);
    EXPECT_TRUE(RInit==R);
    EXPECT_TRUE(BInit==B);
    EXPECT_TRUE(DInit==D);
}

TEST_F(CubeTest, LeftRotationTest) {
    L.rotateClockwise(U, F, D, B);
    L.rotateAntiClockwise(U, F, D, B);
    EXPECT_TRUE(UInit==U);
    EXPECT_TRUE(LInit==L);
    EXPECT_TRUE(FInit==F);
    EXPECT_TRUE(RInit==R);
    EXPECT_TRUE(BInit==B);
    EXPECT_TRUE(DInit==D);
}

TEST_F(CubeTest, RightRotationTest) {
    R.rotateClockwise(U, B, D, F);
    R.rotateAntiClockwise(U, B, D, F);
    EXPECT_TRUE(UInit==U);
    EXPECT_TRUE(LInit==L);
    EXPECT_TRUE(FInit==F);
    EXPECT_TRUE(RInit==R);
    EXPECT_TRUE(BInit==B);
    EXPECT_TRUE(DInit==D);
}

TEST_F(CubeTest, BackRotationTest) {
    B.rotateClockwise(U, L, D, R);
    B.rotateAntiClockwise(U, L, D, R);
    EXPECT_TRUE(UInit==U);
    EXPECT_TRUE(LInit==L);
    EXPECT_TRUE(FInit==F);
    EXPECT_TRUE(RInit==R);
    EXPECT_TRUE(BInit==B);
    EXPECT_TRUE(DInit==D);
}