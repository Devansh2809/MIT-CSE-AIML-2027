#include <stdio.h>

int checkPartition(int arr[], int n, int target, int currentSum, int index, int* opcount) {
    if (currentSum == target)
        return 1;
    if (index == n || currentSum > target)
        return 0;
    (*opcount)++;
    if (checkPartition(arr, n, target, currentSum + arr[index], index + 1, opcount))
        return 1;
    (*opcount)++;
    return checkPartition(arr, n, target, currentSum, index + 1, opcount);
}

int canPartition(int arr[], int n, int* opcount) {
    int totalSum = 0;
    for (int i = 0; i < n; i++)
        totalSum += arr[i];
    if (totalSum % 2 != 0)
        return 0;
    int target = totalSum / 2;
    return checkPartition(arr, n, target, 0, 0, opcount);
}

void main() {
    int n, opcount = 0;
    printf("Enter the no. of integers: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the integers: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    if (canPartition(arr, n, &opcount))
        printf("The array can be partitioned into two subsets with equal sum.\n");
    else
        printf("The array cannot be partitioned into two subsets with equal sum.\n");
    printf("OpCount: %d\n", opcount);
}
