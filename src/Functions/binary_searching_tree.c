#include "../Headers/binary_searching_tree.h"

Node* createNode(int value){
    Node* node = (Node*) malloc(sizeof(Node));
    if (node == NULL){
        printf("Malloc error \n");
        return NULL;
    }
    node->value = value;
    node->leftNode = NULL;
    node->rightNode = NULL;
    node->height = 1;
    return node;
}

Node* searchValue(BST tree, int value){
    /* Time complexity: O(h) */
    if (tree == NULL){
        printf("Tree is empty, cannot searchValue \n");
        return NULL;
    }
    if (tree->value == value)
        return tree;
    else if (tree->value > value)
        return searchValue(tree->rightNode, value);
    else
        return searchValue(tree->leftNode, value);
}

void insertNodeV1(BST* tree, int value){
    /* Time complexity: O(h) */
    if (*tree == NULL){
        *tree = createNode(value);
        return;
    }
    if ((*tree)->value >= value){
        insertNodeV1(&(*tree)->leftNode, value);
        // (*tree)->height++ works aswell
        updateHeight(*tree);
    }
    else{
        insertNodeV1(&(*tree)->rightNode, value);
        updateHeight(*tree);
    }
}

void prefixPrint(BST tree){
    if (tree == NULL){
        printf("/null/ \n");
        return ;
    }
    printf("/%d/ \n", tree->value);
    prefixPrint(tree->leftNode);
    prefixPrint(tree->rightNode);
}

Node* getMaxNode(BST tree){
    /* Time complexity: O(h) */
    if (tree == NULL){
        printf("Tree is empty, no max value \n");
        return NULL;
    }
    if (tree->rightNode == NULL)
        return tree;
    else
        return getMaxNode(tree->rightNode);
}

void removeNodeV1(BST* tree, int value){
    /* Time complexity: O(h) */
    if (*tree == NULL){
        printf("Tree is empty, nothing to remove \n");
        return ;
    }
    if ((*tree)->value < value)
        removeNodeV1(&((*tree)->rightNode), value);
    else if ((*tree)->value > value)
        removeNodeV1(&((*tree)->leftNode), value);
    else{
        // We have (*tree)->value == value
        if ((*tree)->leftNode == NULL){
            Node* rightNode = (*tree)->rightNode;
            free(*tree);
            *tree = rightNode;
            return;
        }
        // Makes the max of leftNode our new Node
        Node* maxNode = getMaxNode((*tree)->leftNode);
        int maxValue = maxNode->value;
        Node* previousNode = *tree;
        Node* currentNode = (*tree)->leftNode;

        while(currentNode){
            if (currentNode->value == maxValue){
                // Set maxNode's father to NULL
                if (previousNode->leftNode == currentNode){
                    // CurrentNode is the left child
                    previousNode->leftNode = NULL;
                    currentNode->rightNode = (*tree)->rightNode;
                    if (currentNode->leftNode == NULL)
                        currentNode->leftNode = (*tree)->leftNode;
                }
                else if (previousNode->rightNode == currentNode){
                    // CurrentNode is the right child
                    previousNode->rightNode = NULL;
                    currentNode->rightNode = (*tree)->rightNode;
                    if (currentNode->leftNode == NULL)
                        currentNode->leftNode = (*tree)->leftNode;
                }
                else{
                    printf("Bug \n");
                    return ;
                }
                currentNode = NULL;
            } else if (currentNode->value < maxValue){
                previousNode = currentNode;
                currentNode = currentNode->rightNode;
            } else{
                previousNode = currentNode;
                currentNode = currentNode->leftNode;
            }
        }
        free(*tree);
        *tree = maxNode;
    }
}

void deleteTree(BST* tree){
    /* Time complexity: O(h) */
    if (*tree == NULL)
        return ;
    if ((*tree)->leftNode != NULL)
        deleteTree(&((*tree)->leftNode));
    if ((*tree)->rightNode != NULL)
        deleteTree(&((*tree)->rightNode));
    free(*tree);
    *tree = NULL;
}

int getHeight(BST tree){
    /* Time complexity: O(1) */
    if (tree == NULL){
        return 0;
    }else{
        return tree->height;
    }
}

void updateHeight(BST tree){
    /* Time complexity: O(1) */
    if (tree == NULL){
        return ;
    }
    int leftHeight, rightHeight;
    if (tree->leftNode == NULL)
        leftHeight = 0;
    else
        leftHeight = tree->leftNode->height;
    if (tree->rightNode == NULL)
        rightHeight = 0;
    else
        rightHeight = tree->rightNode->height;
    // tree->height equals to the max + 1
    if (leftHeight < rightHeight)
        tree->height = 1 + rightHeight;
    else
        tree->height = 1 + leftHeight;
}

void rotateRight(BST* tree){
    /* Rotate the binary tree:
    _root = right_;
    _left = root_;
    _left_left = left_;
    Time complexity: O(1)
    */
    if (*tree == NULL){
        printf("Tree is empty, cannot rotateRight \n");
        return ;
    }
    BST root = *tree;
    BST right = (*tree)->rightNode;
    BST left = (*tree)->leftNode;
    BST leftChild1 = left->leftNode;
    BST leftChild2 = left->rightNode;

    *tree = left;
    (*tree)->leftNode = leftChild1;
    (*tree)->rightNode = root;
    root->leftNode = leftChild2;
    root->rightNode = right;
}

void rotateLeft(BST* tree){
    /* Rotate the binary tree:
    _root = left_;
    _right = root_;
    _right_right = right_
    Time complexity: O(1)
    */
    if (*tree == NULL){
        printf("Tree is empty, cannot rotateLeft \n");
        return ;
    }
    BST root = *tree;
    BST right = (*tree)->rightNode;
    BST left = (*tree)->leftNode;
    BST rightChild1 = right->leftNode;
    BST rightChild2 = right->rightNode;

    *tree = right;
    (*tree)->rightNode = rightChild2;
    (*tree)->leftNode = root;
    root->rightNode = rightChild1;
    root->leftNode = left;
}

void insertNodeV2(BST* tree, int value){
    /* Time complexity: O(h) */
    // Insert naively
    insertNodeV1(tree, value);
    // check if we need to balance
    int leftHeight = getHeight((*tree)->leftNode);
    int rightHeight = getHeight((*tree)->rightNode);
    if (-2 < rightHeight - leftHeight && rightHeight - leftHeight < 2){
        return ;
    }
    if (rightHeight - leftHeight == 2){
        // right side is too heavy
        int rightChildHeight1 = getHeight((*tree)->rightNode->leftNode);
        int rightChildHeight2 = getHeight((*tree)->rightNode->rightNode);
        if (rightChildHeight1 > rightChildHeight2){
            rotateRight(&((*tree)->rightNode));
            updateHeight((*tree)->rightNode);
            updateHeight((*tree));
        }
        rotateLeft(tree);
        updateHeight((*tree)->leftNode);
        updateHeight((*tree));

    } else if (rightHeight - leftHeight == -2){
        // left side is too heavy
        int leftChildHeight1 = getHeight((*tree)->leftNode->leftNode);
        int leftChildHeight2 = getHeight((*tree)->leftNode->rightNode);
        if (leftChildHeight2 > leftChildHeight1){
            rotateLeft(&((*tree)->leftNode));
            updateHeight((*tree)->leftNode);
            updateHeight((*tree));
        }
        rotateRight(tree);
        updateHeight((*tree)->rightNode);
        updateHeight((*tree));

    } else{
        printf("Bug \n");
        return ;
    }
}
