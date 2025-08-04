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

typedef struct Queue {
    int items[MAX_VERTICES];
    int front, rear;
} Queue;

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

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isQueueEmpty(Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1) return;
    if (q->front == -1) q->front = 0;
    q->items[++q->rear] = value;
}

int dequeue(Queue* q) {
    if (isQueueEmpty(q)) return -1;
    return q->items[q->front++];
}

void bfs(Graph* g, int startVertex) {
    Queue q;
    initQueue(&q);

    g->visited[startVertex] = 1;
    enqueue(&q, startVertex);

    printf("BFS Traversal:\n");

    while (!isQueueEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex + 1);

        Node* temp = g->adjList[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!g->visited[adjVertex]) {
                g->visited[adjVertex] = 1;
                enqueue(&q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    Graph g;
    int vertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    initGraph(&g, vertices);

    printf("Enter the edges (enter -1 -1 to stop):\n");
    int start, end;
    while (1) {
        scanf("%d %d", &start, &end);
        if (start == -1 && end == -1) break;
        addEdge(&g, start - 1, end - 1);
    }

    printf("Enter the starting vertex for BFS: ");
    int startVertex;
    scanf("%d", &startVertex);

    bfs(&g, startVertex - 1);

    return 0;
}
