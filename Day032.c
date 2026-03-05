/*Implement push and pop operations on a stack and verify stack operations.*/
#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        return;   
    }
    stack[++top] = value;
}

void pop() {
    if (top == -1) {
        return;   
    }
    top--;
}

void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i != 0)
            printf(" ");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        push(value);
    }

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        pop();
    }

    display();

    return 0;
}