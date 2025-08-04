#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct node
{
int item;
struct node* link;
}Node;
typedef struct
{
Node *front,*rear;
}Queue;

Node* getnode()
{
  Node *x=(Node*)malloc(sizeof(Node));
  if(x==NULL)
  {printf("Unsuccessful allocation\n");
  return NULL;
  }
  return x;
}
Node* insertrear(int x, Queue *q)
{
    Node *temp = getnode();
    if (temp == NULL) return NULL;

    temp->link = NULL;
    temp->item = x;

    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return temp;
    }
    q->rear->link = temp;
    q->rear = temp;
    return q->rear;
}

  Node* deletefront(Queue *q)
  {
  if(q->front==NULL)
  {printf("Nothing to remove\n");
  return NULL;
  }
  Node *temp=q->front;
  q->front=temp->link;
  if(q->front==NULL)
  q->rear=NULL;
  printf("Element deleted=%d\n",temp->item);
  free(temp);
  return q->front;
  }
void display(Queue *q)
{
  if(q->front==NULL||q->rear==NULL)
    printf("Empty queue\n");
  Node *temp=q->front;
  while(temp->link!=NULL)
  {
  printf("%d ",temp->item);
  temp=temp->link;
  }
  printf("%d\n",temp->item);
  temp=temp->link;
  }
  int main() {
    Queue q;
    q.front=NULL;
    q.rear=NULL;
    int choice, value;
    printf("1. Insert element at rear,2. Delete element from front,3. Display queue,4.Exit\n");
    do {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: \n");
                scanf("%d", &value);
                q.rear=insertrear(value, &q);
                break;
            case 2:
                q.front=deletefront(&q);
                break;
            case 3:
                display(&q);
                break;
            default:
                printf("Exiting program.\n");
        }
    } while (choice>0&&choice<4);
    return 0;
}
