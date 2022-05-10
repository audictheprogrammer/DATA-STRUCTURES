#include "../Headers/binary_heap.h"

int main(){
    const int TEST1 = 1;
    const int TEST2 = 1;

    if (TEST1){
        // Testing printHeap and insertNode
        Heap* heap = createHeap(8);
        heap->array[0] = 1;
        heap->array[1] = 2;
        heap->array[2] = 3;
        heap->array[3] = 4;
        heap->array[4] = 5;
        heap->array[5] = 6;
        heap->array[6] = 7;
        heap->array[7] = 8;
        heap->nb = 8;
        printf("Printing heap \n");
        printHeap(heap);
        printf("Printed heap \n");
    }

    if (TEST2){
        // Testing insertNode and getMaxValue
        Heap* heap = createHeap(4);
        printf("Inserts the following sequence: [1, 2, 3, 4] \n");
        insertNode(heap, 1);
        insertNode(heap, 2);
        insertNode(heap, 3);
        insertNode(heap, 4);
        printf("Current number of nodes is: %d \n", heap->nb);
        printHeap(heap);
        printf("The max value is: %d \n", getMaxValue(heap));
    }


    return 0;
}
