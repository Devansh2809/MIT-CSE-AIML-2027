#include <stdio.h>
#include <time.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high,int *opc) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
             (*opc)++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high,int *opc) {
    if (low < high) {
        int pi = partition(arr, low, high,opc);
        quickSort(arr, low, pi - 1,opc);
        quickSort(arr, pi + 1, high,opc);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    printf("Enter size of array");
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    clock_t start, end;
     double time_taken;
     int opc=0;
    printf("Unsorted array: ");
    printArray(arr, n);
    start = clock();
    quickSort(arr, 0, n - 1,&opc);
    end = clock();
    printf("Opcount:%d\n",opc);
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken:%.8lf\n",time_taken);
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
