/*				OM SRI SAI RAM.
WRITTEN BY:K.SAIPRANEETH. AND N.S.S KAMALESH
RED.NO:173204 AND 173223
THIS CONTAINS FUNCTION FOR :SYSTEM OF LINEAR EQUATIONS.
*/

#include"Header.h"
#include"header.h"
#include<limits.h>
void solve(){
    float c;int col;char v='\0',s='\0';
    float **a=malloc(10*sizeof(float)),**b=malloc(10*sizeof(float));
    for (int i=0;i<10;i++){
        a[i]=calloc(10,sizeof(float));
        b[i]=malloc(sizeof(float));
    }
    FILE *f=fopen("1.txt","r");
    int i=0,j=0;
    fscanf(f,"%f",&c);
    while(!feof(f)){
        if (s!='=')
            a[i][j]=c;
        else{
            b[i][0]=c;
            ++i;
            if (i==1)
                col=j;
            j=-1;
        }
        fscanf(f,"%c %c %f",&v,&s,&c);
        if (s=='-')
            c*=-1;    
        ++j;
    }c=0;
    for (j=0;j<10;j++)
        a[j]=realloc(a[j],col*sizeof(float));
    *b=realloc(*b,i*sizeof(int));
    *a=realloc(*a,i*sizeof(int));
    float **f1=malloc(i*sizeof(float));
    for(int k1=0;k1<i;k1++)
        f1[k1]=malloc(col*sizeof(float));
    for(int z=0,y;z<i;z++)
        for(y=0;y<col;y++)
            f1[z][y]=a[z][y];
    float **g=malloc(i*sizeof(float));
    for(int v1=0;v1<i;v1++)
        g[v1]=malloc(sizeof(float));
    int s1=0,k1,ar,rnk;float pr1=0;
    for(k1=0;k1<i;k1++)
        if (b[k1][0]!=c)
            break;
    rnk=rank(i,col,a,&s1,&pr1);
    if (rnk==col){
        if (k1==i){
            printf("solution is: ");
            for(int z=0;z<i;z++)
                printf("0 ");
            puts("");    
        }
        else{
            if (i==col){
                inverse(i,a,f1);
                mul(i,col,col,1,f1,b,g);
                printf("solution is: ");
                for(int z=0;z<i;z++)
                    printf("%f ",g[z][0]);
                puts("");    
            }
            else
                puts("Equations are inconsistent");
        }
    }
    else{
        row_op(i,col,a,f1,&s1,&pr1,0);
        printf("k1:%d\n",k1);
        if (k1==i || rnk==i){
            ar=col-rnk;
            int *arr=malloc(ar*sizeof(int));
            float sn[col],s=0;int count=0,q=0;
            for(int y=0;y<col;y++)
                sn[y]=INT_MAX;
            for(int z=rnk-1,y;z>=0;z--,count=0,s=0){
                for(y=0;y<col;y++)
                    if (a[z][y]!=0)
                        ++count;
                y=col-1;
                while(count){
                    if (a[z][y]!=0){
                        if(sn[y]!=INT_MAX){
                            s=s+(a[z][y]*sn[y]);
                        }
                        else{
                            if (count!=1){
                                s=s+(a[z][y]*(ar==1?1:0));
                                sn[y]=(ar==1?1:0);
                                --ar;
                                arr[q++]=y;
                                printf("arr:%d\n",arr[q-1]);
                            }
                            else
                                sn[y]=((b[y][0]-s)/a[z][y]);
                        }
                        --count;
                    }
                    --y;
                }
            }
            for(int y=0;y<col;y++)
                if (sn[y]==INT_MAX){
                    sn[y]=1;
                    break;
                }
            printf("one of the solutions: ");
            for(int y=0;y<col;y++)
                printf("%f ",sn[y]);
            puts("");    
            printf("positions of arbitrary choices:");
            for(int y=0;y<(col-rnk);y++)
                printf("%d ",arr[y]);
            puts("");    
        }
        else
            puts("equations are inconsistent");
    }
    fclose(f);
}    
