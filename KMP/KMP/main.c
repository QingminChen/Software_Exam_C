//
//  main.c
//  KMP
//
//  Created by Chen Qingmin on 5/1/21.
//

//O(lt+ls)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_next(int *next,char *s,int ls){
    int i=0,j=-1;
    next[0]=-1;
    while(i<ls){
        if(j==-1||s[i]==s[j]){
            i++;
            j++;
            if(s[i]==s[j])
                next[i]=next[j];
            else
                next[i]=j;
        }else
            j=next[j];
    }
    for(int m=0;m<ls;m++){
        printf("next[%d]:%d\n",m,next[m]);
    }
}

int kmp(int *next,char *t,char *s,int lt,int ls){
    for(int m=0;m<ls;m++){
        printf("next[%d]:%d\n",m,next[m]);
    }
    int i=0,j=0;
    int count=0;
    while(i<lt&&j<ls){
        count++;
        if(j==-1||t[i]==s[j]){
            i++;
            j++;
        }else
            j=next[j];
    }
    printf("count:%d\n",count);
    if(j>=ls)
        return i-ls+1;
    else
        return -1;
}


void get_next_2(int *lps,char *p, int M) {
   int len = 0;
    lps[0] = 0;
   int i = 1;
   while (i < M) {
      if (p[i] == p[len]) {   //char s[8]={'B','B','A','B','B','C','A','C'};//0,1,0,1,2,0,0,0
         lps[i] = len+1;
         len++;
         i++;
      } else {
         if (len!= 0)
            len = lps[len - 1];
         else {
            lps[i] = 0;
            i++;
         }
      }
   }
    for(int m=0;m<M;m++){
        printf("pps[%d]:%d\n",m,lps[m]);
    }
}

void KMPAlgorithm(int *lps,char *t, char *p,int lt,int lp) {
   int M = lp;
   int N = lt;
    get_next_2(lps,p, M);
   int i = 0;
   int j = 0;
   int count=0;
   while (i < N) {
       printf("i: %d\n",i);
       count=count+1;
      if (p[j] == t[i]) {
         j++;
         i++;
      }
      if (j == M) {
         printf("Found pattern at index %d\n", i - j);
         j = lps[j - 1];
      }else if (i < N && p[j] != t[i]) {
         if (j != 0)
         j = lps[j - 1];
         else
         i = i + 1;
      }
   }
    printf("count: %d\n",count);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    char t[15]={'A','A','B','B','C','B','B','A','B','B','C','A','C','C','D'};
    char p[8]={'B','B','A','B','B','C','A','C'};//0,1,0,1,2,0,0,0
   //char p[8]={'a','b','a','a','b','a','c','a'};//0,0,1,1,2,3,0,1

//    char test[8]={'c','o','c','a','c','o','l','a'};

    int lt=15;
    int lp=8;
    int lps[lp];
    int result=0;
    //get_next_2(next,test,8);
    //get_next_2(next,s,ls);
    KMPAlgorithm(lps,t,p,lt,lp);
    
    printf("result:%d\n",result);
    return 0;
}
