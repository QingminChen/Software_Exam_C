//
//  main.c
//  Dynamic_StringPairs
//
//  Created by Chen Qingmin on 5/16/21.
//

#include <stdio.h>
#include <stdlib.h>
#define LEN 11

int isMatch(char a,char b){
    if((a=='A'&&b=='U')||(a=='U'&&b=='A')){
        return 1;
    }
    if((a=='C'&&b=='G')||(a=='G'&&b=='C')){
        return 1;
    }
    return 0;
}

int RNA_2(int n){
    int i,j,k,t,max;
    int c[LEN][LEN]={0};
    char B[]={' ','A','C','C','G','G','U','A','G','U'};
    for(k=5;k<=n-1;k++){//代表的是差值，因为要中间有4个元素，所以差值至少是5，并且差值不能取到刚好加上它就越界了
        for(i=1;i<=n-k;i++){
            j=i+k;
            max=c[i][j-1];//假如j此时不能找到匹配，它就是j-1的问题
            for(t=i;t<j-4;t++){//here it should be less than j-4 no equal，since t and j has less then 4 elements
                printf("k=%d,i=%d,j=i+k=%d,t=%d,j-4=%d\n",k,i,j,t,j-4);
                if(isMatch(B[t],B[j])&&max<c[i][t-1]+1+c[t+1][j-1]){//j和中间的t匹配
                    max=c[i][t-1]+1+c[t+1][j-1];
                    printf("matched,c[i=%d][t-1=%d]=%d,c[t+1=%d][j-1=%d]=%d,max=%d\n",i,t-1,c[i][t-1],t+1,j-1,c[t+1][j-1],max);
                }
//                printf("change the postion t of char which is matched very last position at j in each(i,j) string \n");
            }
            c[i][j]=max;
            printf("c[%d][%d]=%d\n",i,j,c[i][j]);
//            printf("change the start char position i,and end char position j with fix incremental k\n");
        }
        printf("===============================\n");
        printf("change the incremental k\n");
    }
    
    printf("c[1][n]=%d\n",c[1][n]);
    return c[1][n];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    RNA_2(9);
    return 0;
}
