#include "face.h"


// struct U:Face<'U',3>
// {

//     using Face<'U',3>::rotateFaceClockwise;
//     using Face<'U',3>::rotateFaceAntiClockwise;

//     void rotateClockwise(B b, R r, F f, L l){
//         rotateFaceClockwise(); 
//     }
// };

template <size_t N>
struct L:Face<'L',N>
{


};

template <size_t N>
struct R:Face<'R',N>
{


};

template <size_t N>
struct F:Face<'F',N>
{


};

template <size_t N>
struct B:Face<'B',N>
{


};

template <size_t N>
struct D:Face<'D',N>
{

    using Face<'D',N>::rotateFaceClockwise;
    using Face<'D',N>::rotateFaceAntiClockwise;

    void rotateClockwise(F<N>& f, R<N>& r, B<N>& b, L<N>& l){
        rotateFaceClockwise();

        std::string tmp[N] = f.values[N-1];
        f.values[N-1] = l.values[N-1];
        l.values[N-1] = b.values[N-1];
        b.values[N-1] = r.values[N-1];
        r.values[N-1] = tmp; 
    }

    void rotateAntiClockwise(F<N>& f, R<N>& r, B<N>& b, L<N>& l){
        rotateFaceAntiClockwise();

        std::string tmp[N] = f.values[N-1];
        f.values[N-1] = r.values[N-1];
        r.values[N-1] = b.values[N-1];
        b.values[N-1] = l.values[N-1];
        l.values[N-1] = tmp; 
    }

};

template <size_t N>
struct U:Face<'U',N>
{

    using Face<'U',N>::rotateFaceClockwise;
    using Face<'U',N>::rotateFaceAntiClockwise;

    void rotateClockwise(B<N>& b, R<N>& r, F<N>& f, L<N>& l){
        rotateFaceClockwise();

        // std::string tmp[N] = b.values[0];
        // b.values[0] = l.values[0];
        // l.values[0] = f.values[0];
        // f.values[0] = r.values[0];
        // r.values[0] = tmp; 
        std::string tmp[N];
        std::copy(std::begin(b.values[0]), std::end(b.values[0]), std::begin(tmp));
        std::copy(std::begin(l.values[0]), std::end(l.values[0]), std::begin(b.values[0]));
        std::copy(std::begin(f.values[0]), std::end(f.values[0]), std::begin(l.values[0]));
        std::copy(std::begin(r.values[0]), std::end(r.values[0]), std::begin(f.values[0]));
        std::copy(std::begin(tmp), std::end(tmp), std::begin(r.values[0]));
        
    }

    void rotateAntiClockwise(B<N>& b, R<N>& r, F<N>& f, L<N>& l){
        rotateFaceAntiClockwise();

        // std::string tmp[N] = b.values[0];
        // b.values[0] = r.values[0];
        // r.values[0] = f.values[0];
        // f.values[0] = l.values[0];
        // l.values[0] = tmp; 

        std::string tmp[N];
        std::copy(std::begin(b.values[0]), std::end(b.values[0]), std::begin(tmp));
        std::copy(std::begin(r.values[0]), std::end(r.values[0]), std::begin(b.values[0]));
        std::copy(std::begin(f.values[0]), std::end(f.values[0]), std::begin(r.values[0]));
        std::copy(std::begin(l.values[0]), std::end(l.values[0]), std::begin(f.values[0]));
        std::copy(std::begin(tmp), std::end(tmp), std::begin(l.values[0]));
    }
};
/*
D Initial stage:

        [2,0] [2,1] [2,2]

    [2,2]               [2,0]
    [2,1]               [2,1]
    [2,0]               [2,2]

        [2,2] [2,1] [2,0]

D - Clockwise: F -> R -> B -> L -> F
D - Anti-clockwise: F <- R <- B <- L <- F

U Initial stage:

        [0,2] [0,1] [0,0]

    [0,0]               [0,2]
    [0,1]               [0,1]
    [0,2]               [0,0]

        [0,0] [0,1] [0,2]

U - Clockwise: B -> R -> F -> L -> B
U - Anti-clockwise: B <- R <- F <- L <- B
*/