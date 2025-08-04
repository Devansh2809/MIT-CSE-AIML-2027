#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Stack structure
typedef struct {
    int top;
    int capacity;
    char *array;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char *)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Stack operations
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(Stack *stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '\0'; // Error condition if stack is empty
}

char peek(Stack *stack) {
    return stack->array[stack->top];
}

// Function to check if the given character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to return precedence of operators
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

// Function to reverse a string
void reverseString(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

// Function to change brackets
void changeBrackets(char* expression) {
    for (int i = 0; expression[i]; i++) {
        if (expression[i] == '(')
            expression[i] = ')';
        else if (expression[i] == ')')
            expression[i] = '(';
    }
}

// Function to convert infix to postfix
void infixToPostfix(char* infix, char* postfix) {
    Stack *stack = createStack(strlen(infix));
    int k = 0;

    for (int i = 0; infix[i]; i++) {
        if (isspace(infix[i])) continue; // Skip spaces
        
        // If the character is an operand
        if (isalnum(infix[i])) {
            postfix[k++] = infix[i];
        }
        // If the character is a left parenthesis
        else if (infix[i] == '(') {
            push(stack, infix[i]);
        }
        // If the character is a right parenthesis
        else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[k++] = pop(stack);
            }
            pop(stack); // Pop '('
        }
        // If the character is an operator
        else if (isOperator(infix[i])) {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(infix[i])) {
                postfix[k++] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }

    // Pop all the remaining operators in the stack
    while (!isEmpty(stack)) {
        postfix[k++] = pop(stack);
    }

    postfix[k] = '\0'; // Null terminate the postfix expression
}

// Function to convert infix to prefix
void infixToPrefix(char* infix, char* prefix) {
    // Step 1: Reverse the infix expression
    reverseString(infix);

    // Step 2: Change brackets
    changeBrackets(infix);

    // Step 3: Convert infix to postfix
    char postfix[100];
    infixToPostfix(infix, postfix);

    // Step 4: Reverse postfix to get prefix
    reverseString(postfix);
    strcpy(prefix, postfix);
}

int main() {
    char infix[100], prefix[100];
    
    // Input the infix expression
    printf("Enter an infix expression: ");
    fgets(infix, 100, stdin);
    infix[strcspn(infix, "\n")] = 0; // Remove trailing newline character
    
    // Convert infix to prefix
    infixToPrefix(infix, prefix);
    
    // Print the prefix expression
    printf("Prefix expression: %s\n", prefix);
    
    return 0;
}

