//
//  main.c
//  ShellSorting
//
//  Created by Chen Qingmin on 5/14/21.
//

//#include <stdio.h>
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("Hello, World!\n");
//    return 0;
//}




//// C++ implementation of Shell Sort
//#include  <stdio.h>
//
///* function to sort arr using shellSort */
//int shellSort(int arr[], int n){
//    printf("n:%d\n",n);
//    // Start with a big gap, then reduce the gap
//    for (int gap = n/2; gap > 0; gap /= 2){
//        // Do a gapped insertion sort for this gap size.
//        // The first gap elements a[0..gap-1] are already in gapped order
//        // keep adding one more element until the entire array is
//        // gap sorted
//        printf("gap:%d\n",gap);
//        for (int i = gap; i < n; i += 1)
//        {
//            // add a[i] to the elements that have been gap sorted
//            // save a[i] in temp and make a hole at position i
//            int temp = arr[i];
//
//            // shift earlier gap-sorted elements up until the correct
//            // location for a[i] is found
//            int j;
//            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
//                arr[j] = arr[j - gap];
//
//            //  put temp (the original a[i]) in its correct location
//            arr[j] = temp;
//        }
//    }
//    return 0;
//}
//
//void printArray(int arr[], int n)
//{
//    for (int i=0; i<n; i++){
//        printf("arr[%d]=%d,",i,arr[i]);
//    }
//    printf("\n");
//}
//
//int main()
//{
//    int arr[] = {15, 9, 7, 8, 20,-1,4};
//    int n = sizeof(arr)/sizeof(arr[0]);
//
//    printf("Array before sorting: \n");
//
//    printArray(arr, n);
//
//    shellSort(arr, n);
//
//    printf("\nArray after sorting: \n");
//    printArray(arr, n);
//
//    return 0;
//}


#include <stdio.h>
void shellsort(int dataNoNeed[],int n){//15和8比较的时候，即使交换了（8，15），也不会继续比较15和4，而是继续比较9和20，7和-1，然后才是15和-4，把15的位置再减一个gap，到这个时候15和-4也交换了，去比较-4和8，再交换，此时j=0，再减一个gap,负值推出循环
    int data[]={15, 9, 7, 8, 20,-1,4};
    int delta[3]={0},k,i=0,t,dk,j;
    k=n;
//    delta=(int *) malloc(sizeof(int)*3);
    if(i==0){
        do{
            k=k/2;
            delta[i++]=k;
        }while(k>1);
        i=0;
        while((dk=delta[i])>0){ //差值的3，1
            for(k=delta[i];k<n;++k){ //从delta[i]组从差值位置第一个开始，比如差值是3的时候，我们从3这个组中第一个组中后者的位置3开始，它的配对是0，然后位置一个一个往后移动
                printf("===========================\n");
                printf("i=%d\n",i);
                printf("dk=%d\n",dk);
                printf("k=%d\n",k);
                printf("data[k-dk=%d]=%d\n",k-dk,data[k-dk]);
                printf("data[%d]=%d\n",k,data[k]);
                if(data[k]<data[k-dk]){// to check if the item in the same group,store the smaller one temporary
                    printf("data[k=%d]<data[k-dk=%d]\n",k,k-dk);
                    t=data[k];
                    printf("t=data[k]=%d\n",t);
                    for(j=k-dk;j>=0&&t<data[j];j-=dk){// Here it means after everytime we swap,we need to also go back previous position in the same group to see if after the swaping the lower position still larger than the latter position in the same group
                        printf("j=%d\n",j);
                        printf("t=%d<data[j=%d]=%d\n",t,j,data[j]);
                        data[j+dk]=data[j];
                        printf("data[j+dk=%d]=%d\n",j+dk,data[j+dk]);
                    }
                    data[j+dk]=t;
                }
            }
            printf("Pass #%d\n",i);
            for(int m=0;m<n;m++){
                printf("data[%d]=%d  ",m,data[m]);
            }
            printf("\n");
            ++i;
        }
    }
}

int main()
{
    int arr[] = {15, 9, 7, 8, 20,-1,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    shellsort(arr,n);

    return 0;
}
