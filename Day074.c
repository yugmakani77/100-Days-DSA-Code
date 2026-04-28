// Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.
#include <stdio.h>
#include <string.h>

#define MAX 1000
#define LEN 50

int main() {
    int n;
    char names[MAX][LEN];
    int freq[MAX] = {0};

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    int maxVotes = 0;
    char winner[LEN] = "";

    for (int i = 0; i < n; i++) {
        if (freq[i] == -1) continue;

        int count = 1;

        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) == 0) {
                count++;
                freq[j] = -1; // mark counted
            }
        }

        freq[i] = count;

        if (count > maxVotes) {
            maxVotes = count;
            strcpy(winner, names[i]);
        } 
        else if (count == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}