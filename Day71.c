// Problem Statement
// Implement a hash table using quadratic probing with formula:

// h(k, i) = (h(k) + i*i) % m

// Input Format
// Same as previous.

// Output Format
// Result of SEARCH operations.

// Sample Input
// 7
// 4
// INSERT 49
// INSERT 56
// SEARCH 49
// SEARCH 15

// Sample Output
// FOUND
// NOT FOUND

// Explanation
// Collisions resolved using i² jumps.
#include <stdio.h>
#include <string.h>

#define EMPTY -1

int hash(int key, int m) {
    return key % m;
}

void insert(int table[], int m, int key) {
    int h = hash(key, m);
    int i = 0;

    while (i < m) {
        int idx = (h + i * i) % m;
        if (table[idx] == EMPTY) {
            table[idx] = key;
            return;
        }
        i++;
    }
}

int search(int table[], int m, int key) {
    int h = hash(key, m);
    int i = 0;

    while (i < m) {
        int idx = (h + i * i) % m;
        if (table[idx] == EMPTY)
            return 0;
        if (table[idx] == key)
            return 1;
        i++;
    }
    return 0;
}

int main() {
    int m, q;
    scanf("%d", &m);
    scanf("%d", &q);

    int table[m];
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    char op[10];
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0)
            insert(table, m, key);
        else if (strcmp(op, "SEARCH") == 0) {
            if (search(table, m, key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}