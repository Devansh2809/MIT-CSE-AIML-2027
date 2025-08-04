#include<stdio.h>
#include<stdlib.h>

void Mult2(int *arr, int size) {
    for (int i = 0; i < size; i++)
        arr[i] *= 2;
}

int* NewArr(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr!=NULL)
        for (int i = 0; i < size; i++)
            arr[i] = (i+1) * 10;
    return arr;
}


void ModArr(int **arr, int size) {
    *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        (*arr)[i] = (1+i) * 3;
    }
}

int main() {
    int size, n,len;
    printf("Enter size of original array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr)
        for (int i = 0; i < size; i++)
            arr[i] = i + 1;
    printf("Original Array: \n");
    for(int i=0;i<size;i++)
        printf("%d ", arr[i]);
    Mult2(arr, size);
    printf("\nNew array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    printf("Enter size for the creation of an array: ");
    scanf("%d", &len);
    int *newArr = NewArr(len);
    if (newArr) {
        printf("Array created by returning pointer from a function: ");
        for (int i = 0; i < len; i++)
            printf("%d ", newArr[i]);
        printf("\n");
        free(newArr);
    }
    int *narr,m;
    printf("Enter size for the creation of an array using pointer to pointer: ");
    scanf("%d", &m);
    ModArr(&narr, m);
    printf("Created array:\n");
    for (int i = 0; i < m; i++) {
        printf("%d ", narr[i]);
    }
    printf("\n");
    free(narr);

}
