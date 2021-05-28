//
//  main.c
//  LongestAscendSubsequenceLength
//
//  Created by Chen Qingmin on 4/10/21.
//

#include <stdio.h>

//2,4,3,7,6,5,8,1,0,9
int data[10]={2,4,3,7,6,5,8,1,0,9},mark[11]={0},loc[11],n=10,len;

void MaxLongSequence(){
//    int data[10]={2,4,3,7,6,5,8,1,0};
    int i,j;
    mark[0]=1; //b
    loc[0]=-1;
    for(i=0;i<n;i++){    //i=1 or i=0 both of them are okay //表示以i为结尾的序列，i从0开始从1开始都是可以的，因为0的时候，j没有值可以取，没关系的
        for(j=0,len=0;j<i;j++){
            if(data[i]>=data[j]&&len<mark[j]){
                len=mark[j];
                loc[i]=j;//  when the string total lenght is i+1, to see which position can get longest ascending subsequence in string-1,position starts from 0
                printf("loc[i=%d]=j=%d,",i,j);
            }
            mark[i]=len+1; // len didn't increase itself,when the string total lenght is i+1,longest non-decreasing subsequence 's lenghth in string
            
            printf("len=%d,mark[i=%d]=%d\n",len,i,mark[i]);
        }
    }
}


void Input(){
    int i;
    printf("请输入元素个数：");
    scanf("%d",&n);
    printf("序列成员为:");
    for(i=0;i<n;i++)
        scanf("%d",&data[i]);
}


//输出最长的长度，以及最大递增子序列的成员
void Output(){
    int i,max=0,m;
    int res[20],k=0;
    for(i=0;i<n;i++)
        if(mark[i]>mark[max])
            max=i;
    printf("最长序列为:%d",mark[max]);
    res[k++]=data[max];
    while(mark[max]>1)  //推递增子序列的成员
    {
        m=loc[max];
        res[k++]=data[m];
        max=m;
    }
    printf("\n最长递增序列为:");
    for(i=k-1;i>=0;i--)
        printf("%d ",res[i]);
}


int main(){
//    int b[]={2,4,3,7,6,5,8,1,0,9};
//    int abc=sizeof(b)/sizeof(b[0]);
//    printf("\n abc=%d\n:",abc);
//    Input();
    MaxLongSequence();
    Output();
    return 0;
}
