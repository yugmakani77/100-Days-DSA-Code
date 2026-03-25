/*Deque (Double-Ended Queue)*/
#include <stdio.h>
#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

int empty() {
    return (front == -1);
}

int size() {
    if (empty()) return 0;
    if (rear >= front) return rear - front + 1;
    return MAX - front + rear + 1;
}

void push_front(int val) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }

    dq[front] = val;
}

void push_back(int val) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    dq[rear] = val;
}

int pop_front() {
    if (empty()) return -1;

    int val = dq[front];

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }

    return val;
}

int pop_back() {
    if (empty()) return -1;

    int val = dq[rear];

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }

    return val;
}

int get_front() {
    if (empty()) return -1;
    return dq[front];
}

int get_back() {
    if (empty()) return -1;
    return dq[rear];
}

void clear() {
    front = rear = -1;
}

void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", dq[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);
    push_front(2);

    display();   

    printf("Front: %d\n", get_front());
    printf("Back: %d\n", get_back());

    printf("Pop Front: %d\n", pop_front());
    printf("Pop Back: %d\n", pop_back());

    display();

    printf("Size: %d\n", size());

    clear();
    printf("Empty? %d\n", empty());

    return 0;
}
