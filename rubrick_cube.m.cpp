#include <iostream>
#include "cube_core/cube.h"
#include <unordered_set>

const std::string WELCOME = "Welcome to Rubrick Cube Simulator\n\n";
const std::string INPUTS =  "\nInstructions:\n"
                            "Faces should be one of these options:\n"
                            "U, L, F, B, R, D\n"
                            "\nRotations should be one of these options:\n"
                            "0 - Clockwise Rotation\n"
                            "1 - Anti-clockwise Rotation\n\n";


const std::unordered_set<char> faces{'U', 'L', 'F', 'B', 'R', 'D'};
int main()
{
    std::cout << WELCOME;
    Cube<3> cube{};
    std::cout << cube;
    std::cout << INPUTS;

    char face;
    int action;

    while (true){
        std::cout << "\nPlease enter face (U, L, F, B, R, D) to rotate:\n";
        std::cin >> face;

        while (!std::cin || !faces.contains(face)){
            std::cout << "\nError, wrong input!\n";
            std::cout << "Please enter face (U, L, F, B, R, D) to rotate:\n";
            std::cin >> face;
        }
        
        std::cout << "\nPlease enter the rotation (0 - clockwise and 1 - anti-clockwise):\n";
        std::cin >> action;
        while (!std::cin || (action != 0 && action != 1)){
            std::cout << "\nError, wrong input!\n";
            std::cout << "Please enter the rotation (0 - clockwise and 1 - anti-clockwise):\n";
            std::cin >> action;
        }

        std::cout << "\nState of Cube after the above action\n";
        cube.make_move(face, action);
        std::cout << cube;
    }

    return 0;
}
