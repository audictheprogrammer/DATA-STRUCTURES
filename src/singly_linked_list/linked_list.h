#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} Node;

Node* createNode(int data);
void insertFront(Node** list, int data);
void insertLast(Node** list, int data);
void print(Node* list);
Node* search(Node*, int data);
void removeNode(Node** list, Node* node);
void removeFront(Node** list);
void removeBack(Node** list);
void deleteList(Node** list);

#endif
