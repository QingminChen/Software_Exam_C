//
//  main.c
//  Sort_Bubble
//
//  Created by Chen Qingmin on 5/17/21.
//

// mean O(n^2) worst O(n^2) O(1) stable
#include <stdio.h>
#define N 4

int main(int argc, const char * argv[]) {
    // insert code here...
//    printf("Hello, World!\n");
    //               0 1 2 3 4  5 6  7  8
    int size=9,a[9]={1,5,4,3,11,8,20,56,15};
    int i,j,temp;
    for(i=size-2;i>=0;i--){
        for(j=0;j<=i;j++){
            printf("i=%d,j=%d,j+1=%d\n",i,j,j+1);
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        for(int m=0;m<size;m++){
            printf("a[%d]=%d ",m,a[m]);
        }
        printf("\n=============================\n");
    }
    
    return 0;
}
