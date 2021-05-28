#include <stdio.h>

//Mean O(n^2)  Worst O(n^2)  best O(n)  space O(1)  stable
 
void Swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
// Direct insertion sort ascending
void InsertSort_Up(int* arr, int length){
     int i,k;
     // Assume that the 0th element is already in ordered list, from the first element to insert data into the ordered list
    for (i = 1; i < length; i++){
        int temp = arr[i];
        int j;
        for (j = i - 1; j >= 0 && arr[j] > temp; j--){
             arr[j + 1] = arr[j];// Move forward
        }
        for(k=0;k<10;k++){
            printf("arr[%d]:%d\n",k,arr[k]);
        }
        printf("++++++++++++++++++++\n");
        arr[j + 1] = temp;
    }
    return;
}
 
 // Direct insert sorting descending
void InsertSort_Down(int* arr, int length){
     int i;
     // Assume that the 0th element is an ordered list, from the first element to insert data into the ordered list
    for (i = 1; i < length; i++){
        int temp = arr[i];
        int j;
        for (j = i - 1; j >= 0 && arr[j] < temp; j--){
             arr[j + 1] = arr[j];// Move forward
        }
        arr[j + 1] = temp;
    }
    return;
}
 
void PrintArr(int* arr, int length){
    int i;
    for ( i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}
 
int main( ){
    int a[] = {3, 5, 2, 1, 9, 0, 6, 4, 7, 8};
    int length = sizeof(a) / sizeof(a[0]);
    InsertSort_Up(a, length);
    PrintArr(a, length);
//    InsertSort_Down(a, length);
//    PrintArr(a, length);
    return 0;
}
