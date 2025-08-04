#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int pri_que[MAX];
int front, rear;

void create()
{
    front = rear = -1;
}

void insert(int data)
{
    if (rear >= MAX - 1)
    {
        printf("\nQueue overflow ");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front = rear = 0;
        pri_que[rear] = data;
    }
    else
    {
        rear++;
        pri_que[rear] = data;
            }
}

void delete_by_priority()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }

    int minIndex = front;
    for (int i = front + 1; i <= rear; i++)
    {
        if (pri_que[i] < pri_que[minIndex])
            minIndex = i;
    }
    printf("\nDeleted element: %d", pri_que[minIndex]);
    for (int i = minIndex; i < rear; i++)
    {
        pri_que[i] = pri_que[i + 1];
    }

    rear--;

    if (rear < front)
    {
        front = rear = -1;
    }
}

void display_pqueue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }
    printf("\nPriority Queue elements are: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", pri_que[i]);
    }
}

int main()
{
    int n, ch;
    printf("\n1 - Insert an element, 2 - Delete an element, 3 - Display, 4 - Exit\n");
    create();
    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter value to be inserted: ");
            scanf("%d", &n);
            insert(n);
            break;
        case 2:
            delete_by_priority();
            break;
        case 3:
            display_pqueue();
            break;
        default:
            printf("\nIncorrect choice, Enter a correct choice");
        }
    }while(ch>0&&ch<4);
    return 0;
}
