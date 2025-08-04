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
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to remove duplicates from a sorted linked list
Node* removeDuplicates(Node* head) {
    if (head == NULL) return NULL;  // If list is empty, return NULL

    Node* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            // Duplicate found, remove the next node
            Node* duplicate = current->next;
            current->next = current->next->next;
            free(duplicate);  // Free the memory of the duplicate node
        } else {
            // Move to the next node if no duplicate
            current = current->next;
        }
    }

    return head;
}

int main() {
    int n, value, i;
    Node* head = NULL;

    // Read number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Read the sorted elements and insert them into the list
    printf("Enter the elements in sorted order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insert(head, value);
    }

    // Display the list before removing duplicates
    printf("Original List:\n");
    display(head);

    // Remove duplicates
    head = removeDuplicates(head);

    // Display the list after removing duplicates
    printf("List after removing duplicates:\n");
    display(head);

    return 0;
}
