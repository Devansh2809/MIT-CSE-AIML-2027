#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int opcount = 0;
int inversion_count = 0;

void mergeSort(int A[], int n) {
    if (n <= 1)
        return;

    int L[n / 2], R[n - n / 2];
    int i;

    for (i = 0; i < n / 2; i++)
        L[i] = A[i];
    for (i = n / 2; i < n; i++)
        R[i - n / 2] = A[i];

    mergeSort(L, n / 2);
    mergeSort(R, n - n / 2);

    int lp = 0, rp = 0;
    i = 0;

    while (lp < n / 2 && rp < n - n / 2) {
        opcount++;
        if (L[lp] <= R[rp]) {
            A[i++] = L[lp++];
        } else {
            A[i++] = R[rp++];
            inversion_count += (n / 2 - lp);
        }
    }

    while (lp < n / 2) {
        opcount++;
        A[i++] = L[lp++];
    }

    while (rp < n - n / 2) {
        opcount++;
        A[i++] = R[rp++];
    }
}

int main() {
    int n, i;
    printf("Enter the number of integers: ");
    scanf("%d", &n);
    int A[n];
    clock_t start, end;
     double time_taken;
    printf("Enter the integers: ");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    start = clock();
    mergeSort(A, n);
     end = clock();
    printf("The sorted array is: ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken:%.8lf\n",time_taken);
    printf("Opcount = %d\n", opcount);
    printf("Inversion count = %d\n", inversion_count);

    return 0;
}
