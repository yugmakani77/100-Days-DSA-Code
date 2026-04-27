// Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.
#include <stdio.h>
#include <string.h>

void findFirstRepeated(char* s) {
   
    int seen[26] = {0}; 

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        if (seen[index] > 0) {
            printf("%c\n", s[i]);
            return;
        }
        
        seen[index]++;
    }

    printf("-1\n");
}

int main() {
    char s[100001]; 
    if (scanf("%s", s) == 1) {
        findFirstRepeated(s);
    }
    return 0;
}
