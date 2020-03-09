////				OM SRI SAI RAM
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
void Display(int r1,int c1,float **num)
{
    int i,j;
    for(i=0;i<r1;i++)
    {   printf("\n");
	for(j=0;j<c1;j++)
	    printf("\t\t\t%f",num[i][j]);
    }
	printf("\n");
}

////////////////TO EDIT A GIVEN MATRIX  
//om sri sai ram
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
	tr+=a[i][i];
    return tr;
}

//////TRANSPOSE 
void transpose(int r,int c,float **a)
{int i,j;
    for(i=0;i<r;i++)
    { printf("\n");
     for(j=0;j<c;j++)
	 printf("\t\t\t%f",a[j][i]);
    }
    printf("\n");
}
////////////////
void system_of_linear_equation(int x,int y)
{ 


}
