//
//#include <stdio.h>
//
//const int N = 10;
//
//void MNS(int C[],int n,int **size)
//{
//    for(int j=0;j<C[1];j++)
//    {
//        size[1][j]=0;
//    }
//
//    for(int j=C[1]; j<=n; j++)
//    {
//        size[1][j]=1;
//    }
//
//    for(int i=2; i<n; i++)
//    {
//        for(int j=0; j<C[i]; j++)
//        {
//            size[i][j]=size[i-1][j];//当i<c[i]的情形
//        }
//        for(int j=C[i]; j<=n; j++)
//        {
//            //当j>=c[i]时，考虑(i，c[i])是否属于MNS(i,j)的两种情况
//            size[i][j]=size[i-1][j]>size[i-1][C[i]-1]+1?size[i-1][j]:size[i-1][C[i]-1]+1;
//        }
//    }
//    size[n][n]=size[n-1][n]>size[n-1][C[n]-1]+1?size[n-1][n]:size[n-1][C[n]-1]+1;
//}
//
//void Traceback(int C[],int **size,int n,int Net[],int& m)
//{
//    int j=n;
//    m=0;
//    for(int i=n;i>1;i--)
//    {
//        if(size[i][j]!=size[i-1][j])//此时，（i,c[i])是最大不相交子集的一条边
//        {
//            Net[m++]=i;
//            j=C[i]-1;//更新扩展连线柱区间
//        }
//    }
//    if(j>=C[1])//处理i=1的情形
//    {
//        Net[m++]=1;
//    }
//}
//
//int main(){
//    int c[] = {0,8,7,4,2,5,1,9,3,10,6};//下标从1开始
//    int size[11];
//
//    for(int i=0; i<=N; i++)
//    {
//        size[i] =0;
//    }
//
//    MNS(c,N,size);
//
//    printf("电路布线最大不相交连线数目为：");
//
//    int Net[N],m;
//    Traceback(c,size,N,Net,m);
//
//    printf("最大不相交连线分别为：");
//    for(int i=m-1; i>=0; i--){
//        printf("Net[%d]=%d,c[Net[i]]=%d",i,Net[i],c[Net[i]]);
//    }
//    return 0;
//}

#include <stdlib.h>
#include <stdio.h>
#define N 10
int m=0;

int maxNum(){
    int size[N+1][N+1];
    int pi[N+1]={0,8,7,4,2,5,1,9,3,10,6};
    int n=10;
    int i,j;
    for(j=0;j<pi[1];j++){
        size[1][j]=0;
    }
    for(j=pi[1];j<=n;j++){
        size[1][j]=1;
    }
    for(i=2;i<n;i++){
        printf("i=%d\n",i);
        printf("j=pi[%d]=%d\n",j,pi[i]);
        for(j=0;j<pi[i];j++){
            //printf("i=%d,j=%d\n",i,j);
            size[i][j]=size[i-1][j];
            printf("size[%d][%d]=%d\n",i,j,size[i][j]);
        }
        for(j=pi[i];j<=n;j++){
            printf("size[i-1=%d][j=%d]=%d\n",i-1,j,size[i-1][j]);
            printf("size[i-1=%d][pi[i=%d]-1]+1=%d\n",i-1,i,size[i-1][pi[i]-1]+1);
            size[i][j]=size[i-1][j]>=size[i-1][pi[i]-1]+1?size[i-1][j]:size[i-1][pi[i]-1]+1;
            printf("size[%d][%d]=%d\n",i,j,size[i][j]);
        }
        printf("==========================================\n");
    }
    
    size[n][n]=size[n-1][n]>=size[i-1][pi[n]-1]+1?size[n-1][n]:size[n-1][pi[n]-1]+1;
    return size;
}

void constructSet(int size[N+1][N+1]){
    int pi[N+1]={0,8,7,4,2,5,1,9,3,10,6};
    int n=10;
    int i,j=n;
    m=0;
    int net[10];
    for(i=n;i>1;i--){
        if(size[i][j]!=size[i-1][j]);
        net[m++]=i;
        j=pi[i]-1;
    }
    if(j>=pi[1]){
        net[m++]=1;
    }
}

int main(){
    
    int size[N+1][N+1];
    int pi[N+1]={0,8,7,4,2,5,1,9,3,10,6};
    int n=10;
    int i,j;
    for(j=0;j<pi[1];j++){
        size[1][j]=0;
    }
    for(j=pi[1];j<=n;j++){
        size[1][j]=1;
    }
    for(i=2;i<n;i++){
        printf("i=%d\n",i);
        printf("j=pi[%d]=%d\n",j,pi[i]);
        for(j=0;j<pi[i];j++){
            //printf("i=%d,j=%d\n",i,j);
            size[i][j]=size[i-1][j];
            printf("size[%d][%d]=%d\n",i,j,size[i][j]);
        }
        for(j=pi[i];j<=n;j++){
            printf("size[i-1=%d][j=%d]=%d\n",i-1,j,size[i-1][j]);
            printf("size[i-1=%d][pi[i=%d]-1]+1=%d\n",i-1,i,size[i-1][pi[i]-1]+1);
            size[i][j]=size[i-1][j]>=size[i-1][pi[i]-1]+1?size[i-1][j]:size[i-1][pi[i]-1]+1;
            printf("size[%d][%d]=%d\n",i,j,size[i][j]);
        }
        printf("==========================================\n");
    }
    
    size[n][n]=size[n-1][n]>=size[i-1][pi[n]-1]+1?size[n-1][n]:size[n-1][pi[n]-1]+1;
    
    
    

    int a,b=n;
    int c=0;
    int net[10];
    for(a=n;a>1;a--){
        if(size[a][b]!=size[a-1][b]);
        net[c++]=a;
        b=pi[a]-1;
    }
    if(b>=pi[1]){
        net[c++]=1;
    }
    
    
    
    return 0;
}
