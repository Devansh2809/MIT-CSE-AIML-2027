#include <stdio.h>
#include <stdlib.h>

#define MAX 100


void displayAdjMatrix(int matrix[MAX][MAX], int vertices) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 1; i <=vertices; i++) {
        for (int j = 1; j <=vertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


typedef struct Node {
    int vertex;
    struct Node* next;
} Node;


void displayAdjList(Node* adjList[], int vertices) {
    printf("\nAdjacency List:\n");
    for (int i = 1; i <=vertices; i++) {
        printf("%d: ", i);
        Node* temp = adjList[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}


Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int vertices, edges, src, dest;
    int adjMatrix[MAX][MAX] = {0};
    Node* adjList[MAX] = {NULL};

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 1; i <=edges; i++) {
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);

        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;

        Node* newNode = createNode(dest);
        newNode->next = adjList[src];
        adjList[src] = newNode;

        newNode = createNode(src);
        newNode->next = adjList[dest];
        adjList[dest] = newNode;
    }

    displayAdjMatrix(adjMatrix, vertices);
    displayAdjList(adjList, vertices);

    return 0;
}
