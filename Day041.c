/*Implement a Queue using a linked list supporting enqueue and dequeue operations*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return -1;
    }

    struct Node* temp = q->front;
    int val = temp->data;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return val;
}

int main() {
    int N;
    scanf("%d", &N);

    struct Queue* q = createQueue();

    while (N--) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'e') {  
            int x;
            scanf("%d", &x);
            enqueue(q, x);
        } 
        else if (op[0] == 'd') {  
            int res = dequeue(q);
            printf("%d\n", res);
        }
    }

    return 0;
}