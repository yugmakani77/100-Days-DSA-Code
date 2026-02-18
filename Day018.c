/*Given an array of integers, rotate the array to the right by k positions.*/
#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    k = k % n;

    int temp[n];

    for(int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    for(int i = k; i < n; i++) {
        temp[i] = arr[i - k];
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}
