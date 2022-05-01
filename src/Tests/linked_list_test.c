#include "../Headers/linked_list.h"

int main(){
    const int TEST1 = 1;
    const int TEST2 = 1;

    if (TEST1){
        Element* list = createElement(1);
        insertFront(&list, 0);
        insertLast(&list, 2);
        print(list);
        deleteList(&list);
        print(list);
    }

    if (TEST2){
        Element* list = createElement(3);
        insertLast(&list, 4);
        insertLast(&list, 5);
        print(list);
        Element* five = search(list, 5);
        Element* six = search(list, 6);
        if (five)
            printf("5 found! \n");
        else
            printf("5 not found! \n");
        if (six)
            printf("6 found! \n");
        else
            printf("6 not found! \n");
        removeElement(&list, five);
        removeBack(&list);
        removeBack(&list);
        print(list);
    }

    return 0;
}
