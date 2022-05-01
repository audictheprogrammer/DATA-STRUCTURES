#include "../Headers/hash_table.h"


int main(){
    const int TEST1 = 0;
    const int TEST2 = 1;
    if (TEST1){
        hashTable* table = createHashTable(5);
        insertElem(table, "aa");
        insertElem(table, "af");
        insertElem(table, "ak");
        printTable(table);
        printf("Removing the front of table[1] \n");
        removeFront(&(table->tab[1]));
        printTable(table);
        deleteTable(&table);
        printTable(table);
    }

    if (TEST2){
        // Testing O(n) searching and removing
        hashTable* table = createHashTable(5);
        insertElem(table, "af");
        for (int i = 0; i < 12300; i++){
            insertElem(table, "aa");
        }
        printf("Trying to remove /af/ \n");
        Element* elem = search(table, "af");
        removeElement(table, elem);
        printf("element successfully removed /af/ \n");
        // printTable(table);
        deleteTable(&table);
    }

    return 0;
}
