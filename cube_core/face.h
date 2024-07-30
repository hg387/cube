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

        bool operator==(const Face<C,N>& face) const{
          for (int i=0; i!=N; ++i){
            for (int j=0; j!=N; ++j){
              if (values[i][j] != face.values[i][j]) return false;
            }
          }

          return true;
        }

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

        template <char c1, char c2>
        void copyColToRowReverse(Face<c1,N>& f1, int col, Face<c2,N>& f2, int row) noexcept{
          for (int j=0; j!=N; ++j){
            f2.values[row][N-1-j] = f1.values[j][col];
          }
        }

        template <char c1, char c2>
        void copyColToRow(Face<c1,N>& f1, int col, Face<c2,N>& f2, int row) noexcept{
          for (int j=0; j!=N; ++j){
            f2.values[row][j] = f1.values[j][col];
          }
        }

        template <char c1, char c2>
        void copyRowToCol(Face<c1,N>& f1, int row, Face<c2,N>& f2, int col) noexcept{
          for (int i=0; i!=N; ++i){
            f2.values[i][col] = f1.values[row][i];
          }
        }

        template <char c1, char c2>
        void copyRowToColReverse(Face<c1,N>& f1, int row, Face<c2,N>& f2, int col) noexcept{
          for (int i=0; i!=N; ++i){
            f2.values[N-1-i][col] = f1.values[row][i];
          }
        }

        template <char c1, char c2>
        void copyColToCol(Face<c1,N>& f1, int col1, Face<c2,N>& f2, int col2) noexcept{
          for (int i=0; i!=N; ++i){
            f2.values[i][col2] = f1.values[i][col1];
          }
        }

        template <char c1, char c2>
        void copyColToColReverse(Face<c1,N>& f1, int col1, Face<c2,N>& f2, int col2) noexcept{
          for (int i=0; i!=N; ++i){
            f2.values[N-1-i][col2] = f1.values[i][col1];
          }
        }
};

template <char c, std::size_t n>
std::ostream& operator<<(std::ostream& os, const Face<c,n>& face){
    int digits = std::to_string(n*n).size();
    os << "+" << std::setfill('-') << std::setw(((3+digits)*n)+1) << "+" << std::endl;
    for (int i=0; i!=n; ++i){
        os << "| ";
        for (int j=0; j!=n; ++j){
            if (j != 0) os << std::setfill(' ') << std::setw(3+digits) << std::right << face.values[i][j];
            else os << std::setfill(' ') << std::setw(1+digits) << std::right << face.values[i][j];      
        }
        os << " |" << std::endl;
        if (i != (n-1)) os << "|" << std::setfill(' ') << std::setw(((3+digits)*n)+1) << "|" << std::endl;
    }
    os << "+" << std::setfill('-') << std::setw(((3+digits)*n)+1) << "+" << std::endl; 

    return os;
}