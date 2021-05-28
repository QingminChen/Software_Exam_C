//
//  main.c
//  QuickSortMid
//
//  Created by Chen Qingmin on 4/22/21.
//

#include <stdio.h>

//#include<string>
//using namespace std;
 
 
void QuickSort(int data[], int seq[], int low, int high)
{
    if( low < high )
    {
        int pivot = data[ (low+high)/2 ];
        int tmp;
 
        //data[ (low+high)/2 ] = data[low];
        //data[low] = pivot;
 
        int low_org = low;
        int high_org = high;
 
        while( low < high )
        {
            while( data[high] > pivot )
                high--;
            while( data[low] <= pivot && low < high )
                low++;
 
            if( low < high )
            {
                tmp = data[low];
                data[low] = data[high];
                data[high] = tmp;
 
                tmp = seq[low];
                seq[low] = seq[high];
                seq[high] = tmp;
                for(int j = 0; j < 10; j++){
                    printf("data[%d]:%d,",j,data[j]);
                }
                printf("\n========================================================================================\n");
            }
        }
 
        //tmp = data[low];
        //data[low_org] = tmp;
        //data[low] = pivot;
        //tmp = data[ (low_org+high_org )];
        //data[ (low+high)/2 ] = data[low];
        //data[low] = tmp;
 
 
        QuickSort(data, seq, low_org, low-1);
        QuickSort(data, seq, low+1, high_org);
    }
}

int main(void)
{
    
    int qingmin=8.9;
    int number[10] = {4,23,9,11,5,63,5,33,8,100};
    int seq[10] = {1,2,3,4,5,6,7,8,9,10};//no used
    QuickSort( number, seq, 0, 9 );
 
    for(int i = 0; i < 10; i++){  //no used
        printf("seq[%d]:%d\n",i,seq[i]);
    }
 
    return 0;
}
