//  Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int adjSize[MAX];
int indegree[MAX];

int queue[MAX];
int front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

void topoSort(int n) {
    
    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
    }

    for (int u = 0; u < n; u++) {
        for (int j = 0; j < adjSize[u]; j++) {
            int v = adj[u][j];
            indegree[v]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int count = 0;

    printf("Topological Order:\n");

    while (front < rear) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        for (int i = 0; i < adjSize[node]; i++) {
            int neighbor = adj[node][i];
            indegree[neighbor]--;

            if (indegree[neighbor] == 0) {
                enqueue(neighbor);
            }
        }
    }

    if (count != n) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }
}

int main() {
    int n, e;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    for (int i = 0; i < n; i++) {
        adjSize[i] = 0;
    }

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v;
    }

    topoSort(n);

    return 0;
}