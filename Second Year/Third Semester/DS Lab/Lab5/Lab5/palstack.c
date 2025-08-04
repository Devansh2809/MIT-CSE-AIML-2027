#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    char arr[MAX];
    int tos;
} Stack;

void intStack(Stack *s) {
    s->tos = -1;
}
int isFull(Stack *s) {
    return s->tos == MAX - 1;
}
int isEmpty(Stack *s) {
    return s->tos == -1;
}
void push(Stack *s, char ch) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++s->tos] = ch;
}
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return s->arr[s->tos--];
}
int isPalindrome(char *str) {
    Stack s;
    intStack(&s);
    for (int i = 0; str[i] != '\0'; i++)
        push(&s, str[i]);
    for (int i = 0; str[i] != '\0'; i++)
        if (pop(&s) != str[i])
            return 0;
    return 1;
}

void main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    if (isPalindrome(str))
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);
}
