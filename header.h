#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void sub(int r1,int c1,float **a,float **b,float **c);
void add(int r1,int c1,float **a,float**b,float **c);
void mul(int r1,int r2,int c1,int c2, float **a,float **b,float **c);
void Display(int r1,int c1,float **a);
float  trace(int r,int c,float **a);
void transpose(int r,int c,float **a);
void edit(int r1,int c1,float **a,float x );
