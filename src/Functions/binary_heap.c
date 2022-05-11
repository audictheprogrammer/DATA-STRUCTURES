#include "../Headers/binary_heap.h"

Heap* createHeap(int size){
    Heap* heap = (Heap*) malloc(sizeof(Heap));
    if (heap == NULL){
        printf("Malloc error \n");
        return NULL;
    }
    heap->array = (int*) malloc(sizeof(int) * size);
    if (heap->array == NULL){
        printf("Malloc error \n");
        free(heap);
        return NULL;
    }
    heap->size = size;
    heap->nb = 0;
    return heap;
}

void printHeap(Heap* heap){
    if (heap == NULL){
        printf("Heap is empty, cannot print \n");
    }
    int* array = heap->array;
    for (int i = 0; i < heap->nb; i++){
        printf("[%d] ", array[i]);
        if (log2(i+2) == (double) (int) log2(i+2)){
            printf("\n");
        } else if (i == heap->nb - 1){
            printf("\n");
        }
    }
}

int getParentPosition(int i){
    /* Time complexity: O(1) */
    if (i == 0)
        return -1;
    else
        return (i-1) / 2;
}

void swap(int* a, int* b){
    /* Time complexity: O(1) */
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void insertNode(Heap* heap, int value){
    /* Time complexity: O(log n) */
    if (heap == NULL || heap->nb >= heap->size){
        printf("Heap full, cannot insert \n");
        return ;
    }
    int* array = heap->array;
    // Insert the node to keep the complete tree structure
    heap->nb++;
    int childPos = heap->nb - 1;
    array[childPos] = value;
    int parentPos = getParentPosition(childPos);
    // Swap between parent and child until tree becomes a heap
    while(parentPos >= 0 && array[childPos] > array[parentPos]){
        swap(&array[childPos], &array[parentPos]);
        childPos = parentPos;
        parentPos = getParentPosition(parentPos);
    }
}

int getMaxValue(Heap* heap){
    /* Time complexity: O(1) */
    if (heap == NULL){
        printf("Heap is empty, the max value doesn't exist \n");
        return -1;
    } else{
        return heap->array[0];
    }
}

int getMinValue(Heap* heap){
    /* Time complexity: O(n) */
    // Get the index where last level of the heap starts
    int tmp = (int) log2(heap->nb);
    int index = (int) pow(2, tmp) - 1;
    // Start comparing
    int mn = heap->array[index];
    for (int i = index; i < heap->nb; i++){
        if (heap->array[i] < mn)
            mn = heap->array[i];
    }
    return mn;
}

int searchValue(Heap* heap, int value){
    /* Time complexity: O(n) */
    int nb;
    if (heap == NULL)
        nb == 0;
    else
        nb = heap->nb;
    for (int i = 0; i < nb; i++){
        if (heap->array[i] == value)
            return i;
    }
    return -1;
}

void removeNode(Heap* heap, int value){
    /* Time complexity: O(n) */
    if (heap == NULL || heap->nb == 0)
        return ;
    int valuePos = searchValue(heap, value);
    if (valuePos == -1){
        return ;
    }
    int* array = heap->array;
    // Swap valueNode and lastNode to keep the structure properties
    swap(&array[valuePos], &array[heap->nb-1]);
    // Remove the node
    array[heap->nb-1] = 0;
    heap->nb--;
    // Swap between parent and child until tree becomes a heap
    int childPos = getParentPosition(heap->nb);
    int parentPos = getParentPosition(childPos);
    while(parentPos >= valuePos){
        swap(&array[childPos], &array[parentPos]);
        childPos = parentPos;
        parentPos = getParentPosition(parentPos);
    }
}

void removeRoot(Heap* heap){
    /* Time complexity: O(log n) */
    if (heap == NULL || heap->nb == 0){
        return ;
    }
    removeNode(heap, heap->array[0]);
}
