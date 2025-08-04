#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    double data[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, double value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    s->data[++(s->top)] = value;
}

double pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[(s->top)--];
}

double peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top];
}

int isOperand(char c) {
    return isdigit(c);
}

double evaluatePrefix(const char* exprsn) {
    Stack stack;
    initStack(&stack);
    int length = strlen(exprsn);

    for (int i = length - 1; i >= 0; i--) {
        if (isOperand(exprsn[i])) {
         
            push(&stack, exprsn[i] - '0');
        } else {
           
            double o1 = pop(&stack);
            double o2 = pop(&stack);

            switch (exprsn[i]) {
                case '+':
                    push(&stack, o1 + o2);
                    break;
                case '-':
                    push(&stack, o1 - o2);
                    break;
                case '*':
                    push(&stack, o1 * o2);
                    break;
                case '/':
                    if (o2 != 0) {
                        push(&stack, o1 / o2);
                    } else {
                        printf("Division by zero\n");
                        exit(EXIT_FAILURE);
                    }
                    break;
                default:
                    printf("Invalid operator %c\n", exprsn[i]);
                    exit(EXIT_FAILURE);
            }
        }
    }

    return pop(&stack);
}

int main() {
     char* exp;
     scanf("%[^\n]s",exp);
    printf("%3f\n", evaluatePrefix(exp));
    return 0;
}

