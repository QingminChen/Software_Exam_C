//
//  main.c
//  MatrixMultiplyDynamic
//
//  Created by Chen Qingmin on 4/25/21.
//


//O(n^3)

//#include <stdio.h>
//#include <stdlib.h>
//void MatrixChain(int p[6],int n,int m[][7],int s[][7])
//{
//    int r=0,i=0,j=0,k=0,t=0;
//    for(i=1;i<=n;i++){
//        m[i][i]=0;
//    }
//    for(r=2;r<=n;r++){
//        for(i=1;i<=n-r+1;i++)//n-r+1表示保证有r个矩阵相乘
//        {
//            j=i+r-1;//当r=3时 有三个矩阵 但j=i+2，所以需要-1
//            m[i][j]=m[i][i]+m[i+1][j]+p[i-1]*p[i]*p[j];//默认在初始下标之后断开，得到初始值
//            s[i][j]=i;
//            for(k=i+1;k<j;k++)
//            {
//                t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
//                if(t<m[i][j]){
//                    m[i][j]=t;
//                    s[i][j]=k;
//                }
//
//            }
//        }
//    }
//}
//void TrackBack(int i,int j, int s[][7])
//{
//    if(i==j) return;
//    TrackBack(i,s[i][j],s);//递归第一次断开之前
//    TrackBack(s[i][j]+1,j,s);
//    printf("A%d",i);
//    printf(" and A%d",j);
//    printf("\n");
//
//}
//int main()
//{
//   int n=6;
//   int p[]={5,10,3,12,5,50,6};
//   int s[7][7]={0};
//   int m[7][7]={0};
//   MatrixChain(p,n,m,s);
//   TrackBack(1,n,s);
//}

//space complexity is O(n^2),since we need to use a matrix to store the intermediate /ˌɪntəˈmiːdiət/ result

#include <stdio.h>
#include <stdlib.h>
#define N 7
int cost[N][N];
int trace[N][N];
int cmm(int n, int seq[]){
    int tempCost;
    int tempTrace;
    int i,j,k,p;
    int temp;
    for(i=0;i<n;i++){
        cost[i][i]=0;
    }
    for(p=1;p<n-1;p++){//列与行的差值 1-5，差值是0的，或者小于0的都不算数的，就是主对角线和0行，0列，还有下三角都不算了
        printf("cmm p:%d\n",p);
        for(i=1;i<n-p;i++){  //i是行，从1开始
            printf("cmm i:%d\n",i);
            j=i+p;//j是列，是2开始，用行数+差值得到列值
            tempCost=900000;
            printf("cmm j:%d\n",j);
            for(k=i;k<j;k++){
                printf("cmm k:%d\n",k);
                temp=cost[i][k]+cost[k+1][j]+seq[i-1]*seq[k]*seq[j];
                if(tempCost==900000||tempCost>temp){
                    tempCost=temp;
                    printf("tempCost[%d][%d][%d]:%d\n",i,k,j,tempCost);
                    tempTrace=k;
                    printf("tempTrace k:%d\n",k);
                }
            }
            cost[i][j]=tempCost;
            printf("cost[%d][%d]:%d\n",i,j,cost[i][j]);
            trace[i][j]=tempTrace;
            printf("trace[%d][%d]:%d\n",i,j,trace[i][j]);
        }
    }
    return cost[1][n-1];
}

int main(){ //it is clear now
   int n=6;
   int p[]={5,10,3,12,5,50,6};
   int result = cmm(N,p);
    printf("result:%d\n",result);
}
