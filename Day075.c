// Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.
#include <stdio.h>

#define MAX 1000
#define HASH 20001   

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int hash[HASH];
    for (int i = 0; i < HASH; i++) {
        hash[i] = -2;   
    }

    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        }

        int index = sum + 10000; 

        if (hash[index] == -2) {
            hash[index] = i; 
        } else {
            int len = i - hash[index];
            if (len > maxLen) {
                maxLen = len;
            }
        }
    }

    printf("%d\n", maxLen);

    return 0;
}