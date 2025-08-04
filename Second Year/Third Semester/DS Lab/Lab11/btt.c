#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
    int info;
    struct node *lchild;
    struct node *rchild;
} NODE;

NODE* getNode() {
    NODE *x = (NODE*)malloc(sizeof(NODE));
    return x;
}


NODE* createBinTree(NODE* root, int item)
{
  NODE *temp; /* Node to be inserted */
  NODE *prev = NULL; /* Parent Node */
  NODE *cur = root; /* Current Node */

  char direction[100]; // Increased the size to handle longer input
  int i;

  // Allocate memory for new node
  temp = getnode();
  if(temp == NULL) return root;

  temp->info = item;
  temp->lchild = temp->rchild = NULL;

  // If tree is empty, the new node is the root
  if(root == NULL) return temp;

  printf("Enter the directions to insert the item: ");
  scanf("%s", direction);

  // Find the position to insert
  for(i=0;i<strlen(direction); i++)
  {
    prev = cur; // Update parent
    if(direction[i]=='L' || direction[i]=='l') cur = cur->lchild;
    else cur = cur->rchild;

    // If we encounter a NULL before the final direction, the input is invalid
    if(cur == NULL && i != strlen(direction) - 1) {
      printf("Invalid direction provided! Cannot proceed.\n");
      return root;
    }
  }

  // Insert the node at the found position
  if(toupper(direction[i-1]) == 'L') prev->lchild = temp;
  else prev->rchild = temp;

  return root;
}


void preorder(NODE* root) {
     if(root != NULL)
    {
        printf("%d ", root->info);  // Visit root first
        preorder(root->lchild);  // Traverse left subtree
        preorder(root->rchild);  // Traverse right subtree
    }
}

void postorder(NODE* root) {
    if(root != NULL)
    {
        postorder(root->lchild);  // Traverse left subtree
        postorder(root->rchild);  // Traverse right subtree
        printf("%d ", root->info);  // Visit root last
    }
}
void inorder(NODE* root)
{
    if(root != NULL)
    {
        inorder(root->lchild);  // Traverse left subtree
        printf("%d ", root->info);  // Visit root
        inorder(root->rchild);  // Traverse right subtree
    }
}
int main() {
    NODE* root = NULL;
    int ch, item, n, i;
    printf("\nEnter the number of nodes: ");
        scanf("%d", &n);
        printf("\nEnter the Binary Tree elements: ");
        for(i = 0; i < n; i++)
        {
          printf("\nEnter the Element: ");
          scanf("%d", &item);
          root = createBinTree(root, item);
        }

    // Perform Traversals
    printf("In-order Traversal: ");
    inorder(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preorder(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}
