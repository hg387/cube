#include "gtest/gtest.h"
#include "../face.h"
#include <sstream>
#include <string>


TEST(CubeCoreTest, ConstructorTest){
    Face<'X',3> f{};
    std::stringstream ss;
    ss << f;
    std::string f_text = ss.str();
    std::string expected_text = "+------------+\n"
                                "| X1  X2  X3 |\n"
                                "| X4  X5  X6 |\n"
                                "| X7  X8  X9 |\n"
                                "+------------+\n";
    EXPECT_EQ(expected_text, f_text);
}

TEST(CubeCoreTest, FaceClockwiseTest){
    Face<'X',3> f{};
    f.rotateFaceClockwise();
    std::stringstream ss;
    ss << f;
    std::string f_text = ss.str();
    std::string expected_text = "+------------+\n"
                                "| X7  X4  X1 |\n"
                                "| X8  X5  X2 |\n"
                                "| X9  X6  X3 |\n"
                                "+------------+\n";
    EXPECT_EQ(expected_text, f_text);
}

TEST(CubeCoreTest, FaceAntiClockwiseTest){
    Face<'X',3> f{};
    f.rotateFaceAntiClockwise();
    std::stringstream ss;
    ss << f;
    std::string f_text = ss.str();
    std::string expected_text = "+------------+\n"
                                "| X3  X6  X9 |\n"
                                "| X2  X5  X8 |\n"
                                "| X1  X4  X7 |\n"
                                "+------------+\n";
    EXPECT_EQ(expected_text, f_text);
}

TEST(CubeCoreTest, FaceRotationTest){
    Face<'X',3> f{};
    f.rotateFaceClockwise();
    f.rotateFaceAntiClockwise();
    std::stringstream ss;
    ss << f;
    std::string f_text = ss.str();
    std::string expected_text = "+------------+\n"
                                "| X1  X2  X3 |\n"
                                "| X4  X5  X6 |\n"
                                "| X7  X8  X9 |\n"
                                "+------------+\n";
    EXPECT_EQ(expected_text, f_text);
}
