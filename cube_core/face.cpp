#include "face.h"

template <size_t N>
struct L:Face<'L',N>
{

    using Face<'L',N>::rotateFaceClockwise;
    using Face<'L',N>::rotateFaceAntiClockwise;

    void rotateClockwise(Face<'U',N>& u, Face<'F',N>& f, Face<'D',N>& d, Face<'B',N>& b){
        rotateFaceClockwise();

        //U -> F -> D -> B -> U 

        std::string tmp[N];
        for (int i=0; i!=N; ++i){
            tmp[i] = u.values[i][0];
        }
        Face<'L',N>::template copyColToColReverse<'B','U'>(b, N-1, u, 0);
        Face<'L',N>::template copyColToColReverse<'D','B'>(d, 0, b, N-1);
        Face<'L',N>::template copyColToCol<'F','D'>(f, 0, d, 0);
        for (int i=0; i!=N; ++i){
            f.values[i][0] = tmp[i];
        }
        
    }

    void rotateAntiClockwise(Face<'U',N>& u, Face<'F',N>& f, Face<'D',N>& d, Face<'B',N>& b){
        rotateFaceAntiClockwise();

        //U <- F <- D <- B <- U

        std::string tmp[N];
        for (int i=0; i!=N; ++i){
            tmp[i] = u.values[i][0];
        }
        Face<'L',N>::template copyColToCol<'F','U'>(f, 0, u, 0);
        Face<'L',N>::template copyColToCol<'D','F'>(d, 0, f, 0);
        Face<'L',N>::template copyColToColReverse<'B','D'>(b, N-1, d, 0);
        for (int i=0; i!=N; ++i){
            b.values[N-1-i][0] = tmp[i];
        }
    }

};

template <size_t N>
struct R:Face<'R',N>
{

    using Face<'R',N>::rotateFaceClockwise;
    using Face<'R',N>::rotateFaceAntiClockwise;

    void rotateClockwise(Face<'U',N>& u, Face<'B',N>& b, Face<'D',N>& d, Face<'F',N>& f){
        rotateFaceClockwise();

        //U -> B -> D -> F -> U

        std::string tmp[N];
        for (int i=0; i!=N; ++i){
            tmp[i] = u.values[N-1-i][N-1];
        }
        Face<'R',N>::template copyColToCol<'F','U'>(f, N-1, u, N-1);
        Face<'R',N>::template copyColToCol<'D','F'>(d, N-1, f, N-1);
        Face<'R',N>::template copyColToColReverse<'B','D'>(b, 0, d, N-1);
        for (int i=0; i!=N; ++i){
            b.values[N-1-i][0] = tmp[i];
        }
    }

    void rotateAntiClockwise(Face<'U',N>& u, Face<'B',N>& b, Face<'D',N>& d, Face<'F',N>& f){
        rotateFaceAntiClockwise();

        //U <- B <- D <- F <- U

        std::string tmp[N];
        for (int i=0; i!=N; ++i){
            tmp[i] = u.values[N-1-i][N-1];
        }
        Face<'R',N>::template copyColToColReverse<'B','U'>(b, 0, u, N-1);
        Face<'R',N>::template copyColToColReverse<'D','B'>(d, N-1, b, 0);
        Face<'R',N>::template copyColToCol<'F','D'>(f, N-1, d, N-1);
        for (int i=0; i!=N; ++i){
            f.values[i][0] = tmp[i];
        }
    }
};

template <size_t N>
struct F:Face<'F',N>
{
    using Face<'F',N>::rotateFaceClockwise;
    using Face<'F',N>::rotateFaceAntiClockwise;

    void rotateClockwise(Face<'U',N>& u, Face<'R',N>& r, Face<'D',N>& d, Face<'L',N>& l){
        rotateFaceClockwise();

        //U -> R -> D -> L -> U 

        std::string tmp[N];
        std::copy(std::begin(u.values[N-1]), std::end(u.values[N-1]), std::begin(tmp));
        Face<'F',N>::template copyColToRowReverse<'L','U'>(l, N-1, u, N-1);
        Face<'F',N>::template copyRowToCol<'D','L'>(d, 0, l, N-1);
        Face<'F',N>::template copyColToRowReverse<'R','D'>(r, 0, d, 0);
        for (int i=0; i!=N; ++i){
            r.values[i][0] = tmp[i];
        }
        
    }

    void rotateAntiClockwise(Face<'U',N>& u, Face<'R',N>& r, Face<'D',N>& d, Face<'L',N>& l){
        rotateFaceAntiClockwise();

        //U <- R <- D <- L <- U 

        std::string tmp[N];
        std::copy(std::begin(u.values[N-1]), std::end(u.values[N-1]), std::begin(tmp));
        Face<'F',N>::template copyColToRow<'R','U'>(r, 0, u, N-1);
        Face<'F',N>::template copyRowToColReverse<'D','R'>(d, 0, r, 0);
        Face<'F',N>::template copyColToRow<'L','D'>(l, N-1, d, 0);
        for (int i=0; i!=N; ++i){
            l.values[N-1-i][N-1] = tmp[i];
        }
        
    }

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

    void rotateClockwise(Face<'F',N>& f, Face<'R',N>& r, Face<'B',N>& b, Face<'L',N>& l){
        rotateFaceClockwise();
        
        // std::string tmp[N] = f.values[N-1];
        // f.values[N-1] = l.values[N-1];
        // l.values[N-1] = b.values[N-1];
        // b.values[N-1] = r.values[N-1];
        // r.values[N-1] = tmp; 

        std::string tmp[N];
        std::copy(std::begin(f.values[N-1]), std::end(f.values[N-1]), std::begin(tmp));
        std::copy(std::begin(l.values[N-1]), std::end(l.values[N-1]), std::begin(f.values[N-1]));
        std::copy(std::begin(b.values[N-1]), std::end(b.values[N-1]), std::begin(l.values[N-1]));
        std::copy(std::begin(r.values[N-1]), std::end(r.values[N-1]), std::begin(b.values[N-1]));
        std::copy(std::begin(tmp), std::end(tmp), std::begin(r.values[N-1]));
    }

    void rotateAntiClockwise(Face<'F',N>& f, Face<'R',N>& r, Face<'B',N>& b, Face<'L',N>& l){
        rotateFaceAntiClockwise();

        // std::string tmp[N] = f.values[N-1];
        // f.values[N-1] = r.values[N-1];
        // r.values[N-1] = b.values[N-1];
        // b.values[N-1] = l.values[N-1];
        // l.values[N-1] = tmp; 

        std::string tmp[N];
        std::copy(std::begin(f.values[N-1]), std::end(f.values[N-1]), std::begin(tmp));
        std::copy(std::begin(r.values[N-1]), std::end(r.values[N-1]), std::begin(f.values[N-1]));
        std::copy(std::begin(b.values[N-1]), std::end(b.values[N-1]), std::begin(r.values[N-1]));
        std::copy(std::begin(l.values[N-1]), std::end(l.values[N-1]), std::begin(b.values[N-1]));
        std::copy(std::begin(tmp), std::end(tmp), std::begin(l.values[N-1]));
    }

};

template <size_t N>
struct U:Face<'U',N>
{

    using Face<'U',N>::rotateFaceClockwise;
    using Face<'U',N>::rotateFaceAntiClockwise;

    void rotateClockwise(Face<'B',N>& b, Face<'R',N>& r, Face<'F',N>& f, Face<'L',N>& l){
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

    void rotateAntiClockwise(Face<'B',N>& b, Face<'R',N>& r, Face<'F',N>& f, Face<'L',N>& l){
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
R Initial stage:

        [2,2] [1,2] [0,2]

    [0,2]               [0,0]
    [1,2]               [1,0]
    [2,2]               [2,0]

        [0,2] [1,2] [2,2]

R - Clockwise: U -> B -> D -> F -> U
R - Anti-clockwise: U <- B <- D <- F <- U


L Initial stage:

        [0,0] [1,0] [2,0]

    [0,2]               [0,0]
    [1,2]               [1,0]
    [2,2]               [2,0]

        [2,0] [1,0] [0,0]

L - Clockwise:  U -> F -> D -> B -> U
L - Anti-clockwise: U <- F <- D <- B <- U


F Initial stage:

        [2,0] [2,1] [2,2]

    [0,2]               [0,0]
    [1,2]               [1,0]
    [2,2]               [2,0]

        [0,0] [0,1] [0,2]

F - Clockwise: U -> R -> D -> L -> U
F - Anti-clockwise: U <- R <- D <- L <- U


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