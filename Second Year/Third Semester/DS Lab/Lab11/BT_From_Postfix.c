#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
    char info;
    struct node* lchild;
    struct node* rchild;
} NODE;

NODE* getnode() {
    NODE* x = (NODE*)malloc(sizeof(NODE));
    if (x == NULL) {
        printf("Running out of memory\n");
        exit(1);
    }
    return x;
}

NODE* createBinTree(char postfix[]) {
    NODE* S[20];
    int i = 0, top = -1;
    char symbol;

    while ((symbol = postfix[i++]) != '\0') {
        NODE* newnode = getnode();
        newnode->info = symbol;
        newnode->lchild = newnode->rchild = NULL;

        if (isalnum(symbol)) {
            S[++top] = newnode;
        } else {
            newnode->rchild = S[top--];
            newnode->lchild = S[top--];
            S[++top] = newnode;
        }
    }
    return S[top--];
}

void inorder(NODE* root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%c ", root->info);
        inorder(root->rchild);
    }
}

int evaluate(NODE* root) {
    if (root == NULL) return 0;
    if (isdigit(root->info))
        return root->info - '0';

    int left = evaluate(root->lchild);
    int right = evaluate(root->rchild);

    switch (root->info) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
        default:
            printf("Invalid operator\n");
            exit(1);
    }
}

int main() {
    char postfix[50];
    NODE* root = NULL;

    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    root = createBinTree(postfix);

    printf("Inorder display of the binary expression tree:\n");
    inorder(root);
    printf("\n");

    int result = evaluate(root);
    printf("The result of the expression is: %d\n", result);

    return 0;
}
