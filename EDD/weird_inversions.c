#include<stdio.h>
#include<stdlib.h>

int inversiones = 0;
void _merge(int* A, int l, int mid, int r){
    int n_1 = mid - l + 1;
    int n_2 = r - mid;
    int* L = calloc(n_1, sizeof(int));
    int* R = calloc(n_2, sizeof(int));

    for(int i = l; i <= mid; i++) L[i - l] = A[i];
    for(int i = mid + 1; i <= r; i++) R[i - mid - 1] = A[i];

    
    int i = 0, j = 0;
    while(i < n_1 && j < n_2){
        if (L[i] > 2 * (long)R[j]) {
            A[l + i + j] = R[j];
            j++;
            inversiones += n_1 - i;
            printf(" SUMA %d\n", inversiones);
        } else {
            A[l + i + j] = L[i];
            i++;
        }
    }
    
    while (i < n_1) {
        A[l + i + j] = L[i];
        i++;
    }
    
    while (j < n_2) {
        A[l + i + j] = R[j];
        j++;
    }
    
    free(L); free(R);
}


void _merge_sort(int* A, int l, int r){
    printf("AQUI: ");
    for(int i = l; i <= r; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
    if (l == r) return;

    int mid = l + (r - l) / 2;
    _merge_sort(A, l, mid);
    _merge_sort(A, mid + 1, r);
    _merge(A, l, mid, r);
}

void merge_sort(int* A, int n){
    _merge_sort(A, 0, n - 1);
}


int reversePairs(int* nums, int numsSize) {
    merge_sort(nums, numsSize);
    return inversiones;
}

int main(){
    int n;
    scanf("%d", &n);
    int* A = calloc(n, sizeof(int));
    for(int i = 0; i < n;i++){
        scanf("%d", &A[i]);
    }

    merge_sort(A, n);
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }

    printf("\n%d\n", inversiones);
    free(A);    
}