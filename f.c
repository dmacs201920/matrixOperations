//				        			    OM SRI SAI RAM
#include<stdio.h>
#include<math.h>
#include"Header.h"
int chk(int d[],int j,int r){
    for (int i=0;i<(r-2);i++)
	if (d[i]==j)
	    return 0;
    return 1;
}
int det(int r,int b[][r],int i,int k,int r1,int d[],int count,int z){
    if (r1==2){
	while(chk(d,(k++)%r,r)==0);
	k=(k-1)%r;
	int l=k+1;
	while(chk(d,(l++)%r,r)==0);
	l=(l-1)%r;
	return (b[i][k]*b[i+1][l])-(b[i+1][k]*b[i][l]);
    }
    else{
	while(chk(d,k%r,r)==0)
	    ++k;
	d[i]=k%r;
	z=z+(pow(-1,count+1)*b[i][d[i]]*det(r,b,i+1,0,r1-1,d,count,z));
	for (int f=i+1;f<(r-2);f++)
	    d[f]=-1;
	while(count<r1){
	    while(chk(d,(++k)%r,r)==0);
	    d[i]=k%r;
	    if (chk(d,-1,r)==0)
		z=z+(pow(-1,count)*b[i][d[i]]*det(r,b,i+1,0,r1-1,d,1,0));
	    else
		z=z+(pow(-1,count)*b[i][d[i]]*det(r,b,i+1,0,r1-1,d,count,z));
    	    for (int f=i+1;f<(r-2);f++)
		d[f]=-1;
	    ++count;
	}
    }
    return z;
}
void inverse(int n,int a[][n],int c[][n]){
    int s,k=0;
    while(k<n){
	s=a[k][k];
	for (int i=0;i<n;i++){
	    a[k][i]/=s;
	    c[k][i]/=s;
	}
	for (int j=0,i;j<n;j++)
	    if (j!=k){
		s=a[j][k];
		for (i=0;i<n;i++){
		    a[j][i]=a[j][i]-(s*a[k][i]);
		    c[j][i]=c[j][i]-(s*c[k][i]);
		}
	    }
	++k;
    }
}
//int rank(int n,int a[][]
void rank(int r,int col,float c[r][]){
    int s,k=0;
    while(k<r){
	s=c[k][k];
	for (int i=0;i<col;i++)
	    c[k][i]/=s;
	for (int j=0,i;j<r;j++)
	    if (j!=k){
		s=c[j][k];
		for (i=0;i<col;i++)
		    c[j][i]=c[j][i]-(s*c[k][i]);
	    }
	++k;
    }
}

