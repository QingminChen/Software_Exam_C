//
//  main.c
//  0_1_kpack_backtrace
//
//  Created by Chen Qingmin on 4/25/21.
//

#include <stdio.h>
#include <stdlib.h>


float Bound(float *Value, int *Weights, float *VW, int n, int W, float Profit_Gained, int Weight_Used, int k){
    printf("Bound k=%d\n",k);
    int i;
    for(i=k+1;i<n;i++){
        if(Weight_Used+Weights[i]<=W){
            Profit_Gained+=Value[i];
            Weight_Used+=Weights[i];
        }else{
            //Profit_Gained+=VW[i]*(W-Weight_Used);
            //Weight_Used=W;
            return Profit_Gained;
        }
    }
    return Profit_Gained;
}

int *Knapsack(float *Values, int *Weights, float *VW, int n, int W){
    int current_weight=0;
    int current_profit=0;
    int Weight=0;
    float Profit=-1;
    int index=0;
    int *X=(int *)malloc(sizeof(int)*(n+1));  //Final result
    int *Y=(int *)malloc(sizeof(int)*(n+1));  //Temporary result
    for(int j=0;j<n;j++){
        X[j]=-1;
        Y[j]=-1;
    }
    for(int qingmin=0;qingmin<=n;qingmin++){
        printf("Knapsack X[%d]=%d\n",qingmin,X[qingmin]);
        printf("Knapsack Y[%d]=%d\n",qingmin,Y[qingmin]);
    }
    printf("Knapsack======================================\n");
    while(1){
        while(index<n&&current_weight+Weights[index]<=W){
            current_profit+=Values[index];
            current_weight+=Weights[index];
            Y[index]=1;
            index++;
            for(int qingmin=0;qingmin<=n;qingmin++){
                printf("while(1) Y[%d]=%d\n",qingmin,Y[qingmin]);
            }
            printf("while(1) index<n======================================\n");
        }
        if(index>=n){
            Weight=current_weight;
            Profit=current_profit;
            index=n;
            int i;
            for(i=0;i<n;i++){
                X[i]=Y[i];
            }
            for(int qingmin=0;qingmin<=n;qingmin++){
                printf("index>=n X[%d]=%d\n",qingmin,X[qingmin]);
                printf("index>=n Y[%d]=%d\n",qingmin,Y[qingmin]);
            }
            printf("index>=n======================================\n");
        }else{
            Y[index]=0;
            for(int qingmin=0;qingmin<=n;qingmin++){
                printf("index>=n else Y[%d]=%d\n",qingmin,Y[qingmin]);
            }
            printf("index>=n else======================================\n");
        }
        while(Bound(Values,Weights,VW,n,W,current_profit,current_weight,index)<=Profit){
            for(int qingmin=0;qingmin<=n;qingmin++){
                printf("while Bound X[%d]=%d\n",qingmin,X[qingmin]);
                printf("while Bound Y[%d]=%d\n",qingmin,Y[qingmin]);
            }
            printf("while Bound======================================\n");
            while(index!=0&&Y[index]!=1){
                index--;
            }
            if(index==0){
                for(int m=0;m<n;m++){
                    printf("X[%d]=%d\n",m,X[m]);
                }
                printf("profit=%f\t weight=%d\n",Profit,Weight);
                if(Y[0]==0){
                    return X;
                }else{
                    Y[0]=0;
                    index=0;
                    current_profit=0;
                    current_weight=0;
                    Weight=0;
                    Profit=-1;
                    continue;
                }
            }
            Y[index]=0;
            current_profit-=Values[index];
            current_weight-=Weights[index];
        }
        index++;
    }
}







int main(int argc, const char * argv[]) {
    int W=22;
    int n=3;
    
    int Weights[]={15,10,10};
    float Values[]={30,18,17};
    float VW[]={2,1.8,1.7};
    
    Knapsack(Values, Weights, VW, n, W);
    return 0;
}
