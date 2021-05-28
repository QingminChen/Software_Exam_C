//
//  main.c
//  Hamilton
//
//  Created by Chen Qingmin on 4/10/21.

#include <stdio.h>
#include <stdbool.h>
#define MAX 20

void Hamilton(int n){
    int x[5];
    int c[5][5]={{0, 1, 0, 1, 0},{1, 0, 1, 1, 1},{0, 1, 0, 0, 1},{1, 1, 0, 0, 1},{0, 1, 1, 1, 0}};//exist path
    //int c[5][5]={{0, 1, 0, 1, 0},{1, 0, 1, 1, 1},{0, 1, 0, 0, 1},{1, 1, 0, 0, 0},{0, 1, 1, 0, 0}};//doesn't exist path
    int i;
    int visited[n];
    int k;
    /*初始化x数组和visited数组*/
    for(i=0;i<n;i++){
        x[i]=0;
        visited[i]=0;
    }
    /*起始顶点,起始就站在0号节点，就直接初始就访问了的*/
    k=0;  //k代表的是第几趟访问，初始是第0趟，就是站在V0处，第一趟就是V1节点
    visited[0]=1;
    x[0]=0;//理论上是没有第0次的，但是这里第0次访问的节点就是0号位置，就是初始就站在0号位置，不存在遍历这一说
    k=k+1;
    /*访问其他顶点*/
    while(k>=0){//每次，比如当前是第k次，访问一个新的节点，都要看k-1次访问的节点跟当前要访问的节点是否有路径，并且当前访问的节点，没有访问过
        x[k]=x[k]+1;
        while(x[k]<n){
            if((visited[x[k]]==0) && c[x[k-1]][x[k]]==1){/*邻接顶点x[k]未被访问过*/
                break;
            }else{
                x[k] = x[k] + 1; //第k=2趟访问V1节点，因为访问过，尝试访问V2=x[2]
            }
        }
        if(x[k]<n&&k==n-1&&c[x[k]][0]==1){ /*找到一条哈密尔顿回路*/ //判断当前趟数k是不是最后一个编号的节点
            for(k=0;k<n;k++){
                printf("%d--",x[k]); /*输出哈密尔顿回路*/
            }
            printf("%d--\n",x[0]) ;
            return;
        }else if (x[k]<n&&k<n-1){/*设置当期顶点的访问标志，继续下一个顶点*/
            visited[x[k]]=1;
            k=k+1;
        }else{/*没有未被访问过的邻接顶点，回退到上一个顶点*/  //回溯的时候，你只能访问比当前趟数大的节点，已经小的节点都试过了，小的节点访问过是靠x[k]来控制的
            x[k]=0;
            visited[x[k]]=0;
            k=k-1;
        }
   }
   for(int abc=0;abc<20;abc++){
        printf("abc:%d,x[abc]=%d\n",abc,x[abc]);
    }
}

//int main(){
//    int n=4;
//    int x[20];
//    int c[4][4] ={
//        {0,1,2,-1} ,
//        {0,1,2,3} ,
//        {0,1,2,3} ,
//        {-1,1,2,3}
//    };
//
//    Hamilton(n,x,c);
//    return 0;
//}





#define V 5

void printSolution(int path[]);

bool isSafe(int v, bool graph[V][V], int path[], int pos){
    if (graph [ path[pos-1] ][ v ] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamCycleUtil(bool graph[V][V], int path[], int pos)
{
    if (pos == V)
    {

        if ( graph[ path[pos-1] ][ path[0] ] == 1 )
           return true;
        else
          return false;
    }
    for (int v = 1; v < V; v++)
    {
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;
            
            for(int m=0;m<5;m++){
                printf("path[%d]=%d\n",m,path[m]);
            }

            if (hamCycleUtil (graph, path, pos+1) == true)
                return true;

            path[pos] = -1;
            for(int n=0;n<5;n++){
                printf("path[%d]=%d\n",n,path[n]);
            }
        }
    }

    return false;
}


bool hamCycle(bool graph[V][V]){
    int abc[V];
    int *path = abc;
    for (int i = 0; i < V; i++){
        path[i] = -1;
    }
    path[0] = 0;
    if ( hamCycleUtil(graph, path, 1) == false )
    {
        printf("\nSolution does not exist.\n");
        return false;
    }

    printSolution(path);
    return true;
}

void printSolution(int path[])
{
    printf ("Solution Exists:"
            " Following is one Hamiltonian Cycle \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", path[i]);

    // Let us print the first vertex again to show the complete cycle
    printf(" %d ", path[0]);
    printf("\n");
}

int main()
{
   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)-------(4)    */
   bool graph1[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };

    // Print the solution
//    hamCycle(graph1);

//   /* Let us create the following graph
//      (0)--(1)--(2)
//       |   / \   |
//       |  /   \  |
//       | /     \ |
//      (3)       (4)    */
//    bool graph2[V][V] = {{0, 1, 0, 1, 0},
//                      {1, 0, 1, 1, 1},
//                      {0, 1, 0, 0, 1},
//                      {1, 1, 0, 0, 0},
//                      {0, 1, 1, 0, 0},
//                     };
//
//    // Print the solution
//    hamCycle(graph2);
    
    Hamilton(5);

    return 0;
}
