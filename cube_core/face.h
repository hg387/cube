#pragma once
#include <string.h>
#include <iostream>
#include <iomanip>

template <char C, std::size_t N>
struct Face
{
    public:
        std::string values[N][N];

        Face() noexcept{
            int counter = 1;
            for (int i=0; i!=N; ++i){
                for (int j=0; j!=N; ++j){
                    values[i][j] = std::string(1,C);
                    values[i][j] += std::to_string(counter);
                    ++counter;
                }
            }
        }

        template <char c, std::size_t n>
        friend std::ostream& operator<<(std::ostream& os, const Face<c,n>& face);

        void rotateFaceClockwise() noexcept{
          for (int i=0; i!=N/2; ++i){
                for (int j=i; j!=N-i-1; ++j){
                  std::string tmp = values[i][j];
                  values[i][j] = values[N - 1 - j][i];
                  values[N - 1 - j][i] = values[N - 1 - i][N - 1 - j];
                  values[N - 1 - i][N - 1 - j] = values[j][N - 1 - i];
                  values[j][N - 1 - i] = tmp;
                }
            }
        }

        void rotateFaceAntiClockwise() noexcept{
          for (int i=0; i!=N/2; ++i){
                for (int j=i; j!=N-i-1; ++j){
                  std::string tmp = values[i][j];
                  values[i][j] = values[j][N - 1 - i];
                  values[j][N - 1 - i] = values[N - 1 - i][N - 1 - j];
                  values[N - 1 - i][N - 1 - j] = values[N - 1 - j][i];
                  values[N - 1 - j][i] = tmp;
                }
            }
        }
};

template <char c, std::size_t n>
std::ostream& operator<<(std::ostream& os, const Face<c,n>& face){
    os << "+" << std::setfill('-') << std::setw(4*n+1) << "+" << std::endl;
    for (int i=0; i!=n; ++i){
        os << "| ";
        for (int j=0; j!=n; ++j){
            if (j != 0) os << std::setfill(' ') << std::setw(4) << face.values[i][j];
            else os << face.values[i][j];      
        }
        os << " |" << std::endl;
    }
    os << "+" << std::setfill('-') << std::setw(4*n+1) << "+" << std::endl; 

    return os;
}

/*
                +------------+
 1              | U1  U2  U3 |
                |            |
 2              | U4  U5  U6 |
                |            |
 3              | U7  U8  U9 |
   +------------+------------+------------+------------+
 4 | L1  L2  L3 | F1  F2  F3 | R1  R2  R3 | B1  B2  B3 |
   |            |            |            |            |
 5 | L4  L5  L6 | F4  F5  F6 | R4  R5  R6 | B4  B5  B6 |
   |            |            |            |            |
 6 | L7  L8  L9 | F7  F8  F9 | R7  R8  R9 | B7  B8  B9 |
   +------------+------------+------------+------------+
 7              | D1  D2  D3 |
                |            |
 8              | D4  D5  D6 |
                |            |
 9              | D7  D8  D9 |
                +------------+
*/