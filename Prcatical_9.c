/*Assume that you have a seven-slot closed hash table (the slots are numbered o through 6)
 Write program to final hash table that would result if you used the hash function h(k) - k mod 7.*/
#include <stdio.h>
#define SIZE 7

void insert(int table[], int key) {
    int index = key % SIZE;   // hash function
    int original_index = index;
    int i = 0;

    // Linear probing
    while (table[index] != -1) {
        index = (original_index + ++i) % SIZE;
        if (i == SIZE) {  // table full
            printf("Hash table is full. Cannot insert %d\n", key);
            return;
        }
    }

    table[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

int main() {
    int table[SIZE];
    int n, key;

    // Initialize table to -1 (empty)
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    printf("Enter %d keys: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(table, key);
    }

    printf("\nFinal Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (table[i] == -1)
            printf("Slot %d: Empty\n", i);
        else
            printf("Slot %d: %d\n", i, table[i]);
    }

    return 0;
}
