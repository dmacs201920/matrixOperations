#include<stdio.h>
#include<stdlib.h>
#include"header.h"
void main(){
    int c,col;char v='\0',s='\0';
    int **a=malloc(10*sizeof(int)),*b=malloc(10*sizeof(int));
    for (int i=0;i<10;i++)
	a[i]=calloc(10,sizeof(int));
    FILE *f=fopen("1.txt","r");
    int i=0,j=0;
    fscanf(f,"%d",&c);
    while(!feof(f)){
	if (s!='=')
	    a[i][j]=c;
	else{
	    b[i]=c;
	    ++i;
	    if (i==1)
		col=j;
	    j=-1;
	}
    	fscanf(f,"%c %c %d",&v,&s,&c);
	if (s=='-')
	    c*=-1;
	++j;
	    }
    b=realloc(b,i*sizeof(int));
    for (j=0;j<10;j++)
	a[j]=realloc(a[j],col*sizeof(col));
    *a=realloc(*a,i*sizeof(int));
    e[i-2]={-1,-1,-1};
    if (i==col){
	if(det(col,a,0,0,col,e,1,0)==0)
	    puts("soln doesn't exist");
	else{
	    int **f=malloc(col*sizeof(int));
	    for(int k=0;k<col;k++){
		f[k]=calloc(col,sizeof(int));
		f[k][k]=1;
	    }
	    inverse(col,a,f);
	    //multiplication
	    //display
	}
    }
    fclose(f);
}    
