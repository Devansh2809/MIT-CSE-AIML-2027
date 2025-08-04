#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

int queue[MAX], front = 0, rear = 0;
int arr[MAX][MAX], indegree[MAX], n;

void enqueue(int value) {
    queue[rear++] = value;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void topologicalSort() {
    int i, j, count = 0;
    clock_t start_time = clock();

    for (i = 0; i < n; i++) {
        indegree[i] = 0;
        for (j = 0; j < n; j++) {
            if (arr[j][i] == 1) {
                indegree[i]++;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }


    printf("\nTopological Order: ");
    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        for (j = 0; j < n; j++) {
            if (arr[node][j] == 1) {
                indegree[j]--;
                if (indegree[j] == 0) {
                    enqueue(j);
                }
            }
        }
    }
     clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
     printf("Time required: %.8lf seconds\n", time_taken);

    if (count < n) {
        printf("\nCycle detected! Topological sorting not possible.\n");
    } else {
        printf("\n");
    }
}

int main() {
    int i, j;

    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);

    printf("Enter the Adjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    topologicalSort();
    return 0;
}
