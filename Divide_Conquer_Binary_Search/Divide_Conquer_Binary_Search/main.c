#include <stdio.h>//二分查找算法即测试用例
//Time complexity O(logn)
int BinySerch(int *arr, int x, int lengh)//设计参数，由于是整形数组，所以我们必须传递他
{//长度否则数组传参时会发生降级
    int left=0, right=lengh-1;
    int mid ;
    while (left <= right){
      mid = left + (right - left) / 2;
      if (x < arr[mid]){
         right = mid - 1;
      }else if (x>arr[mid]){
         left = mid + 1;
      }else{
         return mid;
      }
    }
    return -1;
}

int main()//测试用例
{
    int x=0;
    int arr[11]= {2, 5, 7, 8, 12, 16, 20, 25, 32, 50, 80};
    int lengh= sizeof(arr) / sizeof(arr[0]);
//    for(int i = 0; i < 12; i++)
//    {
    printf("%d \n",BinySerch(arr, 20, lengh));
//    }

    return 0;
}

