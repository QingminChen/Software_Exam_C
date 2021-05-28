//
//  main.c
//  Divide_Conquer_FakeCoin
//
//  Created by Chen Qingmin on 5/11/21.
//



//Time complexity O(logn)
#include <stdio.h>

//int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("Hello, World!\n");
//    return 0;
//}
#define N 30

int find_false(int coins[],int first,int last)
{
    int i=0;                        //作为遍历的计数器
    int re=0;                        //re作为返回值
    int sum1,sum2,sum3;            //三个用来累加的变量
    sum1=sum2=sum3=0;
    if(first+1==last)                //当遍历到最后两个元素的时候
    {
        if(coins[first]<coins[last])
        {
            re=first;
            return re;
        }
        else
        {
            re=last;
            return re;
        }
    }
    if((last-first+1)%2==0)                //当长度为偶数的时候
    {
        printf("(last-first)/2:%d\n",(last-first)/2);
//        for(i=first;i<first+(last-first)/2+1;i++)    //对前半段求和
        for(i=first;i<(last-first)/2+1;i++)//it is also okay
        {
            printf("i:%d\n",i);
            sum1+=coins[i];
        }
        for(i=first+(last-first)/2+1;i<last+1;i++)    //对后半段求和
        {
            sum2+=coins[i];
        }
        if(sum1<sum2)                //假币在前半段
        {
            re=find_false(coins,first,first+(last-first)/2);
            return re;
        }
        else if(sum2<sum1)            //假币在后半段
        {
            re=find_false(coins,first+(last-first)/2+1,last);
            return re;
        }
    }
    else                        //当长度为奇数的时候
    {
        for(i=first;i<first+(last-first)/2;i++)    //对前半段求和
        {
            sum1+=coins[i];
        }
        for(i=first+(last-first)/2+1;i<last+1;i++)//对后半段求和
        {
            sum2+=coins[i];
        }
        sum3=coins[first+(last-first)/2];            //sum3用于存放中间数据
        if(sum1<sum2)                    //假币在前半段
        {
            re=find_false(coins,first,first+(last-first)/2-1);
            return re;
        }
        else if(sum2>sum1)
        {
            re=find_false(coins,first+(last-first)/2+1,last);
            return re;
        }
        else if(sum1+sum3==sum2+sum3)    //中间的那个就是假币！
        {
            re=first+(last-first)/2;
            //re=(last-first)/2;//wrong
            return re;
        }
    }
    return 0;
}


int main(int argc, const char * argv[])
{
    int coins[N]={3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,3,3,3,3,3,3,3,3,3,3,3,3,3};
    int pos;
//    cout<<"请输入硬币的个数：";
//    cin>>n;
//    cout<<"请分别输入这个"<<n<<"个硬币的重量："<<endl;
//    for(i=1;i<=n;i++)
//    {
//        cin>>a[i];
//    }
    pos=find_false(coins,0,N-1);
    printf("The fake coin is:%d\n",pos);
    return 0;
}
