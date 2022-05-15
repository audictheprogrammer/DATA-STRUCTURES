#include "../Headers/binary_searching_tree.h"

int main(){
    const int TEST1 = 0;
    const int TEST2 = 0;
    const int TEST3 = 0;
    const int TEST4 = 0;
    const int TEST5 = 0;
    const int TEST6 = 0;
    const int TEST7 = 1;

    if (TEST1){
        // Testing insert, print and deleteTree
        BST tree = NULL;
        insertNodeV1(&tree, 1);
        insertNodeV1(&tree, 2);
        insertNodeV1(&tree, 3);
        insertNodeV1(&tree, 4);
        insertNodeV1(&tree, 5);
        insertNodeV1(&tree, 6);
        // The binary tree becomes a linked list.
        printf("\nPriting the tree \n");
        prefixPrint(tree);

        deleteTree(&tree);
    }
    if (TEST2){
        // Testing insert and print
        BST tree = NULL;
        insertNodeV1(&tree, 7);
        insertNodeV1(&tree, 3);
        insertNodeV1(&tree, 11);
        insertNodeV1(&tree, 1);
        insertNodeV1(&tree, 5);
        insertNodeV1(&tree, 9);
        insertNodeV1(&tree, 13);
        insertNodeV1(&tree, 0);
        insertNodeV1(&tree, 2);
        insertNodeV1(&tree, 4);
        insertNodeV1(&tree, 6);
        insertNodeV1(&tree, 8);
        insertNodeV1(&tree, 10);
        insertNodeV1(&tree, 12);
        insertNodeV1(&tree, 14);

        printf("\nPriting the tree \n");
        prefixPrint(tree);

        deleteTree(&tree);

    }
    if (TEST3){
        // Testing rotate and height value
        BST tree = NULL;
        insertNodeV1(&tree, 1);
        insertNodeV1(&tree, 2);
        insertNodeV1(&tree, 3);
        insertNodeV1(&tree, 4);
        insertNodeV1(&tree, 5);
        insertNodeV1(&tree, 6);

        printf("Priting the tree \n");
        prefixPrint(tree);

        printf("Height of the tree: %d \n", tree->height);
        rotateLeft(&tree);
        rotateLeft(&tree);
        rotateLeft(&tree);

        printf("\nPriting the tree \n");
        prefixPrint(tree);

        deleteTree(&tree);

    }
    if (TEST4){
        // Testing insertNodeV2
        BST tree = NULL;
        insertNodeV1(&tree, 1);
        insertNodeV1(&tree, 2);
        insertNodeV1(&tree, 3);
        insertNodeV1(&tree, 4);
        insertNodeV1(&tree, 5);
        insertNodeV1(&tree, 6);

        printf("\nPriting the tree \n");
        prefixPrint(tree);

        printf("Trying to remove 6 \n");
        removeNodeV1(&tree, 6);
        printf("\nPriting the tree \n");
        prefixPrint(tree);

        deleteTree(&tree);
    }

    if (TEST5){
        // Testing remove
        BST tree = NULL;
        insertNodeV1(&tree, 2);
        insertNodeV1(&tree, 1);
        insertNodeV1(&tree, 5);
        insertNodeV1(&tree, 4);
        insertNodeV1(&tree, 3);

        printf("\nPriting the tree \n");
        prefixPrint(tree);

        printf("Trying to remove 3 \n");
        // removeNodeV1(&tree, 2); // passed
        // removeNodeV1(&tree, 1); // passed
        // removeNodeV1(&tree, 5); // passed
        // removeNodeV1(&tree, 4); // passed
        removeNodeV1(&tree, 3); // passed

        printf("\nPriting the tree \n");
        prefixPrint(tree);

        deleteTree(&tree);
    }

    if (TEST6){
        // Testing remove
        BST tree = NULL;
        insertNodeV1(&tree, 7);
        insertNodeV1(&tree, 3);
        insertNodeV1(&tree, 11);
        insertNodeV1(&tree, 1);
        insertNodeV1(&tree, 5);
        insertNodeV1(&tree, 9);
        insertNodeV1(&tree, 13);
        insertNodeV1(&tree, 0);
        insertNodeV1(&tree, 2);
        insertNodeV1(&tree, 4);
        insertNodeV1(&tree, 6);
        insertNodeV1(&tree, 8);
        insertNodeV1(&tree, 10);
        insertNodeV1(&tree, 12);
        insertNodeV1(&tree, 14);

        printf("\nPriting the tree \n");
        prefixPrint(tree);

        printf("Trying to remove 7 \n");
        removeNodeV1(&tree, 7);
        printf("\nPriting the tree \n");
        prefixPrint(tree);

        printf("\nTrying to delete the tree \n");
        deleteTree(&tree);

    }

    if (TEST7){
        // Testing remove
        BST tree = NULL;
        insertNodeV2(&tree, 0);
        insertNodeV2(&tree, 1);
        insertNodeV2(&tree, -1);
        insertNodeV2(&tree, 2);
        insertNodeV2(&tree, -2);
        insertNodeV2(&tree, 3);
        insertNodeV2(&tree, -3);

        printf("\nPriting the tree \n");
        prefixPrint(tree);

        deleteTree(&tree);

    }

    return 0;
}
