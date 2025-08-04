#include <stdio.h>
#include <stdlib.h>

// Structure to represent a polynomial term
typedef struct node {
    int coeff;
    int exp;
    struct node* link;
} Node;

// Helper function to create a new node
Node* getnode() {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (!temp) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    return temp;
}

// Insert a term in sorted order (based on exponent)
Node* insert(Node* head, int coeff, int exp) {
    Node* temp = getnode();
    temp->coeff = coeff;
    temp->exp = exp;
    temp->link = temp;  // Self loop initially

    if (head == NULL) return temp;

    Node* cur = head;
    while (cur->link != head) cur = cur->link;

    cur->link = temp;
    temp->link = head;
    return head;
}

// Display the polynomial
void display(Node* head) {
    if (head == NULL) {
        printf("Polynomial is empty\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->link != head) printf(" + ");
        temp = temp->link;
    } while (temp != head);
    printf("\n");
}

// Subtract two polynomials
Node* subtract(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node *p1 = poly1, *p2 = poly2;
    do {
        int coeff, exp;
        if (p1->exp == p2->exp) {
            coeff = p1->coeff - p2->coeff;
            exp = p1->exp;
            p1 = p1->link;
            p2 = p2->link;
        } else if (p1->exp > p2->exp) {
            coeff = p1->coeff;
            exp = p1->exp;
            p1 = p1->link;
        } else {
            coeff = -p2->coeff;
            exp = p2->exp;
            p2 = p2->link;
        }
        if (coeff != 0) result = insert(result, coeff, exp);
    } while (p1 != poly1 || p2 != poly2);
    return result;
}

// Multiply two polynomials
Node* multiply(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* p1 = poly1;
    do {
        Node* p2 = poly2;
        do {
            int coeff = p1->coeff * p2->coeff;
            int exp = p1->exp + p2->exp;
            result = insert(result, coeff, exp);
            p2 = p2->link;
        } while (p2 != poly2);
        p1 = p1->link;
    } while (p1 != poly1);
    return result;
}

// Main function with menu-driven approach
int main() {
    Node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int choice, coeff, exp, terms;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Input Polynomial 1\n");
        printf("2. Input Polynomial 2\n");
        printf("3. Subtract Polynomials\n");
        printf("4. Multiply Polynomials\n");
        printf("5. Display Polynomial 1\n");
        printf("6. Display Polynomial 2\n");
        printf("7. Display Result\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of terms in Polynomial 1: ");
                scanf("%d", &terms);
                for (int i = 0; i < terms; i++) {
                    printf("Enter coefficient and exponent: ");
                    scanf("%d%d", &coeff, &exp);
                    poly1 = insert(poly1, coeff, exp);
                }
                break;
            case 2:
                printf("Enter the number of terms in Polynomial 2: ");
                scanf("%d", &terms);
                for (int i = 0; i < terms; i++) {
                    printf("Enter coefficient and exponent: ");
                    scanf("%d%d", &coeff, &exp);
                    poly2 = insert(poly2, coeff, exp);
                }
                break;
            case 3:
                result = subtract(poly1, poly2);
                printf("Subtraction Result: ");
                display(result);
                break;
            case 4:
                result = multiply(poly1, poly2);
                printf("Multiplication Result: ");
                display(result);
                break;
            case 5:
                printf("Polynomial 1: ");
                display(poly1);
                break;
            case 6:
                printf("Polynomial 2: ");
                display(poly2);
                break;
            case 7:
                printf("Result: ");
                display(result);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
