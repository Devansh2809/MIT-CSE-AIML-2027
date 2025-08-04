#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *lchild;
    struct node *rchild;
} NODE;
typedef struct
{
  NODE* node;
  int flag;
} Stack;
NODE* getNode() {
    NODE *x = (NODE*)malloc(sizeof(NODE));
    return x;
}

NODE* createBinTree(NODE *root, int item) {
   NODE *temp;
  NODE *prev = NULL;
  NODE *cur = root;

  char direction[100];
  int i;

  temp = getNode();
  if(temp == NULL) return root;

  temp->info = item;
  temp->lchild = temp->rchild = NULL;

  if(root == NULL) return temp;

  printf("Enter the directions to insert the item: ");
  scanf("%s", direction);

  for(i=0;i<strlen(direction); i++)
  {
    prev = cur;
    if(toupper(direction[i]) == 'L') cur = cur->lchild;
    else cur = cur->rchild;


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

void preorderIterative(NODE* root) {
   NODE* cur;
  NODE* s[20];
  int top = -1;
  s[++top] = root; // push the root node
  while(top!=-1)
  {
      cur = s[top--];
      printf("%d ",cur->info);
      if(cur->rchild)
        s[++top] = cur->rchild; // push the right node
      if(cur->lchild)
        s[++top] = cur->lchild; // push the left node
  }
}

void postorderIterative(NODE* root) {
   NODE* cur;
  Stack s[20];
  int top = -1;

  if(root == NULL)
    return;

  cur = root;
  for(;;)
  {
    while(cur != NULL)
    {
      top++;
      s[top].node = cur;  /* Push to stack */
      s[top].flag = 1;
      cur = cur->lchild;  /* Traverse left */
    }
    while(top >= 0 && s[top].flag < 0)
    {
      cur = s[top].node;  /* Pop from the stack */
      top--;
      printf("%d ", cur->info);  /* Visit the node */

      if(top == -1)
        return;
    }

    /* Ascend to traverse right subtree */
    cur = s[top].node;
    cur = cur->rchild;
    s[top].flag = -1;
  }
}

void inorderIterative(NODE* root) {
     NODE* cur;
  NODE* s[20];
  int top = -1;
  cur = root;
  for(;;)
  {
    while(cur!=NULL)
    {
      s[++top]=cur;
      cur = cur->lchild;
    }
    if(top!=-1)
    {
      cur = s[top--];
      printf("%d ",cur->info);
      cur = cur->rchild;
    }
    else
    return;
  }
}

void levelOrder(NODE* root) {
     NODE *cur,*q[50];
   int rear=-1,front=0;
   cur = root;
   q[++rear] = cur;
   while(front<=rear)
   {
     cur = q[front++]; // Dequeueing of node
     if(cur!=NULL)
     {
       printf("%d ",cur->info);
       if(cur->lchild)
       q[++rear] = cur->lchild; // Enqueue
       if(cur->rchild)
       q[++rear] = cur->rchild; // Enqueue
     }
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
    printf("In-order Traversal : ");
    inorderIterative(root);
    printf("\n");

    printf("Pre-order Traversal: ");
    preorderIterative(root);
    printf("\n");

    printf("Post-order Traversal: ");
    postorderIterative(root);
    printf("\n");

    printf("Level-order Traversal: ");
    levelOrder(root);
    printf("\n");

    return 0;
}
