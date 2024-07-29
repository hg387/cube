#include "face.h"

template <char C, std::size_t N>
struct U:Face<C,N>
{
    U(){
        Face<C,N>::Face();
    }
};