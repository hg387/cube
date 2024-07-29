#include "gtest/gtest.h"
#include "../face.h"
#include <sstream>
#include <string>


TEST(CubeCoreTest, ConstructorTest){
    Face<'U',3> f{};
    std::stringstream ss;
    ss << f;
    std::string f_text = ss.str();
    std::string expected_text = "+------------+\n"
                                "| U1  U2  U3 |\n"
                                "| U4  U5  U6 |\n"
                                "| U7  U8  U9 |\n"
                                "+------------+\n";
    EXPECT_EQ(expected_text, f_text);
}
