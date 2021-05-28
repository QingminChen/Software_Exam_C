//
//  main.c
//  0_1_pack_dynamic

//  Up to down
//
//  Created by Chen Qingmin on 4/11/21.
//

#include <stdio.h>
#include <math.h>
#define N 6
# define maxT 1000

int count=0;
int c[N][12]={0};
int v[]={0,1,6,18,22,28};
int w[]={0,1,2,5,6,7};

int Calculate_Max_Value(int v[],int w[],int i,int j){
    printf("Calculate_Max_Value i=%d,j=%d\n",i,j);
    int temp=0;
    if(c[i][j]!=-1){
        printf("Has value c[%d][%d]\n",i,j);
        return c[i][j];
    }
    if(i==0||j==0){
        printf("i=%d,j=%d\n",i,j);
        c[i][j]=0;
    }else{
        printf("Else Before c[%d][%d]=%d\n",i,j,c[i][j]);
        printf("Else Before i-1=%d,j=%d\n",i-1,j);
        c[i][j]=Calculate_Max_Value(v,w,i-1,j);
        printf("Else After c[%d][%d]=%d\n",i,j,c[i][j]);
//        if(i>0&&j>=w[i]){
        if(i>0&&j>=w[i]){
            printf("j>=w[%d] i-1=%d,j-w[%d]=%d\n",i,i-1,i,j-w[i]);
            temp=Calculate_Max_Value(v,w,i-1,j-w[i])+v[i];
//            temp=c[i-1][j-w[i]]+v[i]; wrong
            printf("temp=%d\n",temp);
            if(temp>c[i][j]){
                printf("temp>c[%d][%d],temp=%d,c[%d][%d]=%d\n",i,j,temp,i,j,c[i][j]);
                c[i][j]=temp;
            }
        }
    }
    printf("return c[%d][%d]=%d\n",i,j,c[i][j]);
    printf("++++++++++++++++++++++++++++++++++++++++\n");
    if(c[i][j]>=0){
        count++;
        printf("c[%d][%d]=%d\t",i,j,c[i][j]);
    }
    if(count%3==0){
        printf("\n");
    }
    return c[i][j];
}

int Memorized_knapsack(int T){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<=T;j++){
            c[i][j]=-1;
        }
    }
    return Calculate_Max_Value(v,w,N-1,T);
}

int main(int argc, const char * argv[]) {
    // insert code here...

    int result =-1;
    result=Memorized_knapsack(11);
    printf("result=%d\n",result);
    return 1;
}
