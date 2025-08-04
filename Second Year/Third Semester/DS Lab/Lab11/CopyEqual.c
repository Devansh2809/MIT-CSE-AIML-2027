#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
  char info;
  struct node* lchild;
  struct node* rchild;
}NODE;

NODE* getnode()
{
  NODE* x;
  x = (NODE*)malloc(sizeof(NODE));
  if(x == NULL)
  {
    printf("Running out of memory \n");
    return NULL;
  }
  return x;
}

NODE* createBinTree(NODE* root,int item)
{
  NODE *newnode; /* Node to be inserted */
  NODE *parent;
  NODE *cur;
  int i;
  char direction[50];

  newnode = getnode();
  newnode->info = item;
  newnode->lchild = newnode->rchild = NULL;

  // If tree is empty, the new node is the root
  if(root == NULL)
  {
     printf("Creating root node \n");
     return newnode;
  }
  parent = NULL;
  cur=root;
  i=0;
  printf("Enter the directions to insert the node \n");
  scanf("%s",direction);
  while (cur && direction[i]) {//traverse down the tree
        parent = cur;
        if(direction[i]=='L' || direction[i]=='l')
            cur=cur->lchild;
        else
            cur=cur->rchild;
        i++;
    }
    if ((cur != NULL) || (direction[i]!='\0'))
    {   /*node already present at specified pos/incorrect dir string */
       printf("Insertion Not possible\n") ;
       free(newnode);
       return root;
    }
    /*Based on last character of direction string  insert as a left or right child */
    if(direction[i-1]=='L' || direction[i-1]=='l')
            parent->lchild=newnode;
    else
            parent->rchild=newnode;

   return root;
}

void inorder(NODE* root)
{
	if (root!= NULL)
	{
		inorder(root->lchild);
		printf("%d ",root->info);
		inorder(root->rchild);
	}
}

NODE* copyBinTree(NODE* root)
{
  NODE* temp;
  if(root == NULL)
  return NULL;

  temp = getnode();
  temp->info = root->info;
  temp->lchild = copyBinTree(root->lchild);
  temp->rchild = copyBinTree(root->rchild);
  return temp;
}
int binEqual(NODE *root1,NODE *root2)
{
return ((!root1 && !root2) || (root1 && root2 && (root1->info == root2->info) && binEqual(root1->lchild,root2->lchild) && binEqual(root1->rchild,root2->rchild)));
}
int main()
{
  NODE* root1=NULL;
  NODE* root2=NULL;
  NODE *cproot;
  int item,n,i,flag=0;

  printf("Enter the nodes of in binary tree 1:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
     printf("\nEnter The Element ");
     scanf("%d", &item);
     root1 = createBinTree(root1,item);
  }
    printf("copy the binary tree \n");
    cproot = copyBinTree(root1);
     printf("Display of copied binary tree \n");
    inorder(cproot);
  printf("Enter the nodes of in binary tree 2:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
     printf("\nEnter The Element ");
     scanf("%d", &item);
     root2 = createBinTree(root2,item);
  }

  flag = binEqual(root1,root2);
  if(flag == 1)
  printf("Two binary trees are equal \n");
  else
  printf("Two binary trees are not equal \n");



   return 0;
}



