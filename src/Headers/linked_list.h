#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int data;
    struct element* next;
} Element;

Element* createElement(int data);
void insertFront(Element** list, int data);
void insertLast(Element** list, int data);
void print(Element* list);
Element* search(Element* list, int data);
void removeElement(Element** list, Element* Element);
void removeFront(Element** list);
void removeBack(Element** list);
void deleteList(Element** list);

#endif
