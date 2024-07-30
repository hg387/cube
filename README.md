# Cube
The code is implemented to extend to N-face cube. However, approach and intution are explained for 3x3 cube (limited to the scope of the assignment).
```
U = Up Face
L = Left Face
F = Front Face
R = Right Face
B = Back Face
D = Down Face
```
/*    
A sample 3x3 face:   
```
+------------+    
| X1  X2  X3 |   
|            |   
| X4  X5  X6 |   
|            |   
| X7  X8  X9 |   
+------------+    
```

A sample 5x5 face:
```
+-------------------------+
|  X1   X2   X3   X4   X5 |
|                         |
|  X6   X7   X8   X9  X10 |
|                         |
| X11  X12  X13  X14  X15 |
|                         |
| X16  X17  X18  X19  X20 |
|                         |
| X21  X22  X23  X24  X25 |
+-------------------------+
```
*/    

# State representation:
/* 
```    
             +------------+    
             | U1  U2  U3 |    
             |            |     
             | U4  U5  U6 |    
             |            |    
             | U7  U8  U9 |    
+------------+------------+------------+------------+    
| L1  L2  L3 | F1  F2  F3 | R1  R2  R3 | B1  B2  B3 |    
|            |            |            |            |    
| L4  L5  L6 | F4  F5  F6 | R4  R5  R6 | B4  B5  B6 |     
|            |            |            |            |     
| L7  L8  L9 | F7  F8  F9 | R7  R8  R9 | B7  B8  B9 |      
+------------+------------+------------+------------+     
             | D1  D2  D3 |     
             |            |     
             | D4  D5  D6 |      
             |            |         
             | D7  D8  D9 |     
             +------------+      
```

5 x 5 state representation:
```
                           +-------------------------+
                           |  U1   U2   U3   U4   U5 |
                           |                         |
                           |  U6   U7   U8   U9  U10 |
                           |                         |
                           | U11  U12  U13  U14  U15 |
                           |                         |
                           | U16  U17  U18  U19  U20 |
                           |                         |
                           | U21  U22  U23  U24  U25 |
 +-------------------------+-------------------------+-------------------------+-------------------------+
 |  L1   L2   L3   L4   L5 |  F1   F2   F3   F4   F5 |  R1   R2   R3   R4   R5 |  B1   B2   B3   B4   B5 | 
 |                         |                         |                         |                         |
 |  L6   L7   L8   L9  L10 |  F6   F7   F8   F9  F10 |  R6   R7   R8   R9  R10 |  B6   B7   B8   B9  B10 | 
 |                         |                         |                         |                         |
 | L11  L12  L13  L14  L15 | F11  F12  F13  F14  F15 | R11  R12  R13  R14  R15 | B11  B12  B13  B14  B15 | 
 |                         |                         |                         |                         |
 | L16  L17  L18  L19  L20 | F16  F17  F18  F19  F20 | R16  R17  R18  R19  R20 | B16  B17  B18  B19  B20 | 
 |                         |                         |                         |                         |
 | L21  L22  L23  L24  L25 | F21  F22  F23  F24  F25 | R21  R22  R23  R24  R25 | B21  B22  B23  B24  B25 | 
 +-------------------------+-------------------------+-------------------------+-------------------------+
                           |  D1   D2   D3   D4   D5 |
                           |                         |
                           |  D6   D7   D8   D9  D10 |
                           |                         |
                           | D11  D12  D13  D14  D15 |
                           |                         |
                           | D16  D17  D18  D19  D20 |
                           |                         |
                           | D21  D22  D23  D24  D25 |
                           +-------------------------+
```
*/    

# Instructions to build and run:
1) This project is using CMake to build. Also, some functions available in C++20 are used. Example CMake command to build the project, the command should be adjusted according to build environment:
```
usr/bin/cmake -DCMAKE_INSTALL_PREFIX=</workspaces/cube/out/install/rubrick_cube> -DCMAKE_C_COMPILER=</usr/bin/clang> -DCMAKE_CXX_COMPILER=</usr/bin/clang++> -DCMAKE_BUILD_TYPE=<Debug> <-S/workspaces/cube> <-B/workspaces/cube/out/build/rubrick_cube>
```

2) Based on the above build directory, example CMake command to run the project, the command should be adjusted according to build environment:
```
/usr/bin/cmake --build </workspaces/cube/out/build/rubrick_cube> --parallel 4 --target rubrick_cube --
```

# Instructions to build and run tests:
1) We are using Google Test to create unit tests. Also, some functions available in C++20 are used. Example CMake command to build the project, the command should be adjusted according to build environment:
```
/usr/bin/cmake --build </workspaces/cube/out/build/rubrick_cube> --parallel 4 --
``` 

2) Based on the above build directory, example CMake command to run the project, the command should be adjusted according to build environment:
```
cd </workspaces/cube/out/build/rubrick_cube> && /usr/bin/ctest
```

# Approach for face rotation:
/*
Converting rotated block based on some matrix rotation shown below:     
```
   j                  i
 ******            ********
 * +---------------------+*
i* |                     |*j
 * |                     |*
   |                     |
   |                     |
   |                     |
   |                     |*
 * |                     |*
j* |                     |*i
 * +---------------------+*
 ******             *******
   i                   j
```
*/

# Approach for rotations:
/* 
```    
B Initial stage:     
                U         
        [0,2] [0,1] [0,0]     
           
    [0,2]               [0,0]          
  R [1,2]               [0,1] L      
    [2,2]               [0,2]          
      
        [2,2] [2,1] [2,0]      
                D      
B - Clockwise: U -> L -> D -> R -> U      
B - Anti-clockwise: U <- L <- D <- R <- U      
```      
```      
R Initial stage:      
                U      
        [2,2] [1,2] [0,2]      
      
    [0,2]               [0,0]      
  F [1,2]               [1,0] B      
    [2,2]               [2,0]      
      
        [0,2] [1,2] [2,2]      
                D      
R - Clockwise: U -> B -> D -> F -> U      
R - Anti-clockwise: U <- B <- D <- F <- U      
```         
```         
L Initial stage:      
                U      
        [0,0] [1,0] [2,0]      
      
    [0,2]               [0,0]      
  B [1,2]               [1,0] F      
    [2,2]               [2,0]      
      
        [2,0] [1,0] [0,0]      
                D      
L - Clockwise:  U -> F -> D -> B -> U      
L - Anti-clockwise: U <- F <- D <- B <- U        
```      
```       
F Initial stage:      
                U      
        [2,0] [2,1] [2,2]      
      
    [0,2]               [0,0]      
  L [1,2]               [1,0] R      
    [2,2]               [2,0]      
      
        [0,0] [0,1] [0,2]      
                D      
F - Clockwise: U -> R -> D -> L -> U      
F - Anti-clockwise: U <- R <- D <- L <- U      
```      
```   
D Initial stage:      
                F      
        [2,0] [2,1] [2,2]      
      
    [2,2]               [2,0]      
  L [2,1]               [2,1] R      
    [2,0]               [2,2]      
      
        [2,2] [2,1] [2,0]      
                B      
D - Clockwise: F -> R -> B -> L -> F      
D - Anti-clockwise: F <- R <- B <- L <- F      
```
```      
U Initial stage:      
                B      
        [0,2] [0,1] [0,0]      
      
    [0,0]               [0,2]      
  L [0,1]               [0,1] R      
    [0,2]               [0,0]      
      
        [0,0] [0,1] [0,2]      
                F      
U - Clockwise: B -> R -> F -> L -> B      
U - Anti-clockwise: B <- R <- F <- L <- B      
```
*/      
