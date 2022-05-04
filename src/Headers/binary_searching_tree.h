#ifndef BINARY_SEARCHING_TREE_H
#define BINARY_SEARCHING_TREE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    int height;
    struct node* leftNode;
    struct node* rightNode;
} Node;

typedef Node* BST;

// Basic operations on a BST
Node* createNode(int value);
Node* searchValue(BST tree, int value);
void insertNodeV1(BST* tree, int value);
void prefixPrint(BST tree);
Node* getMaxNode(BST tree);
void removeNodeV1(BST* tree, int value);
void deleteTree(BST* tree);

// Advanced operations on a BST
int getHeight(BST tree);
void updateHeight(BST tree);
void rotateRight(BST* tree);
void rotateLeft(BST* tree);
void insertNodeV2(BST* tree, int value);

#endif
