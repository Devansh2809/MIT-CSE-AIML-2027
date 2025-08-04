#include <stdio.h>
#include <stdlib.h>

#define MAX 32

typedef struct {
    int arr[MAX];
    int tos;
} Stack;

void intStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int i) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->arr[++s->top] = i;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return s->arr[s->top--];
}
void decimalToBinary(int d) {
    Stack s;
    intStack(&s);
    if (d == 0) {
        printf("0");
        return;
    }
    while (d > 0) {
        push(&s, d% 2);
        d/= 2;
    }

    while (!isEmpty(&s))
        printf("%d", pop(&s));
}
void main() {
    int dec;
    printf("Enter a decimal number: ");
    scanf("%d", &dec);
    printf("Binary representation of %d is: ", dec);
    decimalToBinary(dec);
    printf("\n");
}


