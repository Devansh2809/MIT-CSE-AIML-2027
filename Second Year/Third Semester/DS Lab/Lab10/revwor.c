#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char word[50];  // Store each word as a string
    struct node *llink, *rlink;
} Node;

// Helper function to create a new node
Node* getnode() {
    Node *x = (Node*)malloc(sizeof(Node));
    if (x == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return x;
}

// Insert a word at the rear of the doubly linked list
Node* insertrear(Node *start, char *str) {
    Node *temp = getnode();
    strcpy(temp->word, str);  // Copy the word into the node

    if (start == NULL) {
        temp->llink = temp->rlink = temp;  // Circular connection
        return temp;
    }

    Node *last = start->llink;

    temp->rlink = start;
    temp->llink = last;
    last->rlink = temp;
    start->llink = temp;

    return start;
}

// Display the list in forward order
void display(Node *start) {
    if (start == NULL) {
        printf("Empty list\n");
        return;
    }

    Node *current = start;
    do {
        printf("%s ", current->word);
        current = current->rlink;
    } while (current != start);
    printf("\n");
}

// Reverse the doubly linked list
Node* reverseList(Node *start) {
    if (start == NULL) return NULL;

    Node *current = start, *temp = NULL;

    do {
        // Swap the links of each node
        temp = current->llink;
        current->llink = current->rlink;
        current->rlink = temp;

        // Move to the next node in the original sequence
        current = current->llink;  // Since links are swapped, go to llink
    } while (current != start);

    return temp->llink;  // Return the new start (previously the last node)
}

// Main function to demonstrate the reversal of a doubly linked list with words
int main() {
    Node *start = NULL;
    int n;
    char word[50];

    // Input words into the list
    printf("Enter the number of words: ");
    scanf("%d", &n);
    printf("Enter the words one by one:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", word);
        start = insertrear(start, word);
    }

    // Display the original list
    printf("Original List: ");
    display(start);

    // Reverse the list
    start = reverseList(start);

    // Display the reversed list
    printf("Reversed List: ");
    display(start);

    return 0;
}
