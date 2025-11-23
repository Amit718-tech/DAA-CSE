#include <stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

int adj[100][100];
int color[100], parent[100], discovery[100], finish[100];
int timeDFS = 0;
int vertices;

// -------- DFS-VISIT Procedure (Matches CLRS) --------
void DFSVisit(int u) {
    timeDFS++;
    discovery[u] = timeDFS;
    color[u] = GRAY;

    for (int v = 0; v < vertices; v++) {
        if (adj[u][v] == 1 && color[v] == WHITE) {
            parent[v] = u;
            DFSVisit(v);
        }
    }

    color[u] = BLACK;
    timeDFS++;
    finish[u] = timeDFS;
}

// -------- DFS Function --------
void DFS() {
    for (int i = 0; i < vertices; i++) {
        color[i] = WHITE;
        parent[i] = -1;
    }

    timeDFS = 0;

    for (int u = 0; u < vertices; u++) {
        if (color[u] == WHITE) {
            DFSVisit(u);
        }
    }
}

// -------- Main --------
int main() {
    int edges, u, v;

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
        adj[u][v] = 1;    // directed graph (as in CLRS)
    }

    DFS();

    printf("\n---- DFS Output ----\n");
    for (int i = 0; i < vertices; i++) {
        printf("Vertex %d: Discovery time = %d, Finish time = %d, Parent = %d\n",
               i, discovery[i], finish[i], parent[i]);
    }

    return 0;
}
