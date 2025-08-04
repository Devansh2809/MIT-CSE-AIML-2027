#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int item;
    struct node* link;
} Node;

// Get a new node
Node* getnode() {
    Node* x = (Node*)malloc(sizeof(Node));
    if (x == NULL) {
        printf("Unsuccessful allocation\n");
        return NULL;
    }
    return x;
}

// Insert at the end of the circular linked list
Node* insert(Node* last, int x) {
    Node* temp = getnode();
    temp->item = x;

    if (last == NULL) {
        temp->link = temp;  // Point to itself (first node in the circular list)
        return temp;
    }

    temp->link = last->link;  // New node points to the first node
    last->link = temp;        // Last node points to the new node
    return temp;              // New node becomes the last node
}

// Display circular linked list (with and without header node)
void display(Node* last) {
    if (last == NULL) {
        printf("Empty list\n");
        return;
    }

    Node* temp = last->link;  // Start from the first node
    do {
        printf("%d -> ", temp->item);
        temp = temp->link;
    } while (temp != last->link);  // Stop when we reach the first node again
    printf("(back to start)\n");
}

// Union of two circular linked lists
Node* unionLists(Node* last1, Node* last2) {
    if (last1 == NULL) return last2;  // If list1 is empty, return list2
    if (last2 == NULL) return last1;  // If list2 is empty, return list1

    Node* result = NULL;
    Node* temp = last1->link;  // Start from the first node of list1

    // Copy list1 to result
    do {
        result = insert(result, temp->item);
        temp = temp->link;
    } while (temp != last1->link);

    // Add elements of list2 that are not in result
    temp = last2->link;
    do {
        Node* search = last1->link;
        int found = 0;
        do {
            if (search->item == temp->item) {
                found = 1;
                break;
            }
            search = search->link;
        } while (search != last1->link);

        if (!found) {
            result = insert(result, temp->item);
        }
        temp = temp->link;
    } while (temp != last2->link);

    return result;
}

// Intersection of two circular linked lists
Node* intersectionLists(Node* last1, Node* last2) {
    if (last1 == NULL || last2 == NULL) return NULL;  // If any list is empty, no intersection

    Node* result = NULL;
    Node* temp = last1->link;

    // Check elements in list1 that are present in list2
    do {
        Node* search = last2->link;
        do {
            if (search->item == temp->item) {
                result = insert(result, temp->item);
                break;
            }
            search = search->link;
        } while (search != last2->link);

        temp = temp->link;
    } while (temp != last1->link);

    return result;
}

int main() {
    Node* last1 = NULL;  // Last node of the first circular linked list
    Node* last2 = NULL;  // Last node of the second circular linked list
    Node* result = NULL;
    int choice, value;

    do {
        printf("1. Insert element in first list\n");
        printf("2. Insert element in second list\n");
        printf("3. Display first list\n");
        printf("4. Display second list\n");
        printf("5. Union of lists\n");
        printf("6. Intersection of lists\n");
        printf("7. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert in first list: \n");
                scanf("%d", &value);
                last1 = insert(last1, value);
                break;
            case 2:
                printf("Enter value to insert in second list: \n");
                scanf("%d", &value);
                last2 = insert(last2, value);
                break;
            case 3:
                printf("First list: ");
                display(last1);
                break;
            case 4:
                printf("Second list: ");
                display(last2);
                break;
            case 5:
                result = unionLists(last1, last2);
                printf("Union of lists: ");
                display(result);
                break;
            case 6:
                result = intersectionLists(last1, last2);
                printf("Intersection of lists: ");
                display(result);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 7);

    return 0;
}
