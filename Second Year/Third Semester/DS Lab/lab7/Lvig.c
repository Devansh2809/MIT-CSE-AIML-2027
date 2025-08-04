#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = value;
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

int checkQueue(int N, int K) {
    Queue q;
    initQueue(&q);


    for (int i = 1; i <= N; i++) {
        enqueue(&q, i);
    }

    int found = 0;

    while (!isEmpty(&q)) {
        int group[3] = {-1, -1, -1};

        for (int i = 0; i < 3 && !isEmpty(&q); i++) {
            group[i] = dequeue(&q);
        }

        int foundVignesh = 0, foundLata = 0;
        for (int i = 0; i < 3; i++) {
            if (group[i] == K) foundVignesh = 1;
            if (group[i] == K + 1) foundLata = 1;
        }

        if (foundVignesh && foundLata) {
            found = 1;
            break;
        }
    }

    if (found) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    int arr[T];
    for(int i=0;i<T;i++){
        int N, K;
        scanf("%d %d", &N, &K);
        arr[i]=checkQueue(N, K);
    }
    for(int i=0;i<T;i++)
    {
        if(arr[i]==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
