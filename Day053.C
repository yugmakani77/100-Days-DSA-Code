/*Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.*/
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct QNode {
    struct TreeNode* node;
    int hd;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* queue[1000];
    int front = 0, rear = 0;

    struct TreeNode* root = newNode(arr[0]);
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

void findRange(struct TreeNode* root, int hd, int* min, int* max) {
    if (!root) return;

    if (hd < *min) *min = hd;
    if (hd > *max) *max = hd;

    findRange(root->left, hd - 1, min, max);
    findRange(root->right, hd + 1, min, max);
}

void store(struct TreeNode* root, struct QNode queue[], int* front, int* rear, int hd) {
    queue[*rear].node = root;
    queue[*rear].hd = hd;
    (*rear)++;
}

void verticalOrder(struct TreeNode* root) {
    if (!root) return;

    struct QNode queue[1000];
    int front = 0, rear = 0;

    int storeArr[200][1000]; 
    int count[200] = {0};

    int offset = 100; 

    queue[rear++] = (struct QNode){root, 0};

    while (front < rear) {
        struct QNode curr = queue[front++];

        int hd = curr.hd + offset;
        storeArr[hd][count[hd]++] = curr.node->val;

        if (curr.node->left)
            queue[rear++] = (struct QNode){curr.node->left, curr.hd - 1};

        if (curr.node->right)
            queue[rear++] = (struct QNode){curr.node->right, curr.hd + 1};
    }

    for (int i = 0; i < 200; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", storeArr[i][j]);
            }
            printf("\n");
        }
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

    verticalOrder(root);

    return 0;
}