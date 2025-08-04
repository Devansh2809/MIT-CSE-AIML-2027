#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int top;
    int capacity;
    char **array;
} Stack;

Stack* createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char **)malloc(stack->capacity * sizeof(char *));
    if (stack->array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return stack;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, char* item) {
    if (stack->top == stack->capacity - 1) {
        fprintf(stderr, "Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->array[++stack->top] = item;
}

char* pop(Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return NULL; 
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void prefixToPostfix(char* prefix, char* postfix) {
    Stack *stack = createStack(strlen(prefix));
    int length = strlen(prefix);

    for (int i = length - 1; i >= 0; i--) {
        if (isspace(prefix[i])) continue;
        
        if (isalnum(prefix[i])) {
            char *operand = (char *)malloc(2 * sizeof(char));
            if (operand == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
            operand[0] = prefix[i];
            operand[1] = '\0';
            push(stack, operand);
        }
        else if (isOperator(prefix[i])) {
            char *operand1 = pop(stack);
            char *operand2 = pop(stack);
            
            if (operand1 == NULL || operand2 == NULL) {
                fprintf(stderr, "Invalid expression\n");
                exit(EXIT_FAILURE);
            }

            char *expression = (char *)malloc(strlen(operand1) + strlen(operand2) + 2);
            if (expression == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
            sprintf(expression, "%s%s%c", operand1, operand2, prefix[i]);
            
            push(stack, expression);
            
            free(operand1);
            free(operand2);
        }
    }
    
    char *result = pop(stack);
    if (result == NULL) {
        fprintf(stderr, "Invalid expression\n");
        exit(EXIT_FAILURE);
    }
    strcpy(postfix, result);
    free(result); // Free the last popped string
    free(stack->array);
    free(stack);
}

int main() {
    char prefix[100], postfix[100];
    
    printf("Enter a prefix expression: ");
    if (fgets(prefix, sizeof(prefix), stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        return EXIT_FAILURE;
    }
    prefix[strcspn(prefix, "\n")] = 0; 
    
    prefixToPostfix(prefix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}

