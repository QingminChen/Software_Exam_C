//
//  main.c
//  n_queen
//
//  Created by Chen Qingmin on 4/25/21.
//

#include <stdio.h>
#include <stdlib.h>
#define n 4
int queen[n+1]; //actually it should be two dimensions matrice,first element stands for the first queen is located at which row of first column, second emlement stands for the second queen is standing at which row of second column

void Show(){
    int i;
    printf("(");
    for(i=1;i<=n;i++){
        printf(" %d",queen[i]);
    }
    printf(")\n");
}

int Place(int j){
    printf("Place j:%d\n",j);
    int i;
    for(i=1;i<j;i++){
        printf("Place for i:%d\n",i);
        if((queen[i]==queen[j])||abs(queen[i]-queen[j])==(j-i)){
            printf("queen[%d] and queen[%d] Conflict.\n",i,j);
            return 0;
        }
    }
    return 1;
}

void Nqueen(int j){
    printf("Nqueen j:%d\n",j);
    int i;
    for(i=1;i<=n;i++){
        printf("Nqueen for i:%d\n",i);
        printf("Nqueen for j:%d\n",j);
        queen[j]=i;
        if(Place(j)){
            printf("Nqueen yes place\n");
            if(j==n){
                Show();
            }else{
                printf("Nqueen yes j+1:%d\n",j+1);
                Nqueen(j+1);
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    Nqueen(1);
    return 0;
}
