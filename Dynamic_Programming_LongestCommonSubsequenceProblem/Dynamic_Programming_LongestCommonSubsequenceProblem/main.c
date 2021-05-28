//
//  main.c
//  Dynamic_Programming_LongestCommonSubsequenceProblem
//
//  Created by Chen Qingmin on 5/12/21.
//

//O(nm) result:AB

#include <stdio.h>
#include <string.h>

int c[8][7];
int maxi;
int maxj;

int lcs(char *x,int m,char *y,int n){
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
            printf("x[i-1=%d]=%d,y[j-1=%d]=%d\n",i-1,x[i-1],j-1,y[j-1]);
            if(x[i-1]==y[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                if(max<c[i][j]){
                    max=c[i][j];
                    maxi=i;
                    maxj=j;
                    printf("maxi=%d,maxj=%d\n",maxi,maxj);
                }
            }else{
                c[i][j]=0;
            }
        }
    }
    return max;
}

void printLCS(int max,char *x){
    int i=0;
    if(max==0){
        return;
    }
    for(i=maxi-max;i<maxi;i++){
        printf("%c",x[i]);
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    // insert code here...
    char* x="ABCADAB";
    char* y="BDCABA";
    int max=0;
    int m = strlen(x);
    int n = strlen(y);
    max=lcs(x,m,y,n);
    printLCS(max,x);
    return 0;
}
