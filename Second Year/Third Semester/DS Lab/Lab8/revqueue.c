#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *q;
    int front, rear;
} Queue;

void enqueue(Queue *q, int x) {
    if (q->rear == -1)
        q->front = 0;
    q->q[++(q->rear)] = x;
}

int empty(Queue *q) {
    if ((q->front == -1) || (q->front > q->rear))
        return 1;
    return 0;
}

int dequeue(Queue *q) {
    int x = q->q[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;  // Reset queue when last element is dequeued
    } else {
        q->front++;
    }
    return x;
}

void reverseQueue(Queue *q) {
    if (empty(q)) {
        return;  // Base case: if the queue is empty, stop
    }

    // Step 1: Dequeue an element
    int x = dequeue(q);

    // Step 2: Recursively reverse the remaining queue
    reverseQueue(q);

    // Step 3: Enqueue the dequeued element (it will go to the rear, reversing order)
    enqueue(q, x);
}

int main() {
    int n, t;
    printf("Enter size of queue: ");
    scanf("%d", &n);

    Queue q;
    q.rear = -1;
    q.front = -1;
    q.q = (int *)malloc(n * sizeof(int));

    // Insert elements into the queue
    for (int i = 0; i < n; i++) {
        printf("Enter number to insert: ");
        scanf("%d", &t);
        enqueue(&q, t);
    }

    // Reverse the queue using recursive function
    reverseQueue(&q);

    // Display reversed queue
    printf("Reversed queue is: ");
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.q[i]);
    }
    printf("\n");

    free(q.q);
    return 0;
}
