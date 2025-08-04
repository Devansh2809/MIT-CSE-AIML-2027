#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node
{	int data;
	struct node* rchild;
	struct node* lchild;

} Node;
Node* getnode()
{
	Node *x=(Node*)malloc(sizeof(Node));
	if(x==NULL)
	{
		printf("allocation failed");
		return NULL;
	}
	return x;
}
Node* createBST(Node *root,int x)
{	Node *cur=root;
	Node *temp=getnode();
	temp->data=x;
	temp->lchild=temp->rchild=NULL;
	if(cur==NULL)
	{
		return temp;
	}
	Node *par=cur;
	while(cur!=NULL)
	{
		if(x<cur->data)
			{	par=cur;
				cur=cur->lchild;
			}
		else if(x>cur->data)
			{	par=cur;
				cur=cur->rchild;
			}
		else
		{
			printf("Duplicate data");
			return root;
		}
	}
	if(par->data>x)
		par->lchild=temp;
	else
		par->rchild=temp;
	return root;
}
void inorder(Node *root)
{	if(root!=NULL)
	{inorder(root->lchild);
	printf("%d ",root->data);
	inorder(root->rchild);
	}
}
void postorder(Node *root)
{	if(root!=NULL)
	{postorder(root->lchild);
	postorder(root->rchild);
	printf("%d ",root->data);
	}
}
void preorder(Node *root)
{	if(root!=NULL)
	{printf("%d ",root->data);
	preorder(root->lchild);
	preorder(root->rchild);
	}
}
Node* search(Node *root,int x)
{	if(root==NULL)
	return NULL;
	if(x==root->data)
	{	printf("element found \n");
		return root;
	}

	else if(x<root->data)
		search(root->lchild,x);
	else
		search(root->rchild,x);
}
void main()
{
	Node *root=NULL;
	int ch;
	printf("enter 1 for inserting,2 for searching,3 for inorder,4 for preorder,5 for postorder\n");

	do{
		scanf("%d",&ch);
	switch(ch){
	case 1:
		int x;
		printf("enter the element");
		scanf("%d",&x);
		root=createBST(root,x);
		break;
	case 2:
		int g;
		printf("enter the element to search");
		scanf("%d",&g);
		Node *f=search(root,g);
		if(f==NULL)
			{	printf("element not found");
			root=createBST(root,g);
			}

		break;
	case 3:
		inorder(root);
		printf("\n");
		break;
	case 4:
		preorder(root);
		printf("\n");
		break;
	case 5:
		postorder(root);
		printf("\n");
		break;
	default:
		printf("exiting");
		break;
	}
	}while(ch>0&&ch<6);
}
