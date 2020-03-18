# matrixOperations
A novice implementation of matrix operations in C
                              OM SRI SAI RAM

This project is about simple matrix operations.

WORK DIVISION: K.SAIPRANEETH(function.c).
               N.S.S.KAMALESH(f.c).
               try.c(combined).
INPUT :Input to this project is given using a text file on commandline.(test.txt)(file)
     [Sample Input in file shloud be given as below :
      In first row dimension of 1st matrix (row space coloum space) dimension of 2nd matrix (row space coloum).
      (ex. 2 2 3 3)

      entries of matrix 1 then entries of matrix 2
      (ex. 2 3   {entries of 1st matrix (row1)}
           3 4   {entries of 1st matrix (row2)}
           1 3 4 {entries of 2nd matrix (row1)}
           1 2 3 {entries of 2nd matrix (row2)}
           2 3 3 {entries of 2nd matrix (row3)}
       )
     ]

     Input for system of linear equations.(1.txt)(file) (input is taken by function automatically)
     [Sample Input in file shloud be give as below :
       ex. +1x+3y+5z=-1
           -1x-2y-5z=4
           +0x+1y+1z=-1
           +1x+4y+6z=-2
     ]

OUTPUT :as per user's requriment.(switch cases)

FILE STRUCTURE:
1.txt, test.txt:input files
function.c:THIS FILE CONTAINS FUNCTIONS OF : ADDATION,SUBTRACTION,MULTIPLATION,DISPLAY,TRACE,EDIT,TRANSPOSE AND CHECKING IF THE GIVEN MATRICES ARE EITHER SYMMETRIC,SKEW SYMMETRIC,IDEMPOTENT,NILPOTENT,IDENTITY,UPPER TRIANGULAR,LOWER TRIANGULAR OR NOT.
f.c:THIS FILE CONTAINS FUNCTION OF :ROW OPERATIONS,DETERMINANT,RANK,INVERSE.
try.c:THIS FILE CONTAINS FUNCTION TO SOLVE SYSTEM OF LINEAR EQUATIONS.



       
 
