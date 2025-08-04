#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int item;
    struct node *llink,*rlink;
}Node;
Node* getnode()
{
    Node *x=(Node*)malloc(sizeof(Node));
    if(x==NULL)
    return NULL;
    return x;
}
Node* insertfront(Node *start,int x)
{
    Node *temp=getnode();
    temp->item=x;
    if(start==NULL)
    {
        temp->llink=NULL;
        temp->rlink=NULL;
        return temp;
    }
    start->llink=temp;
    temp->rlink=start;
    return temp;
}
Node* insertrear(Node *start,int x)
{
    Node *temp=getnode();
    temp->item=x;
    if(start==NULL)
    {
        temp->llink=NULL;
        temp->rlink=NULL;
        return temp;
    }
    Node *cur=start;
    while(cur->rlink!=NULL)
        cur=cur->rlink;
    cur->rlink=temp;
    temp->llink=cur;
    temp->rlink=NULL;
    return start;
}
Node* deletefront(Node *start)
{   if(start==NULL)
     {  printf("List empty"); 
        return NULL;
     }
    Node *temp=start;
    start=start->rlink;
    printf("Delted=%d\n",temp->item);
    free(temp);
    return start;
}
Node* deleterear(Node *start)
{
    if(start==NULL)
     {  printf("List empty"); 
        return NULL;
     }
     Node *cur=start;
     Node *last=NULL;
     while(cur->rlink!=NULL)
     {  last=cur;
        cur=cur->rlink;
     }
     last->rlink=NULL;
     printf("deleted=%d\n",cur->item);
     free(cur);
     return start;
}
void display(Node* start) {
    Node* current = start;
    if (current == NULL) {
        printf("Empty list\n");
        return;
    }
    while (current != NULL) {
        printf("->%d", current->item);
        current = current->rlink;
    }
    printf("\n");
}
int main() {
    Node* start = NULL;  
    int choice, value;
    do {
        printf("\n1. Insert element at front,2.Insert at rear,3.Delete at front,4.Delete at Rear,5. Display anything else to exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert at front: \n");
                scanf("%d", &value);
                start = insertfront(start,value);
                break;
            case 2:
                printf("Enter value to insert at rear: \n");
                scanf("%d", &value);
                start = insertrear(start,value);
                break;
            case 3:
                printf("Delete at front:");
                start=deletefront(start);
                break;
            case 4:
                printf("Delete at rear:");
                start=deleterear(start);
                break;
            case 5:
                printf("List:");
                display(start);
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice>0&&choice<6);

    return 0;
}
