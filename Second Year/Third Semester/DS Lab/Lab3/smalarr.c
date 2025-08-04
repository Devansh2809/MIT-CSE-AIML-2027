#include<stdio.h>
#include<stdlib.h>

int Smallest (int *arr, int len) {
    if (len <= 0)
        return -1;
    int *m = arr;
    for (int i=1;i<len;i++)
        if(*(arr+i) < *m)
            m = arr + i;
    return *m;
}

void main() {
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n*sizeof(int));
    if (arr == NULL) {
        printf("Memory Allocation Failed.\n");
        exit(0);
    }
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    int sm = Smallest(arr, n);
    printf("The smallest element is %d.\n", sm);
}
