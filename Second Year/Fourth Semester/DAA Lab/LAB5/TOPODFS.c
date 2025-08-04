#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_VERTICES 100

typedef struct node {
    struct node *next;
    int vertex;
} Node;

typedef struct Graph {
    Node* adjList[MAX_VERTICES];
    int visited[MAX_VERTICES];
    int numVertices;
} Graph;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void initGraph(Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        g->adjList[i] = NULL;
        g->visited[i] = 0;
    }
}

void addEdge(Graph* g, int start, int end) {
    if (start < 0 || start >= g->numVertices || end < 0 || end >= g->numVertices) {
        printf("Error: invalid vertex\n");
        return;
    }
    Node* newNode = createNode(end);
    newNode->next = g->adjList[start];
    g->adjList[start] = newNode;
}

int dfs(Graph* g, int v, int* stack, int* top) {
    if (g->visited[v] == 1) {
        return 0;
    }
    if (g->visited[v] == 2) {
        return 1;
    }

    g->visited[v] = 1;

    Node* temp = g->adjList[v];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!dfs(g, adjVertex, stack, top)) {
            return 0;
        }
        temp = temp->next;
    }

    g->visited[v] = 2;
    stack[(*top)++] = v;
    return 1;
}

void topoSort(Graph* g) {
    int stack[MAX_VERTICES];
    int top = 0;

    clock_t start_time = clock();

    for (int i = 0; i < g->numVertices; i++) {
        if (g->visited[i] == 0) {
            if (!dfs(g, i, stack, &top)) {
                printf("Cycle detected! Topological sort not possible.\n");
                return;
            }
        }
    }

    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Topological Sort: ");
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i] );
    }
    printf("\n");

    printf("Time required: %.6f seconds\n", time_taken);
}

int main() {
    Graph g;
    int n;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    initGraph(&g, n);

    printf("Enter the edges (enter -1 -1 to stop):\n");
    int start, end;
    while (1) {
        scanf("%d %d", &start, &end);
        if (start == -1 && end == -1) break;
        addEdge(&g, start, end);
    }

    topoSort(&g);

    return 0;
}
