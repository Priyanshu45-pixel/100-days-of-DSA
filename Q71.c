#include <stdio.h>
#include <string.h>
#define EMPTY -1
int table[100];  // max size
int m;
// Hash function
int hash(int key) {
    return key % m;
}
// Insert using quadratic probing
void insert(int key) {
    int index = hash(key);

    for (int i = 0; i < m; i++) {
        int newIndex = (index + i * i) % m;

        if (table[newIndex] == EMPTY) {
            table[newIndex] = key;
            return;
        }
    }

    printf("Hash table is full\n");
}

// Search using quadratic probing
void search(int key) {
    int index = hash(key);

    for (int i = 0; i < m; i++) {
        int newIndex = (index + i * i) % m;

        if (table[newIndex] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[newIndex] == EMPTY) {
            break;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int q;
    scanf("%d", &m);
    scanf("%d", &q);

    // Initialize table
    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key);
        }
    }

    return 0;
}