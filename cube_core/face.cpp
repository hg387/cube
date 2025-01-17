#include "face.h"

/*
L Initial stage:
                U
        [0,0] [1,0] [2,0]

    [0,2]               [0,0]
  B [1,2]               [1,0] F
    [2,2]               [2,0]

        [2,0] [1,0] [0,0]
                D
*/
template <size_t N>
struct L : Face<'L', N>
{
    using Face<'L', N>::rotateFaceClockwise;
    using Face<'L', N>::rotateFaceAntiClockwise;

    // L - Clockwise:  U -> F -> D -> B -> U
    void rotateClockwise(Face<'U', N> &u, Face<'F', N> &f, Face<'D', N> &d, Face<'B', N> &b)
    {
        rotateFaceClockwise();

        std::string tmp[N];
        for (int i = 0; i != N; ++i)
        {
            tmp[i] = u.values[i][0];
        }
        Face<'L', N>::template copyColToColReverse<'B', 'U'>(b, N - 1, u, 0);
        Face<'L', N>::template copyColToColReverse<'D', 'B'>(d, 0, b, N - 1);
        Face<'L', N>::template copyColToCol<'F', 'D'>(f, 0, d, 0);
        for (int i = 0; i != N; ++i)
        {
            f.values[i][0] = tmp[i];
        }
    }

    // L - Anti-clockwise: U <- F <- D <- B <- U
    void rotateAntiClockwise(Face<'U', N> &u, Face<'F', N> &f, Face<'D', N> &d, Face<'B', N> &b)
    {
        rotateFaceAntiClockwise();

        std::string tmp[N];
        for (int i = 0; i != N; ++i)
        {
            tmp[i] = u.values[i][0];
        }
        Face<'L', N>::template copyColToCol<'F', 'U'>(f, 0, u, 0);
        Face<'L', N>::template copyColToCol<'D', 'F'>(d, 0, f, 0);
        Face<'L', N>::template copyColToColReverse<'B', 'D'>(b, N - 1, d, 0);
        for (int i = 0; i != N; ++i)
        {
            b.values[N - 1 - i][N - 1] = tmp[i];
        }
    }
};

/*
R Initial stage:
                U
        [2,2] [1,2] [0,2]

    [0,2]               [0,0]
  F [1,2]               [1,0] B
    [2,2]               [2,0]

        [0,2] [1,2] [2,2]
                D
*/
template <size_t N>
struct R : Face<'R', N>
{

    using Face<'R', N>::rotateFaceClockwise;
    using Face<'R', N>::rotateFaceAntiClockwise;

    // R - Clockwise: U -> B -> D -> F -> U
    void rotateClockwise(Face<'U', N> &u, Face<'B', N> &b, Face<'D', N> &d, Face<'F', N> &f)
    {
        rotateFaceClockwise();

        std::string tmp[N];
        for (int i = 0; i != N; ++i)
        {
            tmp[i] = u.values[i][N - 1];
        }
        Face<'R', N>::template copyColToCol<'F', 'U'>(f, N - 1, u, N - 1);
        Face<'R', N>::template copyColToCol<'D', 'F'>(d, N - 1, f, N - 1);
        Face<'R', N>::template copyColToColReverse<'B', 'D'>(b, 0, d, N - 1);
        for (int i = 0; i != N; ++i)
        {
            b.values[N - 1 - i][0] = tmp[i];
        }
    }

    // R - Anti-clockwise: U <- B <- D <- F <- U
    void rotateAntiClockwise(Face<'U', N> &u, Face<'B', N> &b, Face<'D', N> &d, Face<'F', N> &f)
    {
        rotateFaceAntiClockwise();

        std::string tmp[N];
        for (int i = 0; i != N; ++i)
        {
            tmp[i] = u.values[i][N - 1];
        }
        Face<'R', N>::template copyColToColReverse<'B', 'U'>(b, 0, u, N - 1);
        Face<'R', N>::template copyColToColReverse<'D', 'B'>(d, N - 1, b, 0);
        Face<'R', N>::template copyColToCol<'F', 'D'>(f, N - 1, d, N - 1);
        for (int i = 0; i != N; ++i)
        {
            f.values[i][N - 1] = tmp[i];
        }
    }
};

/*
F Initial stage:
                U
        [2,0] [2,1] [2,2]

    [0,2]               [0,0]
  L [1,2]               [1,0] R
    [2,2]               [2,0]

        [0,0] [0,1] [0,2]
                D
*/
template <size_t N>
struct F : Face<'F', N>
{
    using Face<'F', N>::rotateFaceClockwise;
    using Face<'F', N>::rotateFaceAntiClockwise;

    // F - Clockwise: U -> R -> D -> L -> U
    void rotateClockwise(Face<'U', N> &u, Face<'R', N> &r, Face<'D', N> &d, Face<'L', N> &l)
    {
        rotateFaceClockwise();

        std::string tmp[N];
        std::copy(std::begin(u.values[N - 1]), std::end(u.values[N - 1]), std::begin(tmp));
        Face<'F', N>::template copyColToRowReverse<'L', 'U'>(l, N - 1, u, N - 1);
        Face<'F', N>::template copyRowToCol<'D', 'L'>(d, 0, l, N - 1);
        Face<'F', N>::template copyColToRowReverse<'R', 'D'>(r, 0, d, 0);
        for (int i = 0; i != N; ++i)
        {
            r.values[i][0] = tmp[i];
        }
    }

    // F - Anti-clockwise: U <- R <- D <- L <- U
    void rotateAntiClockwise(Face<'U', N> &u, Face<'R', N> &r, Face<'D', N> &d, Face<'L', N> &l)
    {
        rotateFaceAntiClockwise();

        std::string tmp[N];
        std::copy(std::begin(u.values[N - 1]), std::end(u.values[N - 1]), std::begin(tmp));
        Face<'F', N>::template copyColToRow<'R', 'U'>(r, 0, u, N - 1);
        Face<'F', N>::template copyRowToColReverse<'D', 'R'>(d, 0, r, 0);
        Face<'F', N>::template copyColToRow<'L', 'D'>(l, N - 1, d, 0);
        for (int i = 0; i != N; ++i)
        {
            l.values[N - 1 - i][N - 1] = tmp[i];
        }
    }
};

/*
B Initial stage:
                U
        [0,2] [0,1] [0,0]

    [0,2]               [0,0]
  R [1,2]               [0,1] L
    [2,2]               [0,2]

        [2,2] [2,1] [2,0]
                D
*/
template <size_t N>
struct B : Face<'B', N>
{
    using Face<'B', N>::rotateFaceClockwise;
    using Face<'B', N>::rotateFaceAntiClockwise;

    // B - Clockwise: U -> L -> D -> R -> U
    void rotateClockwise(Face<'U', N> &u, Face<'L', N> &l, Face<'D', N> &d, Face<'R', N> &r)
    {
        rotateFaceClockwise();

        std::string tmp[N];
        std::copy(std::begin(u.values[0]), std::end(u.values[0]), std::begin(tmp));
        Face<'B', N>::template copyColToRow<'R', 'U'>(r, N - 1, u, 0);
        Face<'B', N>::template copyRowToColReverse<'D', 'R'>(d, N - 1, r, N - 1);
        Face<'B', N>::template copyColToRow<'L', 'D'>(l, 0, d, N - 1);
        for (int i = 0; i != N; ++i)
        {
            l.values[N - 1 - i][0] = tmp[i];
        }
    }

    // B - Anti-clockwise: U <- L <- D <- R <- U
    void rotateAntiClockwise(Face<'U', N> &u, Face<'L', N> &l, Face<'D', N> &d, Face<'R', N> &r)
    {
        rotateFaceAntiClockwise();

        std::string tmp[N];
        std::copy(std::begin(u.values[0]), std::end(u.values[0]), std::begin(tmp));
        Face<'B', N>::template copyColToRowReverse<'L', 'U'>(l, 0, u, 0);
        Face<'B', N>::template copyRowToCol<'D', 'L'>(d, N - 1, l, 0);
        Face<'B', N>::template copyColToRowReverse<'R', 'D'>(r, N - 1, d, N - 1);
        for (int i = 0; i != N; ++i)
        {
            r.values[i][N - 1] = tmp[i];
        }
    }
};

/*
D Initial stage:
                F
        [2,0] [2,1] [2,2]

    [2,2]               [2,0]
  L [2,1]               [2,1] R
    [2,0]               [2,2]

        [2,2] [2,1] [2,0]
                B
*/
template <size_t N>
struct D : Face<'D', N>
{

    using Face<'D', N>::rotateFaceClockwise;
    using Face<'D', N>::rotateFaceAntiClockwise;

    // D - Clockwise: F -> R -> B -> L -> F
    void rotateClockwise(Face<'F', N> &f, Face<'R', N> &r, Face<'B', N> &b, Face<'L', N> &l)
    {
        rotateFaceClockwise();

        std::string tmp[N];
        std::copy(std::begin(f.values[N - 1]), std::end(f.values[N - 1]), std::begin(tmp));
        std::copy(std::begin(l.values[N - 1]), std::end(l.values[N - 1]), std::begin(f.values[N - 1]));
        std::copy(std::begin(b.values[N - 1]), std::end(b.values[N - 1]), std::begin(l.values[N - 1]));
        std::copy(std::begin(r.values[N - 1]), std::end(r.values[N - 1]), std::begin(b.values[N - 1]));
        std::copy(std::begin(tmp), std::end(tmp), std::begin(r.values[N - 1]));
    }

    // D - Anti-clockwise: F <- R <- B <- L <- F
    void rotateAntiClockwise(Face<'F', N> &f, Face<'R', N> &r, Face<'B', N> &b, Face<'L', N> &l)
    {
        rotateFaceAntiClockwise();

        std::string tmp[N];
        std::copy(std::begin(f.values[N - 1]), std::end(f.values[N - 1]), std::begin(tmp));
        std::copy(std::begin(r.values[N - 1]), std::end(r.values[N - 1]), std::begin(f.values[N - 1]));
        std::copy(std::begin(b.values[N - 1]), std::end(b.values[N - 1]), std::begin(r.values[N - 1]));
        std::copy(std::begin(l.values[N - 1]), std::end(l.values[N - 1]), std::begin(b.values[N - 1]));
        std::copy(std::begin(tmp), std::end(tmp), std::begin(l.values[N - 1]));
    }
};

/*
U Initial stage:
                B
        [0,2] [0,1] [0,0]

    [0,0]               [0,2]
  L [0,1]               [0,1] R
    [0,2]               [0,0]

        [0,0] [0,1] [0,2]
                F
*/
template <size_t N>
struct U : Face<'U', N>
{

    using Face<'U', N>::rotateFaceClockwise;
    using Face<'U', N>::rotateFaceAntiClockwise;

    // U - Clockwise: B -> R -> F -> L -> B
    void rotateClockwise(Face<'B', N> &b, Face<'R', N> &r, Face<'F', N> &f, Face<'L', N> &l)
    {
        rotateFaceClockwise();

        std::string tmp[N];
        std::copy(std::begin(b.values[0]), std::end(b.values[0]), std::begin(tmp));
        std::copy(std::begin(l.values[0]), std::end(l.values[0]), std::begin(b.values[0]));
        std::copy(std::begin(f.values[0]), std::end(f.values[0]), std::begin(l.values[0]));
        std::copy(std::begin(r.values[0]), std::end(r.values[0]), std::begin(f.values[0]));
        std::copy(std::begin(tmp), std::end(tmp), std::begin(r.values[0]));
    }

    // U - Anti-clockwise: B <- R <- F <- L <- B
    void rotateAntiClockwise(Face<'B', N> &b, Face<'R', N> &r, Face<'F', N> &f, Face<'L', N> &l)
    {
        rotateFaceAntiClockwise();

        std::string tmp[N];
        std::copy(std::begin(b.values[0]), std::end(b.values[0]), std::begin(tmp));
        std::copy(std::begin(r.values[0]), std::end(r.values[0]), std::begin(b.values[0]));
        std::copy(std::begin(f.values[0]), std::end(f.values[0]), std::begin(r.values[0]));
        std::copy(std::begin(l.values[0]), std::end(l.values[0]), std::begin(f.values[0]));
        std::copy(std::begin(tmp), std::end(tmp), std::begin(l.values[0]));
    }
};