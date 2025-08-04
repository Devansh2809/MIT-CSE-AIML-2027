#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* arr;
    int tos;
} Stack;

void intStack(Stack *s,int si) {
    s->arr=(char*)malloc(si*sizeof(char));
    s->tos = -1;
}
int isFull(Stack *s,int num) {
    return s->tos == num-1;
}
int isEmpty(Stack *s) {
    return s->tos == -1;
}
void push(Stack *s, char c,int num) {
    if (isFull(s,num)) {
        printf("Stack overflow\n");
        return; }
    s->arr[++s->tos] =c;
    printf("Pushed %c onto the stack.\n", c);
}
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n"); 
        return '\0'; }
    else
        return s->arr[s->tos--];
}
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = s->tos; i >= 0; i--)
        printf("%c ", s->arr[i]);
    printf("\n");
}

void main() {
    Stack s;
    int f;
    char c;
    int num;
    printf("enter size of array");
    scanf("%d",&num);
    intStack(&s,num);
    do {
        printf("Enter 1 for pushing, 2 for popping and 3 for display ");
        scanf(" %d", &f);
        switch (f) {
            case 1:
                if (isFull(&s,num)) {
                    printf("Stack overflow\n");
                } else {
                    printf("Enter character: ");
                    scanf(" %c", &c);
                    push(&s, c,num);
                }
                break;
            case 2:
                if (isEmpty(&s)) {
                    printf("Stack underflow!\n");
                } else {
                    c = pop(&s);
                    printf("Popped character: %c\n", c);
                }
                break;
            case 3:
                if (isEmpty(&s)) {
                    printf("Stack is empty.\n");
                } else {
                    display(&s);
                }
                break;
        }
    } while(f>=1&&f<=3);
}
