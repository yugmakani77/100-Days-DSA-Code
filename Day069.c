// Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int node;
    int dist;
} Pair;

typedef struct {
    Pair heap[1000];
    int size;
} MinHeap;

void swap(Pair *a, Pair *b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap *h, int node, int dist) {
    int i = h->size++;
    h->heap[i].node = node;
    h->heap[i].dist = dist;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (h->heap[parent].dist <= h->heap[i].dist) break;
        swap(&h->heap[parent], &h->heap[i]);
        i = parent;
    }
}

Pair pop(MinHeap *h) {
    Pair top = h->heap[0];
    h->heap[0] = h->heap[--h->size];

    int i = 0;
    while (1) {
        int left = 2*i + 1, right = 2*i + 2, smallest = i;

        if (left < h->size && h->heap[left].dist < h->heap[smallest].dist)
            smallest = left;
        if (right < h->size && h->heap[right].dist < h->heap[smallest].dist)
            smallest = right;

        if (smallest == i) break;
        swap(&h->heap[i], &h->heap[smallest]);
        i = smallest;
    }

    return top;
}

int adj[MAX][MAX];
int weight[MAX][MAX];
int adjSize[MAX];

void dijkstra(int n, int src) {
    int dist[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    MinHeap h;
    h.size = 0;

    push(&h, src, 0);

    while (h.size > 0) {
        Pair p = pop(&h);
        int u = p.node;
        int d = p.dist;

        if (d > dist[u]) continue;

        for (int i = 0; i < adjSize[u]; i++) {
            int v = adj[u][i];
            int w = weight[u][i];

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&h, v, dist[v]);
            }
        }
    }

    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            printf("%d -> INF\n", i);
        else
            printf("%d -> %d\n", i, dist[i]);
    }
}

int main() {
    int n, e;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    for (int i = 0; i < n; i++) {
        adjSize[i] = 0;
    }

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        adj[u][adjSize[u]] = v;
        weight[u][adjSize[u]] = w;
        adjSize[u]++;
    }

    int src;
    printf("Enter source node: ");
    scanf("%d", &src);

    dijkstra(n, src);

    return 0;
}