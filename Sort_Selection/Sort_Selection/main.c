//
//  main.c
//  Sort_Selection
//
//  Created by Chen Qingmin on 5/18/21.
//


//mean O(n^2), worst O(n^2)  space O(1)  unstable
#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int a[8]={3,7,30,25,12,9,1,2};
    int i,j,n=8;
    for(i=0;i<n;i++){
        int min=a[i];
        int minindex=i;
        for(j=i;j<n;j++){
//            if(a[j]<min){
//                int temp=a[i];
//                a[i]=a[j];
//                a[j]=temp;
//                min=a[j];
//                minindex=j;
//            }
            if(a[j]<min){
                min=a[j];
                minindex=j;
            }
        }
        int temp=a[i];
        a[i]=min;
        a[minindex]=temp;
        for(int m=0;m<n;m++){
            printf("a[%d]=%d ",m,a[m]);
        }
        printf("\n=======================\n");
    }
    return 0;
}
