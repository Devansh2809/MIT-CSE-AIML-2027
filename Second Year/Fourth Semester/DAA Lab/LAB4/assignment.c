#include <stdio.h>
#include <stdlib.h>

int minCost = 1000000;
int n;
int optimalAssignment[10];

int calculateCost(int arr[n][n], int assignment[n], int *opc) {
    int cost = 0;
    for (int i = 0; i < n; i++) {
        cost += arr[i][assignment[i]];
    }
    return cost;
}

void permute(int arr[n][n], int assignment[n], int l, int r, int *opc) {

    if (l == r) {
        int cost = calculateCost(arr, assignment, opc);
        if (cost < minCost) {
            minCost = cost;
            for (int i = 0; i < n; i++) {
                optimalAssignment[i] = assignment[i];
            }
        }
    } else {
        for (int i = l; i <= r; i++) {
            int temp = assignment[l];
            assignment[l] = assignment[i];
            assignment[i] = temp;
            (*opc) ++;

            permute(arr, assignment, l + 1, r, opc);

            temp = assignment[l];
            assignment[l] = assignment[i];
            assignment[i] = temp;
        }
    }
}

int main() {
    printf("Input no of workers (n): ");
    scanf("%d", &n);

    int arr[n][n];
    printf("Input the job assignment matrix (costs):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int assignment[n];
    for (int i = 0; i < n; i++) {
        assignment[i] = i;
    }

    int opc = 0;
    permute(arr, assignment, 0, n - 1, &opc);

    printf("Minimum cost: %d\n", minCost);
    printf("Opcount = %d\n", opc);

    printf("Optimal Assignment:\n");
    for (int i = 0; i < n; i++) {
        printf("Worker %d is assigned to Job %d\n", i + 1, optimalAssignment[i] + 1);
    }

    return 0;
}
