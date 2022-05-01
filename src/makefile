CC = gcc

HEAD_DIR = Headers
FUNC_DIR = Functions
TEST_DIR = Tests

cible: linked_list hash_table

linked_list.o: ./$(HEAD_DIR)/linked_list.h ./$(FUNC_DIR)/linked_list.c
	$(CC) -c ./$(FUNC_DIR)/linked_list.c
hash_table.o: ./$(HEAD_DIR)/hash_table.h ./$(FUNC_DIR)/hash_table.c
	$(CC) -c ./$(FUNC_DIR)/hash_table.c

linked_list: ./$(TEST_DIR)/linked_list_test.c linked_list.o
	$(CC) -o linked_list ./$(TEST_DIR)/linked_list_test.c linked_list.o
hash_table: ./$(TEST_DIR)/hash_table_test.c hash_table.o
	$(CC) -o hash_table ./$(TEST_DIR)/hash_table_test.c hash_table.o

clean:
	rm -f *.o linked_list hash_table
