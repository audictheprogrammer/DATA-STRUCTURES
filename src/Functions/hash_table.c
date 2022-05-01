#include "../Headers/hash_table.h"

Element* createElement(int value){
    Element* elem = (Element*) malloc(sizeof(Element));
    if (elem == NULL){
        printf("Malloc error \n");
        return NULL;
    }
    elem->value = value;
    elem->key = -1;
    elem->next = NULL;
}

void removeFront(Element** list){
    if (*list == NULL){
        printf("list is empty \n");
    }
    Element* copy = (*list)->next;
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

int hash(int value, int size){
    /* arbitrary choice. Time complexity: O(1) */
    return value % size;
}

void insertElem(hashTable* table, int value){
    /* Consider table is composed of linked-list, so always
    insert front. Time complexity: O(1) */
    // initialize elem
    Element* elem = createElement(value);
    if (elem == NULL){
        return ;
    }
    elem->value = value;
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
            printf("/%d/ ", current->value);
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
