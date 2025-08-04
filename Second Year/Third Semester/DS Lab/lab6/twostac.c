#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int* array;
    int top1;
    int top2;
    int capacity;
} TwoStacks;


TwoStacks* createTwoStacks(int capacity) {
    TwoStacks* ts = (TwoStacks*)malloc(sizeof(TwoStacks));
    ts->capacity = capacity;
    ts->array = (int*)malloc(ts->capacity * sizeof(int));
    ts->top1 = -1; // Initialize top for Stack 1
    ts->top2 = capacity; // Initialize top for Stack 2
    return ts;
}


void push1(TwoStacks* ts, int value) {
   
    if (ts->top1 < ts->top2 - 1) {
        ts->array[++ts->top1] = value;
    } else {
        printf("Stack Overflow! Cannot push %d into Stack 1\n", value);
    }
}


void push2(TwoStacks* ts, int value) {
 
    if (ts->top1 < ts->top2 - 1) {
        ts->array[--ts->top2] = value;
    } else {
        printf("Stack Overflow! Cannot push %d into Stack 2\n", value);
    }
}


int pop1(TwoStacks* ts) {
    // Check for underflow
    if (ts->top1 >= 0) {
        return ts->array[ts->top1--];
    } else {
        printf("Stack Underflow! Stack 1 is empty\n");
        return -1;
    }
}


int pop2(TwoStacks* ts) {
    // Check for underflow
    if (ts->top2 < ts->capacity) {
        return ts->array[ts->top2++];
    } else {
        printf("Stack Underflow! Stack 2 is empty\n");
        return -1;
    }
}

// Function to display Stack 1
void displayStack1(TwoStacks* ts) {
    if (ts->top1 >= 0) {
        printf("Stack 1: ");
        for (int i = 0; i <= ts->top1; i++) {
            printf("%d ", ts->array[i]);
        }
        printf("\n");
    } else {
        printf("Stack 1 is empty\n");
    }
}

void displayStack2(TwoStacks* ts) {
    if (ts->top2 < ts->capacity) {
        printf("Stack 2: ");
        for (int i = ts->capacity - 1; i >= ts->top2; i--) {
            printf("%d ", ts->array[i]);
        }
        printf("\n");
    } else {
        printf("Stack 2 is empty\n");
    }
}

int main() {
    int capacity = 10;
    TwoStacks* ts = createTwoStacks(capacity);

    
    push1(ts, 10);
    push1(ts, 20);
    push1(ts, 30);

    push2(ts, 100);
    push2(ts, 200);
    push2(ts, 300);

   
    displayStack1(ts);
    displayStack2(ts);

   
    printf("Popped from Stack 1: %d\n", pop1(ts));
    displayStack1(ts);

    printf("Popped from Stack 2: %d\n", pop2(ts));
    displayStack2(ts);

    free(ts->array);
    free(ts);

    return 0;
}

