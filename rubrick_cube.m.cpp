#include <stdio.h>
#include "cube_core/face.h"

int main()
{
    printf("Hello, from rubrick_cube!\n");
    Face<'U',3> f{};
    Face<'B',5> bb{};
    std::cout << f;
    std::cout << bb;
}
