#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
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
    Node* newNode = createNode(end);
    newNode->next = g->adjList[start];
    g->adjList[start] = newNode;

    newNode = createNode(start);
    newNode->next = g->adjList[end];
    g->adjList[end] = newNode;
}

void dfs(Graph* g, int vertex) {
    g->visited[vertex] = 1;
    printf("Push: %d\n", vertex + 1);

    Node* adjList = g->adjList[vertex];
    while (adjList != NULL) {
        int adjVertex = adjList->vertex;
        if (!g->visited[adjVertex]) {
            dfs(g, adjVertex);
        }
        adjList = adjList->next;
    }

    printf("Pop: %d\n", vertex + 1);
}

int main() {
    Graph g;

    printf("Enter the number of vertices: ");
    int vertices;
    scanf("%d", &vertices);

    initGraph(&g, vertices);

    printf("Enter the edges (enter -1 -1 to stop):\n");
    int start, end;
    while (1) {
        scanf("%d %d", &start, &end);
        if (start == -1 && end == -1) break;
        addEdge(&g, start - 1, end - 1);
    }

    printf("\nDepth First Search (DFS) Traversal:\n");

    for (int i = 0; i < vertices; i++) {
        if (!g.visited[i]) {
            dfs(&g, i);
        }
    }


    return 0;
}
