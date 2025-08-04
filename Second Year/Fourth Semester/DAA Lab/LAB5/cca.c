#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* createBinTree(struct Node* root, int item) {
    struct Node *newnode, *parent, *cur;
    char direction[50];

    newnode = newNode(item);
    if (root == NULL) {
        printf("Creating root node\n");
        return newnode;
    }

    parent = NULL;
    cur = root;
    int i = 0;

    printf("Enter the directions to insert the node (e.g., LLR for left-left-right): ");
    scanf("%s", direction);

    while (cur && direction[i]) {
        parent = cur;
        if (direction[i] == 'L' || direction[i] == 'l')
            cur = cur->left;
        else
            cur = cur->right;
        i++;
    }

    if (cur != NULL || direction[i] != '\0') {
        printf("Insertion not possible.\n");
        free(newnode);
        return root;
    }

    if (direction[i - 1] == 'L' || direction[i - 1] == 'l')
        parent->left = newnode;
    else
        parent->right = newnode;

    return root;
}

struct Node* findCCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data == n1 || root->data == n2) return root;

    struct Node* leftCCA = findCCA(root->left, n1, n2);
    struct Node* rightCCA = findCCA(root->right, n1, n2);

    if (leftCCA && rightCCA) return root;
    return (leftCCA != NULL) ? leftCCA : rightCCA;
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;
    int choice, item, n1, n2;

    do {
        printf("\n1. Insert node\n2. Find Closest Common Ancestor\n3. Display Inorder Traversal\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &item);
                root = createBinTree(root, item);
                break;
            case 2:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                    break;
                }
                printf("Enter first node value (n1): ");
                scanf("%d", &n1);
                printf("Enter second node value (n2): ");
                scanf("%d", &n2);
                clock_t start_time = clock();
                struct Node* cca = findCCA(root, n1, n2);
                clock_t end_time = clock();
                double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
                printf("Time required: %.8lf seconds\n", time_taken);
                if (cca != NULL)
                    printf("Closest Common Ancestor of %d and %d is: %d\n", n1, n2, cca->data);
                else
                    printf("Nodes not found in the tree.\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
