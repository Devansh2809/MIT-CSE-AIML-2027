#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node *llink, *rlink;
} Node;

// Helper function to create a new node
Node* getnode() {
    Node *x = (Node*)malloc(sizeof(Node));
    if (x == NULL) return NULL;
    return x;
}

// Insert a new node at the rear
Node* insertrear(Node *start, int x) {
    Node *temp = getnode();
    temp->item = x;
    if (start == NULL) {
        temp->llink = temp->rlink = temp; // Circular connection
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
        printf("%d", current->item); // Print each digit
        current = current->rlink;
    } while (current != start);
    printf("\n");
}

// Add two numbers represented by circular doubly linked lists
Node* addNumbers(Node *num1, Node *num2) {
    Node *result = NULL;
    Node *n1 = num1->llink; // Start from the least significant digit (tail)
    Node *n2 = num2->llink;
    int carry = 0;

    // Traverse both numbers and add corresponding digits
    do {
        int digit1 = (n1 != NULL) ? n1->item : 0;
        int digit2 = (n2 != NULL) ? n2->item : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result = insertrear(result, sum % 10); // Insert at rear to maintain order

        n1 = (n1 != num1) ? n1->llink : NULL;
        n2 = (n2 != num2) ? n2->llink : NULL;

    } while (n1 != NULL || n2 != NULL || carry);

    return result;
}

// Main function to demonstrate the addition of two numbers
int main() {
    Node *num1 = NULL;
    Node *num2 = NULL;

    int n, digit;

    // Input for first number
    printf("Enter the number of digits for the first number: ");
    scanf("%d", &n);
    printf("Enter the digits of the first number one by one:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &digit);
        num1 = insertrear(num1, digit);  // Insert at rear to preserve order
    }

    // Input for second number
    printf("Enter the number of digits for the second number: ");
    scanf("%d", &n);
    printf("Enter the digits of the second number one by one:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &digit);
        num2 = insertrear(num2, digit);  // Insert at rear to preserve order
    }

    // Display the two numbers
    printf("First Number: ");
    display(num1);
    printf("Second Number: ");
    display(num2);

    // Add the two numbers and display the result
    Node *result = addNumbers(num1, num2);
    printf("Sum: ");
    display(result);

    return 0;
}
