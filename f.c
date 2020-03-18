/*    OM SRI SAI RAM
WRITTEN BY:N.S.S KAMALESH.
RED.NO:173223.
THIS FILE CONTAINS FUNCTION OF :ROW_OPERATIONS,DETERMINANT,RANK,INVERSE.
*/

#include<stdio.h>
#include<stdlib.h>
#include"Header.h"
void row_op(int r,int col,float **c,float **b,int *p,float *pr,int check){
    float s;int k=0,f=0,chk=0;
    while(k<r && chk<col){
        if (c[k][chk]==0){
            f=k+1;
            while(f<r && c[f][chk]==0)
                ++f;
            if(f==r){
                ++chk;
                if(chk==col)
                    k=r;
            }
            else{
                for(int i=0;i<col;i++){
                    s=c[k][i];
                    c[k][i]=c[f][i];
                    c[f][i]=s;
                }
                if (check==1)
                    for(int i=0;i<col;i++){
                        s=b[k][i];
                        b[k][i]=b[f][i];
                        b[f][i]=s;
                    }
                else
                    ++*p;
            }
        }
        if(f!=r){
            s=c[k][chk];
            if (check==0)
                (*pr)*=s;
            for (int i=0;i<col;i++){
                c[k][i]/=s;
                if (check==1)
                    b[k][i]/=s;
            }
            for (int j=0,i;j<r;j++){
                if (j!=k){
                    s=c[j][chk];
                    for (i=0;i<col;i++){
                        c[j][i]=c[j][i]-(s*c[k][i]); 
                        if (check==1)
                            b[j][i]=b[j][i]-(s*b[k][i]);
                    }
                }
            }
            ++k;++chk;
        }
        f=0;
    }
}
float det(int r,float **a){
    float p=1;float pr=1;int i=0,s=0;
    if (rank(r,r,a,&s,&pr)!=r)
        return 0;
    else{
        while(i<r){
            p*=a[i][i];
            ++i;
        }
        return p*(s%2==0? 1:-1)*pr;
    }
}
int rank(int r,int col,float **c,int *s,float *pr){
    float **b=malloc(sizeof(float));
    b[0]=malloc(sizeof(float));
    row_op(r,col,c,b,s,pr,0);
    int cnt=0;
    for(int i=0,j=0;i<r;i++,j=0){
        while(j<col && c[i][j]==0)
            ++j;
        if(j!=col)
            ++cnt;
    }
    return cnt;
}
void inverse(int r,float **a,float **b){
    row_op(r,r,a,b,0,a[0],1);
}
