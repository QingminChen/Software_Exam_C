//
//  main.c
//  Greedy_Multi_Machine_Scheduling
//
//  Created by Chen Qingmin on 5/11/21.
//

//任务已经从小到大时间排列好，最长任务优先的原则
// O(M*N)
#include <stdio.h>
#define M 3  //机器数
#define N 7  //task数

void schedule(){
    int d[M];     //d[i] 第i号机器上面已经跑过的任务所花的总时间
    int s[M][N];  //s[i][j] 第i号机器上面正在跑的第j个（个数，但是从0开始）任务 存的值是真正的任务编号
    int i,j,k,max=0;
    int t[7]={16,14,6,5,4,3,2};
    int count[M];  //count[i] 第i号机器上面跑过的task数量
    for(i=0;i<M;i++){
        d[i]=0;
        for(j=0;j<N;j++){
            s[i][j]=0;
        }
    }
    for(i=0;i<M;i++){
        s[i][0]=i;
        d[i]=t[i];    //这个要填
        count[i]=1;
    }
    for(i=M;i<N;i++){  //这个i从M取要填
        int min=d[0];
        k=0;
        for(j=1;j<M;j++){
            if(min>d[j]){
                min=d[j];
                k=j;
            }
        }
        s[k][count[k]]=i;   //这个要填
        count[k]=count[k]+1;
        d[k]=d[k]+t[i];
    }
    for(i=0;i<M;i++){
        if(d[i]>max){    //这个要填
            max=d[i];
        }
    }
    printf("max:%d\n",max);   //max:17
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    schedule();
    return 0;
}
