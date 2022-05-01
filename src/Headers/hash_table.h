#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct element{
    int key;
    char* value;
    struct element* next;
} Element;

typedef struct hashTable{
    Element** tab;
    int size;
    int nb;
} hashTable;

// linked-list
Element* createElement(char* value);
Element* search(hashTable* table, char* val);
void removeElement(hashTable* table, Element* elem);
void removeFront(Element** list);

// hash table
hashTable* createHashTable(int size);
int hash(char* value, int size);
void insertElem(hashTable* table, char* value);
void printTable(hashTable* table);
void deleteTable(hashTable** table);

#endif
