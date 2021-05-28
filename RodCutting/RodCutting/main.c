//
//  main.c
//  RodCutting
//
//  Created by Chen Qingmin on 4/11/21.
//

#include <stdio.h>
//#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define N 5

const int INF = 100000;
int r[N+1];

void init_r() {
  int i;
  r[0] = 0;
  for(i=1; i<=N; i++) {
    r[i] = -1*INF;
  }
}

int top_down_rod_cutting(int c[], int n) {
    printf("top_down_rod_cutting n=%d\n",n);
  if (r[n] >= 0) {
      printf("r[%d]>=0\n",n);
    return r[n];
  } // this is the final result

  int maximum_revenue = -1*INF;
  int i;

  for(i=1; i<=n; i++) {
      printf("top_down_rod_cutting n=%d,i=%d,n-i=%d\n",n,i,n-i);
      //maximum_revenue = MAX(maximum_revenue, c[i] + top_down_rod_cutting(c, n-i));
      maximum_revenue = maximum_revenue>=(c[i] + top_down_rod_cutting(c, n-i))?maximum_revenue:(c[i] + top_down_rod_cutting(c, n-i));
      //总长-已经切的i的长度，因为剩下的没有算过，所以要再调一下
      printf("maximum_revenue=%d\n",maximum_revenue);
  }
    printf("n=%d\n",n);
  r[n] = maximum_revenue;
    for(int j=0;j<N+1;j++){
        printf("r[%d]=%d\n",j,r[j]);
    }
  return r[n];
}

int bottom_up_rod_cutting(int c[], int n) {
    printf("bottom_up_rod_cutting n=%d\n",n);
//  int r[n+1];
  r[0] = 0;
  int i,j;

  for(j=1; j<=n; j++) {
      printf("j=%d\n",j);
    int maximum_revenue = -1*INF;
    for(i=1; i<=j; i++) {
        printf("i=%d\n",i);
        printf("c[%d],r[%d]\n",i,j-i);
        //maximum_revenue = MAX(maximum_revenue, c[i] +r[j-i]);
        maximum_revenue = maximum_revenue>=(c[i] +r[j-i])?maximum_revenue:(c[i] +r[j-i]);
        //因为是一米一米总长度规模增加的，这里的总长度是j-i的出来的一定是1开始，这个我们之前算过，是一定拿到结果的，这里不需要再调了
//        maximum_revenue=MAX(r[j-1]+c[i],r[j-1]); //Wrong
        printf("maximum_revenue=%d\n",maximum_revenue);
    }
    r[j] = maximum_revenue;
      for(int j=0;j<N+1;j++){
          printf("r[%d]=%d ",j,r[j]);
      }
      printf("\n");
      printf("r[%d]=%d\n",j,r[j]);
      printf("================================\n");
  }
  return r[n];
}

int main() {
  init_r();
  // array starting from 1, element at index 0 is fake
  int c[] = {0, 10, 24, 30, 40, 45};   //Price Array
printf("%d\n", top_down_rod_cutting(c, N));
//printf("%d\n", bottom_up_rod_cutting(c, N));
  return 0;
}

