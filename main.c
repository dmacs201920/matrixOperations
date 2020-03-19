/*                                        OM SRI SAI RAM
  PROJECT ON :SIMPLE MATRIX OPERATIONS.
  WRITTEN BY: KASAM SAI PRANEETH AND N.S.S.KAMASELH.
  REG.NO: 173204 AND 173223.
  */
#include"header.h"
#include"Header.h"
void main(int argc,char *argv[])
{   int s=0;float pr=1; 
    FILE*f;
    int	apos=1,spos=1,mpos=1;
    int r1,c1,r2,c2,c,r,d;
    float e;

    if (argc!=2)
    {puts("........SORRY INPROPER NO.OF ARGUMENTS.....!!!");
        exit(-1);}
    f=fopen(argv[1],"r");
    if (f==NULL)
    {puts("........SORRY CANNOT OPEN FILE.......");
        exit(-1);
    }
    fscanf(f,"%d",&r1),fgetc(f),fscanf(f,"%d",&c1),fgetc(f);//READS DIMENSION OF 1ST MATRIX FROM FILE
    fscanf(f,"%d",&r2),fgetc(f),fscanf(f,"%d",&c2),fgetc(f);//READS DIMENSION OF 2ND MATRIX FORM FILE
    system("clear");
    if (c1<=0||c2<=0||r1<=0||r2<=0)            //CHECKING IF INPUT IS VALID OR NOT
    {  printf("\t\t\tSORRY INVALID INPUT .......\n");
        exit(-1);
    }
    float **a=malloc(r1*sizeof(float));       /////ALLOCATING SPACE FOR MATRICES a,b,ad,sb,ml,temp1,temp2
    for(int i=0;i<r1;i++)
        a[i]=malloc(c1*sizeof(float) );
    float **b=malloc(r2*sizeof(float));
    for(int i=0;i<r2;i++)
        b[i]=malloc(c2*sizeof(float) );
    float **ad=malloc(r1*sizeof(float));
    for(int i=0;i<r1;i++)
        ad[i]=malloc(c1*sizeof(float) );
    float **sb=malloc(r2*sizeof(float) );
    for(int i=0;i<r2;i++)
        sb[i]=malloc(c2*sizeof(float));
    float **ml=malloc(r1*sizeof(float) );
    for(int i=0;i<r1;i++)
        ml[i]=malloc(c2*sizeof(float));
    float **temp1=malloc(r1*sizeof(float));
    for(int i=0;i<r1;i++)
        temp1[i]=malloc(c1*sizeof(float) );
    float **temp2=malloc(r2*sizeof(float));
    for(int i=0;i<r2;i++)
        temp2[i]=malloc(c2*sizeof(float) );
    for(int i=0;i<r1;i++) // INPUT FOR 1ST MATRIX
        for(int j=0;j<c1;j++)
        { fscanf(f,"%f",&a[i][j]),fgetc(f);
            temp1[i][j]=a[i][j];
        }
    for(int i=0;i<r2;i++) // INPUT FOR 2ND MATRIX
        for(int j=0;j<c2;j++)
        {fscanf(f,"%f",&b[i][j]),fgetc(f);
            temp2[i][j]=b[i][j];
        }
    while (1)
    {if (c>=9)
        {for(int i=0,j;i<r1;i++) // 1ST MATRIX
            for(j=0;j<c1;j++)
                a[i][j]= temp1[i][j];
            for(int i=0,j;i<r2;i++) // 2ND MATRIX
                for( j=0;j<c2;j++)
                    b[i][j]=temp2[i][j];
        }
        printf("\n\t\t\tSIMPLE MATRIX OPERATIONS.");
        printf("\n\t\t1.ADDITION\n\t\t2.SUBTRACTION\n\t\t3.MULTIPLICATION\n\t\t4.DISPLAY\n\t\t5.EDIT\n\t\t6.TRACE\n\t\t7.TRANSPOSE");
        printf("\n\t\t8.SPECIAL PROPERTIES\n\t\t9.DETERMINANT\n\t\t10.RANK\n\t\t11.INVERSE\n\t\t12.SOLVING SYSTEM OF LINEAR EQUATIONS\n\t\t0.EXIT\n\t\t");
        scanf("%d",&c);
        switch(c)
        {case 1:///////// ADDITION OF MATRICES.
            if (r1!=r2||c1!=c2)// CHECKS GIVEN MATRIX SQUARE ARE NOT
            {printf("\t\t\t\tSORRY YOU CAN'T ADD TWO MATRICES..........!!!!!!\n");
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
            {printf("\t\t\tSORRY YOU CAN'T SUBTRACT TWO MATRICES...........!!!!\n");
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
            case 3://////// MULTIPLICATION OF MATRICES.  
            if (c1!=r2)
            {printf("\t\t\tSORRY YOU CAN'T MULTIPLY TWO MATRICES ...........!!!!\n");
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
            printf("\t\t\tGIVEN FIRST MATRIX:\n");
            Display(r1,c1,a);//DISPLAYS 1ST MATRIX
            printf("\t\t\tGIVEN SECOND MATRIX:\n");
            Display(r2,c2,b);//DISPLAY 2ND MATRIX
            break;
            case 5: //EDITING THE GIVEN MATRIX
            while(1) 
            {   Display(r1,c1,a);
                Display(r2,c2,b);
                printf("\t\t\tENTER WHICH MATRIX(1st or 2nd) TO EDIT :");
                scanf("%d",&c);
                printf("\t\t\tENTER THE ROW AND COL AND THE ELEMENT :");
                scanf("%d %d %f",&r,&d,&e);
                if (c==1)
                    edit(r,d,a,e);
                else
                    edit(r,d,b,e);
                getchar();
                printf("\t\t\tEDITED SUCCESSFULLY..!!!!!!!!!\n");
                printf("\t\t\tENTER (y/n) TO CONTINUE OR DISCONTINUE EDITING:");
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
            printf("\t\t\tTRACE OF 1st MATRIX IS :%f \n",e);
            e=trace(r2,c2,b);
            printf("\t\t\tTRACE OF 2nd MATRIX IS :%f \n",e);
            break;
            case 7:// TRANSPOSE OF MATRICES
            printf("\t\t\tTRANSPOSE  OF 1st MATRIX IS :");
            transpose(r1,c1,a);
            printf("\t\t\tTRANSPOSE  OF 2nd MATRIX IS :");
            transpose(r2,c2,b);
            break;
            case 8:// SPECIAL TYPES OF MATRICES
            printf("\t\t\tSPECIAL PROPERTIES OF 1st MATRIX IS  :");
            symmetric(r1,c1,a); 
            skew_symmetric(r1,c1,a);
            if (r1!=c1)
                printf("GIVEN MATRIX IS NOT SQUARE MATRIX.");
            else{
                idempotent(r1,a);
                up_triangle(r1,c1,a);
                lower_triangle(r1,c1,a);
                identity(r1,c1,a);
            }
            printf("\t\t\tSPECIAL TYPES OF 2nd MATRIX IS  :");
            symmetric(r2,c2,b); 
            skew_symmetric(r2,c2,b);
            if(r2!=c2)
                printf("GIVEN MATRIX IS NOT SQUARE MATRIX.");
            else
            {   idempotent(r2,b);
                up_triangle(r2,c2,b);
                lower_triangle(r2,c2,b);
                identity(r2,c2,b);
            }
            break;
            case 9:// DETERMINANT OF A MATRIX
            if(r1!=c1)
                printf("1st MATRIX IS NOT SQUARE MATRIX.");
            else
                printf("DETERMINANT OF 1ST MATRIX: %f\n",det(r1,a));
            if(r2!=c2)
                printf("2nd MATRIX IS NOT SQUARE MATRIX.");
            else
                printf("DETERMINANT OF 2nd MATRIX:%f\n",det(r2,b));
            break;
            case 10://RANK OF A MATRIX
            printf("\t\t\tRANK OF 1ST MATRIX : %d\n",rank(r1,c1,a,&s,&pr)); 
            printf("\t\t\tRANK OF 2ND MATRIX : %d\n",rank(r2,c2,b,&s,&pr)); 
            break;
            case 11://INVERSE OF A MATRIX
            if (r1!=c1)
                printf("1st MATRIX IS NOT SQUARE MATRIX.");
            else{
                for (int z=0,y;z<r1;z++)
                    for (y=0;y<c1;y++){
                        if(z!=y)
                            ad[z][y]=0;
                        else
                            ad[z][y]=1;
                    }
                inverse(r1,a,ad);
                Display(r1,c1,ad);
            }
            if (r2!=c2)
                printf("2nd MATRIX IS NOT SQUARE MATRIX.");
            else{
                for (int z=0,y;z<r2;z++)
                    for (y=0;y<c2;y++){
                        if(z!=y)
                            sb[z][y]=0;
                        else
                            sb[z][y]=1;
                    }
                inverse(r2,b,sb);
                Display(r2,c2,sb);
            }
            break;
            case 12://sys
            solve();
            break;
            case 0: 
            system("clear");
            for(int i=0;i<r1;i++)
                free(a[i]);
            free(*a);
            for(int i=0;i<r2;i++)
                free(b[i]);
            free(*b);
            for(int i=0;i<r1;i++)
                free(ad[i]);
            free(*ad);
            for(int i=0;i<r2;i++)
                free(sb[i]);
            free(*sb);
            for(int i=0;i<r1;i++)
                free(ml[i]);
            free(*ml);
            fclose(f);
            exit(-1);
            default :
            printf("WRONG ......ENTRY\n");
        }
    }
}  
