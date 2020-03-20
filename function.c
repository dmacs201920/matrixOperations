/*				OM SRI SAI RAM.
WRITTEN BY:K.SAIPRANEETH.
RED.NO:173204.
THIS FILE CONTAINS FUNCTIONS OF : ADDATION,SUBTRACTION,MULTIPLATION,DISPLAY,TRACE,EDIT,TRANSPOSE,SYMMETRIC,SKEW SYMMETRIC,IDEMPOTENT,NILPOTENT,IDENTITY,UPPER TRIANGULAR,LOWER TRIANGULAR.
*/

#include"header.h"
////////////////////// ADDATION FUN
void add(int r1,int c1,float **a,float **b,float **c)
{int i,j;
    for (i=0;i<r1;i++)
        for (j=0;j<c1;j++)
            c[i][j]=a[i][j]+b[i][j];
}
/////////////////////// SUBTRACTION FUN
void sub(int r1,int c1,float **a,float **b,float **c)
{int i,j;
    for (i=0;i<r1;i++)
        for (j=0;j<c1;j++)
            c[i][j]=a[i][j]-b[i][j];
}
////////////////////// MULTIPLATION FUN
void mul(int r1,int r2,int c1,int c2, float **a,float **b,float **c)
{ int i,j,k;float s=0;
    for (i=0;i<r1;i++)
        for (k=0;k<c2;k++)
        {for (j=0;j<c1;j++)
            { s+=a[i][j]*b[j][k];
            }
            c[i][k]=s;s=0;
        }
}
////////////////////// TO DISPLAY MATRIX
void Display(int r1,int c1,float **a)
{
    int i,j;
    for(i=0;i<r1;i++)
    {   printf("\n");

        for(j=0;j<c1;j++)
            printf("\t\t\t%.2f ",a[i][j]);
    }
    printf("\n");
}
////////////////TO EDIT A GIVEN MATRIX  
void  edit(int r,int c,float **a,float x)
{
    a[r-1][c-1]=x;
}
///////////////TRACE OF A MATRIX
float trace(int r,int c,float **a )
{   int i,j;
    Display(r,c,a);
    float tr=0.00;
    if (r!=c)
    {printf("NOT A SQUARE MATRIX \n");
        return -1;
    }
    for(i=0;i<r;i++)
        tr+=a[i][i];// ADDS ALL ENTRIES IN DIAGONAL.
    return tr;
}
//////TRANSPOSE OF A MATRIX
void transpose(int r,int c,float **a)
{int i,j;
    for(i=0;i<r;i++)
    { printf("\n");
        for(j=0;j<c;j++)
            printf("\t\t\t%f ",a[j][i]);
    }
    printf("\n");
}
/////// SYMMETRIC 
void symmetric(int r,int c,float **a)
{ int i,j;
    for(i=0;i<r;i++)
    {for(j=0;j<c;j++)
        {if(a[i][j]!=a[j][i])//COMPARIES ENTRIES IN (A) AND (A(TRANSPOSE)).
            break;
        }
        if(j!=c)
            break;
    }
    if(i==r)
        printf(" SYMMETRIC MATRIX. \n");
    else
        printf(" NOT A SYMMETRIC MATRIX.\n");
}
/////// SKEW SYMMETRIC 
void skew_symmetric(int r,int c,float **a)
{ int i,j;
    for(i=0;i<r;i++)
    {for(j=0;j<c;j++)
        {if(a[i][j]!=-a[j][i])//COMPARIES ENTRIES IN (A) AND (-(A(TRANSPOSE))).
            break;
        }
        if(j!=c)
            break;
    }
    if(i==r)
        printf("\t\t\t\t\t\t\t:SKEW SYMMETRIC MATRIX.\n");
    else
        printf("\t\t\t\t\t\t\t:NOT A SKEW SYMMETRIC MATRIX.\n");
}
////// IDEMPOTENT MATRIX
void idempotent(int r,float **a)
{ int i,j;
    float **c=malloc(r*sizeof(float));
    for(int i=0;i<r;i++)
        c[i]=malloc(r*sizeof(float) ); 
    mul(r,r,r,r,a,a,c);//calling multiplation function
    for(i=0;i<r;i++)
    {for(j=0;j<r;j++)
        {if (c[i][j]!=a[i][j])//COMPARIES ENTRISE IN (A^2)AND (A).
            break;
        }
        if(j!=r)
            break;
    }
    if(i==r)
        printf("\t\t\t\t\t\t\t:IDEMPOTENT MATRIX.\n");
    else
        printf("\t\t\t\t\t\t\t:NOT A IDENPOTENT MATRIX.\n");
}
///// IDENTITY MATRIX
void identity(int r,int c,float **a)
{ int i,j;
    for(i=0;i<r;i++)
    {for(j=0;j<c;j++)
        { if((i==j&&a[i][j]!=1)||(i!=j&&a[i][j]!=0))//CHECKS ENTRIES IN DIAGONAL ARE '1's' AND REMANING ENTRIES ARE '0's'.
            break;
        }
        if(j!=c)
            break;
    }
    if (i==r)
        printf("\t\t\t\t\t\t\t:IDENTITY MATRIX.\n");
    else
        printf("\t\t\t\t\t\t\t:NOT A IDENTITY MATRIX.\n");
}
///// CHECKS GIVEN MATRIX IS UPPER TRIANGULAR OR NOT
void up_triangle(int r,int c,float **a)
{int i,j;
    for(i=0;i<r;++i)
    {for(j=0;j<i;++j)
        {if(a[i][j]!=0)//CHECKS ENTRIES IN LOWER TRIANGLE ARE '0's'.
            break;
        }
        if(j!=i)
        break;
    }
    if(i==r)
        printf("\t\t\t\t\t\t\t:UPPPER TRIANGULAR MATRIX.\n");
    else
        printf("\t\t\t\t\t\t\t:NOT A UPPER TRIANGULAR MATRIX.\n");

}
///// CHECKS GIVEN MATRIX IS LOWER TRIANGULAR OR NOT
void lower_triangle(int r,int c,float **a)
{int i,j;
    for(i=0;i<r;i++)
    {for(j=0;j<c;j++)
        {if(j>i && a[i][j]!=0)//CHECKS ENTRIES IN UPPER TRIANGLE ARE '0's'.
            break;
        }
        if(j!=c)
        break;
    }
    if(i==r)
        printf("\t\t\t\t\t\t\t:LOWER TRIANGULAR MATRIX.\n");
    else
        printf("\t\t\t\t\t\t\t:NOT A LOWER TRIANGULAR MATRIX.\n");
}
