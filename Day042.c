/*Given a queue of integers, reverse the queue using a stack.*/
#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int arr[1000];
    int top;
};

void push(struct Stack* s, int x) {
    s->arr[++s->top] = x;
}

int pop(struct Stack* s) {
    return s->arr[s->top--];
}

struct Queue {
    int arr[1000];
    int front, rear;
};

void enqueue(struct Queue* q, int x) {
    q->arr[++q->rear] = x;
}

int dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmptyQueue(struct Queue* q) {
    return q->front > q->rear;
}

int main() {
    int N;
    scanf("%d", &N);

    struct Queue q;
    q.front = 0;
    q.rear = -1;

    struct Stack s;
    s.top = -1;

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }

    while (!isEmptyQueue(&q)) {
        push(&s, dequeue(&q));
    }

    while (s.top != -1) {
        enqueue(&q, pop(&s));
    }

    while (!isEmptyQueue(&q)) {
        printf("%d ", dequeue(&q));
    }

    return 0;
}