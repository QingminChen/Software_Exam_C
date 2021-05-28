//
//  main.c
//  0_1_kpack_dynamic_bottom_up
//
//  Created by Chen Qingmin on 4/29/21.     O(nw)
//

#include <stdio.h>

//#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("Hello, World!\n");
//    return 0;
    
    int v[6]={0,1,6,18,22,28};
    int wt[6]={0,1,2,5,6,7};
    int T=11,n=5;
    int c[6][12]={{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}};
    
//    for(int a=0;a<=n;a++){
//        for(int b=0;b<=T;b++){
//            c[a][b]=-1;
//        }
//    }
    
    
    for(int i=0;i<=n;i++){
        for(int w=0;w<=T;w++){
            if(i==0||w==0){
                c[i][w]=0;
            }else if(wt[i]<=w){
                //c[i][w]=MAX(v[i]+c[i-1][w-wt[i]],c[i-1][w]);
                c[i][w]=v[i]+c[i-1][w-wt[i]]>c[i-1][w]?v[i]+c[i-1][w-wt[i]]:c[i-1][w];
            }else{
                c[i][w]=c[i-1][w];
            }
        }
    }
    printf("c[%d][%d]:%d\n",n,T,c[n][T]);
}
