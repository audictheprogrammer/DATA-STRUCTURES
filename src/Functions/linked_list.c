#include "../Headers/linked_list.h"

Element* createElement(int data){
    Element* elem = (Element*) malloc(sizeof(Element));
    if (elem == NULL){
        printf("Malloc error \n");
        return NULL;
    }
    elem->data = data;
    elem->next = NULL;
    return elem;
}

void insertFront(Element** list, int data){
    /* Time complexity: O(1) */
    Element* elem = createElement(data);
    if (elem == NULL){
        return ;
    }
    // elem becomes the first
    elem->next = *list;
    *list = elem;
}

void insertLast(Element** list, int data){
    /* Time complexity: O(n) */
    if (*list == NULL){
        *list = createElement(data);
    }
    Element* current = *list;
    while (current->next){
        current = current->next;
    }
    current->next = createElement(data);
}

void print(Element* list){
    printf("[ ");
    Element* current = list;
    while (current){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("] \n");
}

Element* search(Element* list, int data){
    /* Time complexity: O(n) */
    Element* current = list;
    while (current){
        if (current->data == data)
            return current;
        current = current->next;
    }
    return NULL;
}

void removeElement(Element** list, Element* elem){
    /* Time complexity: O(n) */
    if (elem == *list){
        *list = (*list)->next;
        printf("%d removed \n", elem->data);
        free(elem);
        return ;
    }
    Element* current = *list;
    while (current->next){
        if (current->next == elem){
            Element* copy = elem->next;
            if (elem->next == NULL){
            }
            printf("%d removed \n", elem->data);
            free(elem);
            current->next = copy;
            return ;
        }
        current = current->next;
    }
    printf("Element is not in the list \n");
}

void removeFront(Element** list){
    /* Time complexity: O(1) */
    removeElement(list, *list);
}

void removeBack(Element** list){
    /* Time complexity: O(n) */
    if ((*list)->next == NULL){
        // It is the last one
        printf("%d removed \n", (*list)->data);
        free(*list);
        *list = NULL;
        return ;
    }
    Element* current = (*list);
    while (current->next->next){
        current = current->next;
    }
    printf("%d removed \n", current->next->data);
    free(current->next);
    current->next = NULL;
}

void deleteList(Element** list){
    while ((*list)->next){
        removeFront(list);
    }
    printf("%d removed \n", (*list)->data);
    free(*list);
    *list = NULL;
}
