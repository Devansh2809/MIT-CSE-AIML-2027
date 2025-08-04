#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 50

typedef struct {
    int array[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}
int isFull(Stack *s) {
    return s->top == MAX - 1;
}
int isEmpty(Stack *s) {
    return s->top == -1;
}
void push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->array[++s->top] = item;
}
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return s->array[s->top--];
}
int evaluate(char x,int op1,int op2) {
    if (x == '+')
        return (op1+op2);
    if (x == '-')
        return (op1-op2);
    if (x == '*')
        return (op1*op2);
    if (x == '/')
        return (op1/op2);
    if (x == '%')
        return (op1%op2);
    if (x == '^')
        return (pow(op1, op2));
    else
        return 0;
}

void main() {
    Stack s;
    char x, exp[MAX];
    int op1, op2, val, i = 0, j = 0;
    init(&s);
    printf("Enter a valid prefix expression: ");
    scanf("%[^\n]s", exp);
    int len = strlen(exp);
    for (i = len - 1; i >= 0; i--) {
        x = exp[i];
        if (x == ' ')
            continue;
        if(isdigit(x))
            push(&s,x-'0');
        else
        {
            op2=pop(&s);
            op1=pop(&s);
            val=evaluate(x,op2,op1);
            if (val == 0)
                printf("Invalid Expression detected! Exiting...");
            else
                push(&s,val);
        }
    }
    val = pop(&s);
    printf("Value of the given infix expression: %d\n", val);
}