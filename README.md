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
       ex. +1.3x+3.4y+5.6z=-1.3
           +2.5x-2.0y-5.0z=+4.2
	   +0.0x+1.3y+1.1z=-1.4
	   +0.7x+4.0y+6.9z=-2.7
     ]

OUTPUT :as per user's requriment.(switch cases)

FILE STRUCTURE:
1.txt, test.txt:input files
function.c: THIS FILE CONTAINS FUNCTIONS OF ADDITION,SUBTRACTION,MULTIPLATION,DISPLAY,TRACE,EDIT,TRANSPOSE AND CHECKING IF THE GIVEN MATRICES ARE EITHER SYMMETRIC,SKEW SYMMETRIC,IDEMPOTENT,IDENTITY,UPPER TRIANGULAR,LOWER TRIANGULAR OR NOT.
f.c:THIS FILE CONTAINS FUNCTION OF :ROW OPERATIONS,DETERMINANT,RANK,INVERSE.
try.c:THIS FILE CONTAINS FUNCTION TO SOLVE SYSTEM OF LINEAR EQUATIONS.

PROJECT DESCRIPTION:(1) The input is stored in 2-D arays whose storage is allocated using dynamic allocation.
		    (2)To find rank of matrix first the matrix is converted to row echelon form and then the non-zero rows are counted.The no.of non-zero rows gives the                       rank of the matrix.
		    (3) Inverse is found using elementary row operations.
		    (4) To find determinant first the rank of the matrix is found. Then if the rank is equal to no. of rows/columns detrminant is calculated as product                         of the diagonal elements of the row echelon form and the elements with which we divided diagonal elements to make them equal to 1 in row echelon                        form.
		    (5) To solve system of linear equations first they are converted in the form AX=B.
		        if B=0 then if A is invertible we have trivial solution otherwise we have non-trivial solution.
			if B!=0 then if A is invertible we get unique solution otherwise we either get multiple solutions when rank of A=m of we don't get any solution.                        Now the solutions are calculated by converting A into its row echelon form and by back substitution. 

                     

       
 
