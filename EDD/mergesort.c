#include<stdio.h>
#include<stdlib.h>

int inversiones = 0;

void _merge(int* A, int l, int mid, int r){
    int n_1 = mid - l + 1;
    int n_2 = r - mid;
    int* L = calloc(n_1, sizeof(int));
    int* R = calloc(n_2, sizeof(int));

    printf("l, r = %d %d\n", l, r);

    for(int i = l; i <= mid; i++) L[i - l] = A[i];
    for(int i = mid + 1; i <= r; i++) R[i - mid - 1] = A[i];

    
    int i = 0, j = 0;
    while(i < n_1 && j < n_2){
        if (L[i] > R[j]) {
            A[l + i + j] = R[j];
            j++;
            inversiones += n_1 - i;
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
    if (l == r) return;
    printf("paso: %d, %d\n", l, r);

    int mid = l + (r - l) / 2;
    _merge_sort(A, l, mid);
    _merge_sort(A, mid + 1, r);
    _merge(A, l, mid, r);
}

void merge_sort(int* A, int n){
    printf("una vez aqui\n");
    _merge_sort(A, 0, n - 1);
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