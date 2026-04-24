// Detect cycle in directed graph using DFS and recursion stack.
#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int recStack[MAX];

int dfs(int node, int n) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1) {
            
            if (!visited[i]) {
                if (dfs(i, n))
                    return 1;
            }
            else if (recStack[i]) {
                return 1;
            }
        }
    }

    recStack[node] = 0; 
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
        recStack[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, n)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}