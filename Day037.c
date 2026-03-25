/*Implement a Priority Queue using an array. An element with smaller value has higher priority.*/
#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = -1;

void insert(int value) {
    if (size == MAX - 1) return;

    size++;
    pq[size] = value;

    for (int i = size; i > 0; i--) {
        if (pq[i] < pq[i - 1]) {
            int temp = pq[i];
            pq[i] = pq[i - 1];
            pq[i - 1] = temp;
        }
    }
}

int deleteMin() {
    if (size == -1) return -1;

    int val = pq[0];

    for (int i = 0; i < size; i++) {
        pq[i] = pq[i + 1];
    }
    size--;

    return val;
}

int peek() {
    if (size == -1) return -1;
    return pq[0];
}

int main() {
    int N;
    scanf("%d", &N);

    char op[10];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        }
        else if (strcmp(op, "delete") == 0) {
            printf("%d\n", deleteMin());
        }
        else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}
