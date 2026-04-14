/*Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.*/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* queue[1000];

// Create node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = newNode(arr[0]);
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n && front < rear) {
        struct TreeNode* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

void reverse(int arr[], int size) {
    int i = 0, j = size - 1;
    while (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

void zigzagTraversal(struct TreeNode* root) {
    if (!root) return;

    struct TreeNode* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int level = 0;

    while (front < rear) {
        int size = rear - front;
        int arr[1000];

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            arr[i] = node->val;

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }

        if (level % 2 == 1) {
            reverse(arr, size);
        }

        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }

        level++;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}