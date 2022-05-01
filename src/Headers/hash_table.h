#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int key;
    int value;
    struct element* next;
} Element;

typedef struct hashTable{
    Element** tab;
    int size;
    int nb;
} hashTable;

// linked-list
Element* createElement(int value);
void removeFront(Element** list);

// hash table
hashTable* createHashTable(int size);
int hash(int value, int size);
void insertElem(hashTable* table, int value);
void printTable(hashTable* table);
void deleteTable(hashTable** table);

#endif
