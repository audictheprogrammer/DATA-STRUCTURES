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
        }
    }
    printf("\n");
}
int getParentPosition(int i){
    /* Time complexity: O(1) */
    if (i == 0)
        return 0;
    else
        return (i-1) / 2;
}
void insertNode(Heap* heap, int value){
    /* Time complexity: O(h) */
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
    // Swap with his father until tree becomes a heap
    while(parentPos >= 0 && array[childPos] > array[parentPos]){
        array[childPos] = array[childPos] + array[parentPos];
        array[parentPos] = array[childPos] - array[parentPos];
        array[childPos] = array[childPos] - array[parentPos];

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
