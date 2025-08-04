#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int array[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
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
void print(Stack *s) {
    for (int i = 0; i <= s->top; i++)
        printf("%d ", s->array[i]);
    printf("\n");
}
void delKEle(int arr[], int n, int k) {
    Stack s;
    initStack(&s);
    for (int i = 0; i < n; i++) {
        while (!isEmpty(&s) && k > 0 && s.array[s.top] < arr[i]) {
            pop(&s);
            k--;
        }
        push(&s, arr[i]);
    }
    printf("Remaining elements after deletion: ");
    print(&s);
}

void main() {
    int n, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the no. of elements to be deleted: ");
    scanf("%d", &k);
    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    delKEle(arr, n, k);
}
