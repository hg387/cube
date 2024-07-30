#include "gtest/gtest.h"
#include "../cube.h"

class CubeTest: public testing::Test{
    protected:
        Cube<3> cube{};

        ::U<3> UInit{};
        ::D<3> DInit{};
        ::F<3> FInit{};
        ::B<3> BInit{};
        ::L<3> LInit{};
        ::R<3> RInit{};
};

TEST_F(CubeTest, CubeClockwiseAntiClockwiseTest){
    cube.make_move('U',0);
    cube.make_move('D',0);
    cube.make_move('L',1);
    cube.make_move('L',0);
    cube.make_move('D',1);
    cube.make_move('U',1);

    EXPECT_TRUE(UInit==cube.U);
    EXPECT_TRUE(LInit==cube.L);
    EXPECT_TRUE(FInit==cube.F);
    EXPECT_TRUE(RInit==cube.R);
    EXPECT_TRUE(BInit==cube.B);
    EXPECT_TRUE(DInit==cube.D);
}