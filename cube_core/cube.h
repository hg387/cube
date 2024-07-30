#pragma once
#include "face.cpp"
#include "face.h"
template <size_t N>
struct Cube{
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
            if (j != 0) os << std::setfill(' ') << std::setw(3+digits) << std::right << cube.R.values[i][j];
            else os << std::setfill(' ') << std::setw(1+digits) << std::right << cube.R.values[i][j];      
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