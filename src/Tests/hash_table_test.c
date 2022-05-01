#include "../Headers/hash_table.h"


int main(){
    const int TEST1 = 1;
    if (TEST1){
        hashTable* table = createHashTable(5);
        insertElem(table, 1);
        insertElem(table, 6);
        insertElem(table, 11);
        printTable(table);
        removeFront(&(table->tab[1]));
        printTable(table);
        deleteTable(&table);
        printTable(table);
    }

    return 0;
}
