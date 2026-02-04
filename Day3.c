// Implement linear search to find key k in an array. Count and display the number of comparisons performed.
#include <stdio.h>

int main() {
    int n, k, comparisons = 0, found = -1;

    scanf("%d", &n);

    int a[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &k);

    for(int i = 0; i < n; i++) {
        comparisons++;          

        if(a[i] == k) {
            found = i;
            break;
        }
    }

    if(found != -1)
        printf("Found at index %d\n", found);
    else
        printf("Not Found\n");

    printf("Comparisons = %d", comparisons);

    return 0;
}
