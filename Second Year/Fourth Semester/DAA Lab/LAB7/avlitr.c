#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* rchild;
    struct node* lchild;
    int height;
    int bf;  // Balance Factor
} Node;

Node* getnode() {
    Node *x = (Node*)malloc(sizeof(Node));
    if (x == NULL) {
        printf("Allocation failed\n");
        return NULL;
    }
    x->lchild = x->rchild = NULL;
    x->height = 1;  // Height starts from 1
    x->bf = 0;
    return x;
}

int height(Node* root) {
    return (root == NULL) ? 0 : root->height;
}

int balanceFactor(Node* root) {
    return (root == NULL) ? 0 : height(root->lchild) - height(root->rchild);
}

Node* updateHeightAndBalance(Node* root) {
    if (root != NULL) {
        root->height = 1 + (height(root->lchild) > height(root->rchild) ? height(root->lchild) : height(root->rchild));
        root->bf = balanceFactor(root);
    }
    return root;
}

// Placeholder functions for rotation (implement as needed)
Node* rotateLeft(Node* root) {
    return root;
}
Node* rotateRight(Node* root) {
    return root;
}
Node* balance(Node* root) {
    root = updateHeightAndBalance(root);
    if (root->bf > 1) {  // Left heavy
        if (root->lchild->bf < 0)
            root->lchild = rotateLeft(root->lchild);  // Left-Right case
        return rotateRight(root);
    }
    if (root->bf < -1) {  // Right heavy
        if (root->rchild->bf > 0)
            root->rchild = rotateRight(root->rchild);  // Right-Left case
        return rotateLeft(root);
    }
    return root;
}

Node* createAVLBST(Node *root, int x) {
    Node *cur = root;
    Node *temp = getnode();
    temp->data = x;

    if (cur == NULL)
        return temp;

    Node *par = NULL;
    while (cur != NULL) {
        par = cur;
        if (x < cur->data)
            cur = cur->lchild;
        else if (x > cur->data)
            cur = cur->rchild;
        else {
            printf("Duplicate data\n");
            free(temp);
            return root;
        }
    }

    if (x < par->data) {
        par->lchild = temp;
    } else {
        par->rchild = temp;
    }

    root = balance(root);  // Balance the AVL tree
    return root;
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->lchild);
        printf("%d ", root->data);
        inorder(root->rchild);
    }
}

int main() {
    Node *root = NULL;
    int ch;

    printf("Enter 1 for inserting, 2 for inorder, 3 to exit\n");

    do {
        scanf("%d", &ch);
        switch (ch) {
            case 1: {
                int x;
                printf("Enter the element: ");
                scanf("%d", &x);
                root = createAVLBST(root, x);
                break;
            }
            case 2:
                inorder(root);
                printf("\n");
                break;
            default:
                printf("Exiting\n");
                break;
        }
    } while (ch > 0 && ch < 3);

    return 0;
}
