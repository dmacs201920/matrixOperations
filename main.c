//////    OM SRI SAI RAM
////// WRITTEN BY: KASAM SAI PRANEETH.
/////  REG.NO: 173204.
#include"header.h"

void main(int argc,char *argv[])
{FILE*f;
    int	apos=1,spos=1,mpos=1;
    int r1,c1,r2,c2,c,r,d;
    float e;
    
    if (argc!=2)
    {puts("inproper no.of arguments");
	exit(-1);}
    f=fopen(argv[1],"r");
    if (f==NULL)
    {puts("cannot open file");
	exit(-1);
    }
   fscanf(f,"%d",&r1),fgetc(f),fscanf(f,"%d",&c1),fgetc(f);//READES DIMENSION OF 1ST MATRIX FROM FILE
   fscanf(f,"%d",&r2),fgetc(f),fscanf(f,"%d",&c2),fgetc(f);//READES DIMENSION OF 2ND MATRIX FORM FILE
   system("clear"); 
/////////////////// CHECKING INPUT IS VALID OR NOT   
  if (c1<=0||c2<=0||r1<=0||r2<=0)
  {  printf("\t\t\tINVALID INPUT .......\n");
      exit(-1);
  }
  
//////////////////// 
 
  float **a=malloc(r1);
  for(int i=0;i<r1;i++)
      a[i]=malloc(c1);
  
  float **b=malloc(r2);
  for(int i=0;i<r2;i++)
      b[i]=malloc(c2);
  
  float **ad=malloc(r1);
  for(int i=0;i<r1;i++)
      ad[i]=malloc(c1);

  float **sb=malloc(r2);
  for(int i=0;i<r2;i++)
      sb[i]=malloc(c2);
  
  float **ml=malloc(c1);
  for(int i=0;i<r2;i++)
      ml[i]=malloc(r2);

//////////////////////// INPUT FROM FILE
  for(int i=0;i<r1;i++) // 1ST MATRIX
      for(int j=0;j<c1;j++)
	  fscanf(f,"%f",&a[i][j]),fgetc(f);
 // printf("\t\t\tGIVEN FIRST MATRIX\n");
 //  Display(r1,c1,a);//DISPLAYS 1ST MATRIX

  for(int i=0;i<r2;i++) // 2ND MATRIX
      for(int j=0;j<c2;j++)
	  fscanf(f,"%f",&b[i][j]),fgetc(f);
 // printf("\t\t\tGIVEN 2nd MATRIX\n");
 //Display(r2,c2,b);//DISPLAY 2ND MATRIX


  while (1)
  {   printf("\n\t\t\t MATRIX");
      printf("\n\t\t1.ADDATION OF MATRICES\n\t\t2.SUBTRACTION OF MATRICES\n\t\t3.PRODUCT OF MATRICES\n\t\t4.DISPLAY\n\t\t5.TO EDIT\n\t\t6.TRACE OF GIVEN TWO MATRICES\n\t\t7.TRANSPOSE OF GIVEN MATRICES\n\t\t8.SLOVE SYSTEM OF LINEAR EQUATION\n\t\t0.EXIT\n\t\t");
      scanf("%d",&c);
    switch(c)
    {case 1:///////// ADDATION OF MATRICES.
	    if (r1!=r2||c1!=c2)// CHECKS GIVEN MATRIX SQUARE ARE NOT
	    {printf("\t\t\t\tYOU CAN'T ADD \n");
	     apos=0;
	    }

	    if(apos==1)
	    {add(r1,c1,a,b,ad);
		printf("\t\t\tANSWER FOR MATRIX ADDITION\n");
		for (int i=0,j;i<r1;i++) 
		{  printf("\n");
		    for (j=0;j<c1;j++)
			printf("\t\t\t%f ",ad[i][j]);
		}
		printf("\n");
	    }
	    break;

      case 2://////////SUBTRACTION OF MATRICES.
	    if (r1!=r2||c1!=c2)//CHECKS GIVEN MATRIX SQUARE ARE NOT
	    {printf("\t\t\tYOU CAN'T SUBTRACT\n");
		spos=0;
	    }
	    if(spos==1)
	    {sub(r1,c1,a,b,sb);
		printf("\t\t\tANSWER FOR MATRIX SUBTRACTION\n");
		for (int i=0,j;i<r1;i++) 
		{  printf("\n");
		    for (j=0;j<c1;j++)
			printf("\t\t\t%f ",sb[i][j]);
		}
		printf("\n");
	    }
	    break;

      case 3:////////// MULTIPLICATION OF MATRICES.  
	    if (c1!=r2)
	    {  printf("\t\t\tYOU CAN'T MULTIPLY\n");
		mpos=0;
	    }
	    if (mpos==1)
	    {   mul(r1,r2,c1,c2,a,b,ml);
		printf("\t\t\tANSWER FOR MATRIX multipliction\n");
		for (int i=0,j;i<r1;i++) 
		{  printf("\n");
		    for (j=0;j<c2;j++)
			printf("\t\t\t%f ",ml[i][j]);
		}

		printf("\n");
	    }
	    break;

      case 4: //DISPLAY THE MATRICES
	    printf("\t\t\tGIVEN FIRST MATRIX\n");
	    Display(r1,c1,a);//DISPLAYS 1ST MATRIX
	    printf("\t\t\tGIVEN SECOND MATRIX\n");
	    Display(r2,c2,b);//DISPLAY 2ND MATRIX
	    break;

      case 5: //EDITING THE GIVEN MATRIX
	    while(1) 
	    {printf("\t\t\tENTER WHICH MATRIX(1st or 2nd) TO EDIT :");
		scanf("%d",&c);
		printf("\t\t\tENTER THE POISTION ROW AND COL OF THE ELEMENT :");
		scanf("%d %d %f",&r,&d,&e);
		if (c==1)
		    edit(r,d,a,e);
		else
		    edit(r,d,b,e);
		getchar();
		printf("\t\t\tENTER (y/n) TO CONTINUE OR DISCONTINUE :");
		if (getchar()=='n')
		    break;
	    }
	    Display(r1,c1,a);
	    Display(r2,c2,b);
	    fclose(f);
	    f=fopen(argv[1],"w");
	    { fprintf(f,"%d %d %d %d",r1,c1,r2,c2);
		fputc('\n',f);
		for(int i=0,j;i<r1;i++)
		{for(j=0;j<c1;j++)
		    fprintf(f,"%f ",a[i][j]);
		    fputc('\n',f);
		}
              	for(int i=0,j;i<r2;i++)
		{for(j=0;j<c2;j++)
		    fprintf(f,"%f ",b[i][j]);
		    fputc('\n',f);
		}
		fclose(f);
	    }
            f=fopen(argv[1],"r");
	    break;

      case 6://TRACE
	    e=trace(r1,c1,a);
	    printf("\t\t\tTRACE OF 1ST MATRIX IS :%f \n",e);
	    e=trace(r2,c2,b);
	    printf("\t\t\tTRACE OF 2nd MATRIX IS :%f \n",e);
	    break;

      case 7:// TRANSPOSE OF MATRICES
	     printf("\t\t\tTRANSPOSE  OF 1ST MATRIX IS :");
             transpose(r1,c1,a);
	     printf("\t\t\tTRANSPOSE  OF 2ND MATRIX IS :");
	     transpose(r2,c2,a);
	     break;

      case 0: 
	    system("clear");
	    fclose(f);
	    exit(-1);
      default :
	    printf("WRONG ......ENTERY\n");
    }
  }
}  
