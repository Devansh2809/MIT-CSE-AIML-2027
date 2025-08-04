#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char value; // Can store operators or operands (as chars)
    struct Node *left, *right;
} Node;

// Function to create a new tree node
Node* createNode(char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if the character is an operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to evaluate the expression tree
int evaluate(Node* root) {
    if (!root) return 0;

    // If the node is a leaf (operand), return its integer value
    if (!isOperator(root->value)) {
        return root->value - '0'; // Convert char to int
    }

    // Recursively evaluate left and right subtrees
    int leftEval = evaluate(root->left);
    int rightEval = evaluate(root->right);

    // Perform the operation
    switch (root->value) {
        case '+': return leftEval + rightEval;
        case '-': return leftEval - rightEval;
        case '*': return leftEval * rightEval;
        case '/': return leftEval / rightEval;
    }
    return 0;
}

// Function to construct an expression tree from postfix expression
Node* constructTree(char* postfix) {
    Node* stack[100]; // Simple stack for nodes
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            // Create a new node for operand and push it to the stack
            stack[++top] = createNode(postfix[i]);
        } else if (isOperator(postfix[i])) {
            // Create a new node for operator
            Node* operatorNode = createNode(postfix[i]);
            // Pop two nodes for the operator
            operatorNode->right = stack[top--];
            operatorNode->left = stack[top--];
            // Push the operator node back to the stack
            stack[++top] = operatorNode;
        }
    }
    return stack[top]; // The root of the expression tree
}

int main() {
    char postfix[] = "53241-*+"; // Example postfix expression
    Node* root = constructTree(postfix);

    printf("The result of the expression is: %d\n", evaluate(root));

    return 0;
}
