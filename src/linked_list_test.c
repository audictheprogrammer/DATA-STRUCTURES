#include "linked_list.h"

int main(){
    const int TEST1 = 1;
    const int TEST2 = 1;

    if (TEST1){
        Node* list = createNode(1);
        insertFront(&list, 0);
        insertLast(&list, 2);
        print(list);
        deleteList(&list);
        print(list);
    }

    if (TEST2){
        Node* list = createNode(3);
        insertLast(&list, 4);
        insertLast(&list, 5);
        print(list);
        Node* five = search(list, 5);
        Node* six = search(list, 6);
        if (five)
            printf("5 found! \n");
        else
            printf("5 not found! \n");
        if (six)
            printf("6 found! \n");
        else
            printf("6 not found! \n");
        removeNode(&list, five);
        removeBack(&list);
        removeBack(&list);
        print(list);
    }

    return 0;
}
