//  Compute shortest path from source and detect negative weight cycles using Bellman-Ford.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int bellmanFord(int n, int m, int edges[][3], int src, long long dist[]) {
   
    for (int i = 0; i < n; i++) {
        dist[i] = LLONG_MAX;
    }
    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            
            if (dist[u] != LLONG_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];
        
        if (dist[u] != LLONG_MAX && dist[u] + w < dist[v]) {
            return 1; 
        }
    }

    return 0; 
}

int main() {
    int n = 5; 
    int m = 8; 
    int edges[][3] = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, 
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };
    int src = 0;
    long long dist[n];

    if (bellmanFord(n, m, edges, src, dist)) {
        printf("NEGATIVE CYCLE\n");
    } else {
        printf("Shortest distances from source %d:\n", src);
        for (int i = 0; i < n; i++) {
            if (dist[i] == LLONG_MAX) printf("Vertex %d: INF\n", i);
            else printf("Vertex %d: %lld\n", i, dist[i]);
        }
    }
    return 0;
}
