#include<stdio.h>
#include<stdlib.h>

int main(){
    int n; scanf("%d\n", &n);

    int* A = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    return 0;
}