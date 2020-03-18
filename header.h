/*                   OM SRI SAI RAM
WRITTEN BY:K.SAIRANEETH
RED:NO:173204
HEADER FOR :FUNCTION.C,MAIN.C
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void sub(int ,int ,float **,float **,float **);
void add(int ,int ,float **,float**,float **);
void mul(int ,int ,int ,int , float **,float **,float **);
void Display(int r1,int c1,float **);
float trace(int r,int c,float **);
void transpose(int r,int c,float **);
void edit(int r1,int c1,float **,float x );
void symmetric(int r ,int c ,float **);
void skew_symmetric(int r ,int c,float **);
void idempotent(int r ,float **);
void nilpotent(int r,float **);
void identity(int r,int c,float **);
void up_triangle(int r,int c,float **);
void lower_triangle(int r,int c,float **);
void solve();

