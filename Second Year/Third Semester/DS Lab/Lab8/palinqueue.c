#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int front;
    int rear;
} Deque;

void initDeque(Deque *dq) {
    dq->front = 0;
    dq->rear = -1;
}

int isEmpty(Deque *dq) {
    if(dq->front > dq->rear)
    return 1;
    else 
    return 0;
}
void pushFront(Deque *dq, char c) {
    if (dq->front == 0) {
        printf("Deque is full at front!\n");
        return;
    }
    dq->data[--(dq->front)] = c;
}

void pushBack(Deque *dq, char c) {
    if (dq->rear == MAX_SIZE - 1) {
        printf("Deque is full at back!\n");
        return;
    }
    dq->data[++(dq->rear)] = c;
}

char popFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return '\0';
    }
    return dq->data[(dq->front)++];
}

char popBack(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return '\0';
    }
    return dq->data[(dq->rear)--];
}

int isPalindrome(const char *str) {
    Deque dq;
    initDeque(&dq);

    for (int i = 0; str[i] != '\0'; i++) {
        pushBack(&dq, str[i]);
    }

    while (dq.front <= dq.rear) {
        char front = popFront(&dq);
        char back = popBack(&dq);
        if (front != back) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char string[MAX_SIZE];

    printf("Enter a string: ");
    scanf("%s",string);    
    int len = strlen(string);
    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1] = '\0';
    }

    if (isPalindrome(string)) {
        printf("%s is a palindrome.\n", string);
    } else {
        printf("%s is not a palindrome.\n", string);
    }

    return 0;
}

