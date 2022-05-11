#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct heap{
    int* array;
    int size;
    int nb;
} Heap;

Heap* createHeap(int size);
void printHeap(Heap* heap);
int getParentPosition(int i);
void swap(int* a, int* b);
void insertNode(Heap* heap, int value);
int getMaxValue(Heap* heap);
int getMinValue(Heap* heap);
int searchValue(Heap* heap, int value);
void removeNode(Heap* heap, int value);
void removeRoot(Heap* heap);

#endif
