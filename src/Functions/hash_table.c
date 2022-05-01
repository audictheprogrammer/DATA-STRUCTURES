#include "../Headers/hash_table.h"

Element* createElement(char* value){
    Element* elem = (Element*) malloc(sizeof(Element));
    if (elem == NULL){
        printf("Malloc error \n");
        return NULL;
    }
    elem->value = strdup(value);
    elem->key = -1;
    elem->next = NULL;
}

Element* search(hashTable* table, char* val){
    /* Time complexity: O(n) */
    int key = hash(val, table->size);
    Element* current = table->tab[key];
    while (current){
        if (strcmp(current->value, val) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}

void removeElement(hashTable* table, Element* elem){
    /* Time complexity: O(n) */
    Element* list = table->tab[elem->key];
    if (elem == list){
        list = list->next;
        printf("/%s/ removed \n", elem->value);
        free(elem->value);
        free(elem);
        return ;
    }
    Element* current = list;
    while (current->next){
        if (current->next == elem){
            Element* copy = elem->next;
            if (elem->next == NULL){
            }
            printf("/%s/ removed \n", elem->value);
            free(elem->value);
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
    if (*list == NULL){
        printf("list is empty, cannot remove element \n");
        return ;
    }
    Element* copy = (*list)->next;
    free((*list)->value);
    free(*list);
    *list = copy;
}

hashTable* createHashTable(int size){
    hashTable* table = (hashTable*) malloc(sizeof(hashTable));
    if (table == NULL){
        printf("Malloc error \n");
        return NULL;
    }
    table->tab = (Element**) malloc(sizeof(Element*) * size);
    if (table->tab == NULL){
        printf("Malloc error \n");
        free(table);
        return NULL;
    }
    for (int i = 0; i < size; i++){
        table->tab[i] = NULL;
    }
    table->size = size;
    table->nb = 0;
    return table;
}

int hash(char* value, int size){
    /* arbitrary choice. Time complexity: O(1) */
    int sum = 0;
    for (int i = 0; i < strlen(value); i++){
        sum += value[i] * (i+1);
    }
    return sum % size;
}

void insertElem(hashTable* table, char* value){
    /* Consider table is composed of linked-list, so always
    insert front. Time complexity: O(1) */
    // initialize elem
    Element* elem = createElement(value);
    if (elem == NULL){
        return ;
    }
    elem->key = hash(value, table->size);
    // elem becomes the first
    elem->next = table->tab[elem->key];
    table->tab[elem->key] = elem;
    table->nb++;
}

void printTable(hashTable* table){
    if (table == NULL){
        printf("HashTable: \n");
        return ;
    }
    printf("HashTable: \n");
    for (int i = 0; i < table->size; i++){
        Element* current = table->tab[i];
        printf("%d: ", i);
        while (current){
            printf("/%s/ ", current->value);
            current = current->next;
        }
        printf("\n");
    }
}

void deleteTable(hashTable** table){
    /* Time complexity: O(table->nb) */
    for (int i = 0; i < (*table)->size && (*table)->nb > 0; i++){
        Element* currentList = (*table)->tab[i];
        while (currentList){
            removeFront(&currentList);
            (*table)->nb--;
        }
    }
    free((*table)->tab);
    free(*table);
    *table = NULL;
}
