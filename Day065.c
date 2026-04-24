// Using DFS and parent tracking, detect if undirected graph has a cycle.
#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

int dfs(int node, int parent, int n) {
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1) {
            
            if (!visited[i]) {
                if (dfs(i, node, n))
                    return 1;
            }
            else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, n)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}