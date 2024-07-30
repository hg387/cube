#pragma once
#include "face.cpp"
#include "face.h"
#include <unordered_set>

template <size_t N>
struct Cube{
    inline static const std::unordered_set<char> faces{'U', 'L', 'F', 'B', 'R', 'D'};
    inline static const std::unordered_set<int> rotations{0, 1};

    Cube(){
    }

    U<N> U{};
    D<N> D{};
    F<N> F{};
    B<N> B{};
    L<N> L{};
    R<N> R{};

    template <std::size_t n>
    friend std::ostream& operator<<(std::ostream& os, const Cube<n>& cube);

    void make_move(char face, int rotation){
        if (!faces.contains(face) || !rotations.contains(rotation)) return;

        switch (face) {
            case 'U':
                if (rotation == 0) U.rotateClockwise(B, R, F, L);
                else U.rotateAntiClockwise(B, R, F, L);
                break;
            case 'D':
                if (rotation == 0) D.rotateClockwise(F, R, B, L);
                else D.rotateAntiClockwise(F, R, B, L);
                break;
            case 'F':
                if (rotation == 0) F.rotateClockwise(U, R, D, L);
                else F.rotateAntiClockwise(U, R, D, L);
                break;
            case 'L':
                if (rotation == 0) L.rotateClockwise(U, F, D, B);
                else L.rotateAntiClockwise(U, F, D, B);
                break;
            case 'R':
                if (rotation == 0) R.rotateClockwise(U, B, D, F);
                else R.rotateAntiClockwise(U, B, D, F);
                break;
            case 'B':
                if (rotation == 0) B.rotateClockwise(U, L, D, R);
                else B.rotateAntiClockwise(U, L, D, R);
                break;
        }
    }
};

template <std::size_t n>
std::ostream& operator<<(std::ostream& os, const Cube<n>& cube){
    int digits = std::to_string(n*n).size();
    os << std::setfill(' ') << std::setw(((3+digits)*n)+1) << "";
    os << "+" << std::setfill('-') << std::setw(((3+digits)*n)+1) << "+" << std::endl;
    for (int i=0; i!=n; ++i){
        os << std::setfill(' ') << std::setw(((3+digits)*n)+1) << "" ;
        os << "| ";
        for (int j=0; j!=n; ++j){
            if (j != 0) os << std::setfill(' ') << std::setw(3+digits) << std::right << cube.U.values[i][j];
            else os << std::setfill(' ') << std::setw(1+digits) << std::right << cube.U.values[i][j];      
        }
        os << " |" << std::endl;
        if (i != (n-1)){
            os << std::setfill(' ') << std::setw(((3+digits)*n)+1) << "";
            os << "|" << std::setfill(' ') << std::setw(((3+digits)*n)+1) << "|" << std::endl;
        }
    }

    os << "+";
    for (int i=0; i!=4; ++i){
        os << std::setfill('-') << std::setw(((3+digits)*n)+1) << "+";
    }
    os << std::endl;

    for (int i=0; i!=n; ++i){
        os << "| ";
        for (int j=0; j!=n; ++j){
            if (j != 0) os << std::setfill(' ') << std::setw(3+digits) << std::right << cube.L.values[i][j];
            else os << std::setfill(' ') << std::setw(1+digits) << std::right << cube.L.values[i][j];      
        }
        os << " | ";
        
        for (int j=0; j!=n; ++j){
            if (j != 0) os << std::setfill(' ') << std::setw(3+digits) << std::right << cube.F.values[i][j];
            else os << std::setfill(' ') << std::setw(1+digits) << std::right << cube.F.values[i][j];      
        }
        os << " | ";
        
        for (int j=0; j!=n; ++j){
            if (j != 0) os << std::setfill(' ') << std::setw(3+digits) << std::right << cube.R.values[i][j];
            else os << std::setfill(' ') << std::setw(1+digits) << std::right << cube.R.values[i][j];      
        }
        os << " | ";
        
        for (int j=0; j!=n; ++j){
            if (j != 0) os << std::setfill(' ') << std::setw(3+digits) << std::right << cube.B.values[i][j];
            else os << std::setfill(' ') << std::setw(1+digits) << std::right << cube.B.values[i][j];      
        }
        os << " | " << std::endl;

        if (i != (n-1)){
            os << "|";
            for (int i=0; i!=4; ++i){
                os << std::setfill(' ') << std::setw(((3+digits)*n)+1) << "|";
            }
            os << std::endl;
        }
    }

    os << "+";
    for (int i=0; i!=4; ++i){
        os << std::setfill('-') << std::setw(((3+digits)*n)+1) << "+";
    }
    os << std::endl;

    
    for (int i=0; i!=n; ++i){
        os << std::setfill(' ') << std::setw(((3+digits)*n)+1) << "" ;
        os << "| ";
        for (int j=0; j!=n; ++j){
            if (j != 0) os << std::setfill(' ') << std::setw(3+digits) << std::right << cube.D.values[i][j];
            else os << std::setfill(' ') << std::setw(1+digits) << std::right << cube.D.values[i][j];      
        }
        os << " |" << std::endl;
        if (i != (n-1)){
            os << std::setfill(' ') << std::setw(((3+digits)*n)+1) << "";
            os << "|" << std::setfill(' ') << std::setw(((3+digits)*n)+1) << "|" << std::endl;
        }
    }
    os << std::setfill(' ') << std::setw(((3+digits)*n)+1) << "";
    os << "+" << std::setfill('-') << std::setw(((3+digits)*n)+1) << "+" << std::endl; 

    return os;
}