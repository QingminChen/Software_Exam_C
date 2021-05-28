//
//  main.c
//  Backtrace_N_Queue
//
//  Created by Chen Qingmin on 5/11/21.
//


//Approach #1
#include <stdio.h>
#include <math.h>
#define N 4

int isplace(int pos[],int k){
    int i;
    for(i=1;i<k;i++){
        if((pos[i]==pos[k])||fabs(i-k)==fabs(pos[i]-pos[k])){// score point  pos[i]==pos[k] indicates they are in the same column
            return 0;  // can't place anymore
        }
    }
    return 1;
}

int main(int argc, const char * argv[]) {

    printf("Hello, World!\n");
    int i,j,count=1;
    int pos[N+1];
    for(i=1;i<=N;i++){
        pos[i]=0;
    }
    j=1;//score point
    while(j>=1){
        pos[j]=pos[j]+1;
        while(pos[j]<=N&&isplace(pos,j)==0){//score point to check if it is available
            pos[j]=pos[j]+1;
        }
        if(pos[j]<=N&&j==N){
            printf("approach #%d\n",count++);
            for(i=1;i<=N;i++){
                printf("pos[%d]:%d\n",i,pos[i]);
            }
        }
        if(pos[j]<=N&&j<N){//score point to check if loop to the last queue
            j=j+1;
        }else{
            pos[j]=0;
            j=j-1;//score point  backtrace
            printf("backtrace j %d\n",j);
        }
    }
    return 1;
}


////Approach #2
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//
//#define n 4
//int queen[n+1];
//
//void show(){
//    int i;
//    printf("(");
//    for(i=1;i<=n;i++){
//        printf("%d",queen[i]);
//    }
//    printf(")\n");
//}
//
//int Place(int j){
//    int i;
//    for(i=1;i<j;i++){
//        if(queen[i]==queen[j]||abs(queen[i]-queen[j])==(j-i)){
//            return 0;
//        }
//    }
//    return 1;
//}
//
//void Nqueen(int j){
//    int i;
//    for(i=1;i<=n;i++){
//        queen[j]=i;
//        if(Place(j)){//Place(j)==1
//            if(j==n){
//                show();
//            }else{
//                Nqueen(j+1);
//            }
//        }
//    }
//}
//
//int main(){
//    Nqueen(1);
//    return 0;
//}

