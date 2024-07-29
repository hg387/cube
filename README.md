# cube
Rubrick_Cube Impl


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