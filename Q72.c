#include <stdio.h>
#include <string.h>
char firstRepeatedChar(char *s) {
    int seen[26] = {0};  // for lowercase letters
    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';
        if (seen[index] == 1) {
            return s[i];   // first repeated character
        }
        
        seen[index] = 1;
    }
    return -1;  // no repeated character
}
int main() {
    char s[1000];
    
    scanf("%s", s);
    
    char result = firstRepeatedChar(s);
    
    if (result == -1)
        printf("-1\n");
    else
        printf("%c\n", result);
    
    return 0;
}