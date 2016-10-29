#include<stdio.h>
#include<stdlib.h>

int key[20], n, m;
int *hashTable, hashIndex;
int eCount = 0;

void createHashTable() {
    int i;
    hashTable = (int*) malloc(m*sizeof(int));
    if(hashTable == NULL)
        printf("\nUnable to create the hash table");
    else
        for(i = 0; i < m; i++)
            hashTable[i] = -1;
}

void insertIntoHashTable(int key) {
    hashIndex = key % m;
    while(hashTable[hashIndex] != -1) {
        hashIndex = (hashIndex + 1) % m;
    }
    hashTable[hashIndex] = key;
    eCount++;
}

void displayHashTable() {
    int i;
    if(eCount == 0) {
        printf("\nHash Table is Empty");
        return;
    }
    printf("\nHash Table contents are:\n\n ");
    for(i = 0; i < m; i++)
        printf("\nT[%d] --> %d ", i, hashTable[i]);
}

void main() {
    int i;
    printf("\nEnter the number of employee  records (N) :   ");
    scanf("%d", &n);

    printf("\nEnter the four digit key values (K) of 'N' Employee Records:\n  ");
    for(i = 0; i < n; i++)
        scanf("%d", &key[i]);

    printf("\nEnter the two digit memory locations (m) for hash table:   ");
    scanf("%d", &m);

    createHashTable();

    printf("\nInserting key values of Employee records into hash table….. ");
    for(i=0; i<n; i++) {
        if(eCount == m) {
            printf("\nHash table is full. Cannot insert the %d record key value", i+1);
            break;
        }
        insertIntoHashTable(key[i]);
    }
    displayHashTable();
}