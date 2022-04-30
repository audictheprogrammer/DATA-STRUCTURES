cible: linked_list

linked_list.o: linked_list.h linked_list.c
	gcc -c linked_list.c

linked_list: linked_list_test.c linked_list.o
	gcc -o linked_list linked_list_test.c linked_list.o

clean:
	rm -f *.o linked_list
