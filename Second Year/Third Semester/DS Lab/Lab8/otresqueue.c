#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char str[20];
} String;

typedef struct {
    String * q;
    int front, rear, size;
} Queue;

void insertFront(Queue *q, String s) {
    if (q->front == 0) {
        printf("No space to insert at front\n");
        return;
    }
    if (q->front == -1) {
        q->front = q->rear = 0;
    } else {
        q->front--;
    }
    strcpy((q->q[q->front]).str, s.str);
}

void insertRear(Queue *q, String s) {
    if (q->rear == q->size - 1) {
        printf("Queue is full (cannot insert at rear)\n");
        return;
    }
    if (q->rear == -1) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    strcpy((q->q[q->rear]).str, s.str);
}


String deleteFront(Queue *q) {
    String s = { "" };
    if (q->front == -1) {
        printf("Queue is empty (cannot delete)\n");
        return s;
    }
    strcpy(s.str, (q->q[q->front]).str);
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return s;
}

void displayQueue(Queue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%s ", q->q[i].str);
    }
    printf("\n");
}

int main() {
    int ch, n;
    String t;
    Queue q;
    q.front = -1;
    q.rear = -1;

    printf("Enter max size of queue: ");
    scanf("%d", &n);
    q.size = n;
    q.q = (String *)malloc(n * sizeof(String));

    printf("\n1. Insert at Rear, 2. Insert at Front, 3. Delete from Front, 4. Display, other to exit\n");

    do {
        printf("\nEnter choice: ");
        scanf("%d", &ch);
    switch(ch){
        case 1: {
            printf("Enter word to insert at rear: ");
            scanf("%s", t.str);
            insertRear(&q, t);
            break;
        }
        case 2: {
            printf("Enter word to insert at front: ");
            scanf("%s", t.str);
            insertFront(&q, t);
            break;
        }
        case 3: {
            printf("Word dequeued from front is: %s\n", deleteFront(&q).str);
            break;
        }
        case 4: {
            displayQueue(&q);
            break;
        }
        default:
            printf("Exit")

    } }while (ch>0&&ch<5);

    free(q.q);
    return 0;
}

