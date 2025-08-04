#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* createBinTree(Node* root, int item) {
    Node *newnode, *parent, *cur;
    char direction[50];

    newnode = newNode(item);
    if (root == NULL) {
        printf("Creating root node\n");
        return newnode;
    }

    parent = NULL;
    cur = root;
    int i = 0;

    printf("Enter the directions to insert the node: ");
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

int count(Node* root,int *opc) {

  static int c=0;
  if(root!=NULL)
  { (*opc)++;
    count(root->left,opc);
    c++;
    count(root->right,opc);
    }
    return c;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int opc=0;
    int choice, item, n1, n2;
    clock_t start, end;
     double time_taken;
    printf("1. Insert node 2. Find Count 3. Display Inorder Traversal 4. Exit:\n ");
    do {
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &item);
                root = createBinTree(root, item);
                break;
            case 2:
                start = clock();
                printf("Count:%d\n",count(root,&opc));
                printf("Opcount:%d\n",opc);
                end = clock();
                time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Time taken:%.8lf\n",time_taken);
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

