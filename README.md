# Cube
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
*/    

# Instructions to build and run:
1) This project is using CMake to build. Example CMake command to build the project, the command should be adjusted according to build environment:
```
usr/bin/cmake -DCMAKE_INSTALL_PREFIX=</workspaces/cube/out/install/rubrick_cube> -DCMAKE_C_COMPILER=</usr/bin/clang> -DCMAKE_CXX_COMPILER=</usr/bin/clang++> -DCMAKE_BUILD_TYPE=<Debug> <-S/workspaces/cube> <-B/workspaces/cube/out/build/rubrick_cube>
```

2) Based on the above build directory, example CMake command to run the project, the command should be adjusted according to build environment:
```
/usr/bin/cmake --build </workspaces/cube/out/build/rubrick_cube> --parallel 4 --target rubrick_cube --
```

# Instructions to build and run tests:
1) We are using Google Test to create unit tests. Example CMake command to build the project, the command should be adjusted according to build environment:
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