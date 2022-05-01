CC = gcc
CFLAGS = -Wall

HEAD_DIR = Headers
FUNC_DIR = Functions
TEST_DIR = Tests

cible: linked_list

linked_list.o: ./$(HEAD_DIR)/linked_list.h ./$(FUNC_DIR)/linked_list.c
	$(CC) -c ./$(FUNC_DIR)/linked_list.c

linked_list: ./$(TEST_DIR)/linked_list_test.c linked_list.o
	$(CC) -o linked_list ./$(TEST_DIR)/linked_list_test.c linked_list.o

clean:
	rm -f *.o linked_list
