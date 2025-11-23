#include <stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

int color[100], dist[100], parent[100];
int adj[100][100];
int queue[100], front = 0, rear = 0;
int vertices;

// -------- Queue Functions --------
void enqueue(int v) {
    queue[rear++] = v;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// -------- BFS Function --------
void BFS(int s) {

    // Step 1-4 Initialization (as per Cormen)
    for (int i = 0; i < vertices; i++) {
        color[i] = WHITE;
        dist[i] = 999999;   // ∞
        parent[i] = -1;
    }

    // Step 5-9 Start Node Configuration
    color[s] = GRAY;
    dist[s] = 0;
    parent[s] = -1;

    enqueue(s);

    // Step 10 While queue is not empty
    while (!isEmpty()) {
        int u = dequeue();

        // Step 12 For each adjacent vertex
        for (int v = 0; v < vertices; v++) {

            if (adj[u][v] == 1 && color[v] == WHITE) {
                color[v] = GRAY;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                enqueue(v);
            }
        }

        color[u] = BLACK;
    }
}

// -------- Main --------
int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    // Initialize adjacency matrix
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;  // directed graph (like Cormen)
    }

    printf("Enter BFS starting vertex: ");
    scanf("%d", &start);

    BFS(start);

    printf("\n---- BFS Output ----\n");
    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d: Distance = %d, Parent = %d\n", i, dist[i], parent[i]);
    }

    return 0;
}

