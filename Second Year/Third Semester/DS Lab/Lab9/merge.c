#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the singly linked list
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to create a new node
Node* getnode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
Node* insert(Node* head, int data) {
    Node* temp = getnode(data);
    if (head == NULL) {
        return temp;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
    return head;
}

// Function to display the linked list
void display(Node* head) {
    Node* current = head;
    if (current == NULL) {
        printf("Empty list\n");
        return;
    }
    while (current != NULL) {
        printf("->%d", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to merge two sorted linked lists into one sorted linked list
Node* merge(Node* headA, Node* headB) {
    // If one of the lists is empty, return the other list
    if (headA == NULL) return headB;
    if (headB == NULL) return headA;

    // Create a dummy node to help merge the lists
    Node* dummy = getnode(0);
    Node* tail = dummy;

    // Merge the lists
    while (headA != NULL && headB != NULL) {
        if (headA->data <= headB->data) {
            tail->next = headA;
            headA = headA->next;
        } else {
            tail->next = headB;
            headB = headB->next;
        }
        tail = tail->next;
    }

    // If any list has remaining elements, append them to the merged list
    if (headA != NULL) tail->next = headA;
    if (headB != NULL) tail->next = headB;

    Node* result = dummy->next;
    free(dummy);  // Free the dummy node
    return result;
}

int main() {
    int N1, N2, i, value;

    // Read number of students in Class A and Class B
    printf("Enter the number of students in Class A and Class B: ");
    scanf("%d %d", &N1, &N2);

    // Read heights of students in Class A
    Node* classA = NULL;
    printf("Enter the heights of students in Class A (in ascending order):\n");
    for (i = 0; i < N1; i++) {
        scanf("%d", &value);
        classA = insert(classA, value);
    }

    // Read heights of students in Class B
    Node* classB = NULL;
    printf("Enter the heights of students in Class B (in ascending order):\n");
    for (i = 0; i < N2; i++) {
        scanf("%d", &value);
        classB = insert(classB, value);
    }

    // Display Class A line
    printf("Class A\n");
    display(classA);

    // Display Class B line
    printf("Class B\n");
    display(classB);

    // Merge the two classes into one line
    Node* jointClass = merge(classA, classB);

    // Display the joint class line
    printf("Joint Class\n");
    display(jointClass);

    return 0;
}
