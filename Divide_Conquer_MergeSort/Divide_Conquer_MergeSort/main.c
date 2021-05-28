#include <stdio.h>
#include <stdlib.h>
#define N 6
void merge(int arr[], int low, int mid, int high){
    for(int m=0;m<N;m++)
        printf("%d\t",arr[m]);
    printf ("\nlow:%d,mid:%d,hight:%d\n",low,mid,high);
    int i, k;
    int *tmp = (int *)malloc((high-low+1)*sizeof(int));
    //申请空间，使其大小为两个
    int left_low = low;
    int left_high = mid;
    int right_low = mid + 1;
    int right_high = high;
    printf ("Before left_low:%d,left_high:%d,right_low:%d,right_high:%d\n",left_low,left_high,right_low,right_high);
    for(k=0; left_low<=left_high && right_low<=right_high; k++){  // 比较两个指针所指向的元素
        if(arr[left_low]<=arr[right_low]){
            tmp[k] = arr[left_low++];
            printf ("left_low<=right_low,tmp[k]:%d\n",tmp[k]);
        }else{
            tmp[k] = arr[right_low++];//这里是++
            printf ("left_low>right_low,left over,tmp[k]:%d\n",tmp[k]);
        }
        printf("After left_low:%d,left_high:%d,right_low:%d,right_high:%d,k:%d\n",left_low,left_high,right_low,right_high,k);
    }
    printf("Out loop k:%d\n",k);
    if(left_low <= left_high){  //若第一个序列有剩余，直接复制出来粘到合并序列尾
    //memcpy(tmp+k, arr+left_low, (left_high-left_low+l)*sizeof(int));
        for(i=left_low;i<=left_high;i++){
            printf ("Before k=%d,tmp[k]:%d\n",k,arr[i]);
            tmp[k++] = arr[i];
            printf ("After k=%d\n",k);
        }
    }
    if(right_low <= right_high){
    //若第二个序列有剩余，直接复制出来粘到合并序列尾
    //memcpy(tmp+k, arr+right_low, (right_high-right_low+1)*sizeof(int));
        for(i=right_low; i<=right_high; i++)
            tmp[k++] = arr[i];
    }
    for(i=0; i<high-low+1; i++)
        arr[low+i] = tmp[i];
    for(i=0; i<N; i++){
        printf ("arr[%d]=%d\n ",i,arr[i]);
    }
    printf ("\n====================================\n");
    
    free(tmp);
    return;
}
void merge_sort(int arr[], unsigned int first, unsigned int last){
    printf ("\nfirst:%d,last:%d\n",first,last);//分到2个或者1个时候，就开始一半边一半边开始合并，左半边都合并完了，再整体处理右半边
    int mid = 0;
    if(first<last){
        mid = (first+last)/2; /* 注意防止溢出 */
        printf ("mid:%d\n",mid);
        /*mid = first/2 + last/2;*/
        //mid = (first & last) + ((first ^ last) >> 1);
        merge_sort(arr, first, mid);
        printf ("mid+1:%d\n",mid+1);
        merge_sort(arr, mid+1,last);
        merge(arr,first,mid,last);
    }
    return;
}
int main(){
    int i;
    //int a[N]={60,12,78,56,76,45,36};
    int a[N]={1,1,2,4,7,5};
    printf ("排序前 \n");
    for(i=0;i<N;i++)
        printf("%d\t",a[i]);
    merge_sort(a,0,N-1);  // 排序
    printf ("\n 排序后 \n");
    for(i=0;i<N;i++)
        printf("%d\t",a[i]); printf("\n");
//    system("pause");
    return 0;
}
