# cube
Rubrick_Cube Impl

U = Up Face
L = Left Face
F = Front Face
R = Right Face
B = Back Face
D = Down Face

/*
A sample 3x3 face:
+------------+
| X1  X2  X3 |
|            |
| X4  X5  X6 |
|            |
| X7  X8  X9 |
+------------+
*/



/*
State representation:
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

/*
             +------------+
             | U1  U2  U3 |
|            |
             | U4  U5  U6 |
|            |
             | U7  U8  U9 |
+------------++------------++------------++------------+
| L1  L2  L3 | F1  F2  F3 | R1  R2  R3 | R1  R2  R3 | 
|            ||            ||            ||            |
| L4  L5  L6 | F4  F5  F6 | R4  R5  R6 | R4  R5  R6 | 
|            ||            ||            ||            |
| L7  L8  L9 | F7  F8  F9 | R7  R8  R9 | R7  R8  R9 | 
+------------++------------++------------++------------+
             | D1  D2  D3 |
|            |
             | D4  D5  D6 |
|            |
             | D7  D8  D9 |
             +------------+
*/

/*
B Initial stage:

        [0,2] [0,1] [0,0]

    [0,2]               [0,0]
    [1,2]               [0,1]
    [2,2]               [0,2]

        [2,2] [2,1] [2,0]

B - Clockwise: U -> L -> D -> R -> U
B - Anti-clockwise: U <- L <- D <- R <- U


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