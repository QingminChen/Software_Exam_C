//
//  main.c
//  Dynamic_Programming_Longest_Common_Subsequence
//
//  Created by Chen Qingmin on 5/12/21.
//

//#include <stdio.h>
//
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("Hello, World!\n");
//    return 0;
//}

//O(m*n)

#include <stdio.h>
#include <string.h>
//#include <math.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

int c[8][7];
int maxi;
int maxj;

int lcsq(char *a,int m,char *b,int n){
    char x[8]={'0','A','B','C','A','D','A','B'};
    char y[7]={'0','B','D','C','A','B','A'};
    int i,j;
    int max=0;
    maxi=0;
    maxj=0;
    for(i=0;i<=m;i++){
        c[i][0]=0;
    }
    for(i=0;i<=n;i++){
        c[0][i]=0;
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            printf("i=%d,j=%d\n",i,j);
            printf("x[i=%d]=%d,y[j=%d]=%d\n",i,x[i],j,y[j]);
            if(x[i]==y[j]){
                c[i][j]=c[i-1][j-1]+1;
                printf("match x[i]=%d y[j]=%d\n",x[i],y[j]);
                if(max<c[i][j]){//Not really be used
                    max=c[i][j];
                    maxi=i;
                    maxj=j;
                    printf("maxi=%d,maxj=%d\n",maxi,maxj);
                }
            }else{
                printf("c[i=%d][j-1=%d]=%d,c[i-1=%d][j=%d]=%d\n",i,j-1,c[i][j-1],i-1,j,c[i-1][j]);
                c[i][j]=MAX(c[i][j-1],c[i-1][j]);
            }
        }
    }
    printf("max=%d\n",max);
    printf("c[m][n]=%d\n",c[m][n]);
    return c[m][n];
    //return max;
}

void printLCS(int max,char *x){// no use
    int i=0;
    if(max==0){
        return;
    }
    for(i=maxi-max;i<maxi;i++){
        printf("%c",x[i]);
    }
    printf("\n");
}//答案错误

int main(int argc, const char * argv[]) {
    // insert code here...
    char* x="ABCADAB";//这里开头没把0算上，是不对的
    char* y="BDCABA";
    int max=0;
    int m = strlen(x);
    int n = strlen(y);
    max=lcsq(x,m,y,n);
    printLCS(max,x);  //BCAA  BCAB
    return 0;
}
