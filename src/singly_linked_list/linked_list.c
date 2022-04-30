#include "linked_list.h"

Node* createNode(int data){
    Node* node = (Node*) malloc(sizeof(Node));
    if (node == NULL){
        printf("Malloc error \n");
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}

void insertFront(Node** list, int data){
    /* Time complexity: O(1) */
    Node* node = createNode(data);
    if (node == NULL){
        return ;
    }
    // node becomes the first
    node->next = *list;
    *list = node;
}

void insertLast(Node** list, int data){
    /* Time complexity: O(n) */
    if (*list == NULL){
        *list = createNode(data);
    }
    Node* running = *list;
    while (running->next){
        running = running->next;
    }
    running->next = createNode(data);
}

void print(Node* list){
    printf("[ ");
    Node* running = list;
    while (running){
        printf("%d ", running->data);
        running = running->next;
    }
    printf("] \n");
}

Node* search(Node* list, int data){
    Node* running = list;
    while (running){
        if (running->data == data)
            return running;
        running = running->next;
    }
    return NULL;
}

void removeNode(Node** list, Node* node){
    /* Time complexity: O(n) */
    if (node == *list){
        *list = (*list)->next;
        printf("%d removed \n", node->data);
        free(node);
        return ;
    }
    Node* running = *list;
    while (running->next){
        if (running->next == node){
            Node* copy = node->next;
            if (node->next == NULL){
            }
            printf("%d removed \n", node->data);
            free(node);
            running->next = copy;
            return ;
        }
        running = running->next;
    }
    printf("node is not in the list \n");
}

void removeFront(Node** list){
    /* Time complexity: O(1) */
    removeNode(list, *list);
}

void removeBack(Node** list){
    /* Time complexity: O(n) */
    if ((*list)->next == NULL){
        // It is the last one
        printf("%d removed \n", (*list)->data);
        free(*list);
        *list = NULL;
        return ;
    }
    Node* running = (*list);
    while (running->next->next){
        running = running->next;
    }
    printf("%d removed \n", running->next->data);
    free(running->next);
    running->next = NULL;
}

void deleteList(Node** list){
    while ((*list)->next){
        removeFront(list);
    }
    printf("%d removed \n", (*list)->data);
    free(*list);
    *list = NULL;
}
