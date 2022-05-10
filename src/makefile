CC = gcc

HEAD_DIR = Headers
FUNC_DIR = Functions
TEST_DIR = Tests

cible: linked_list hash_table binary_searching_tree binary_heap

# .o files
linked_list.o: ./$(HEAD_DIR)/linked_list.h ./$(FUNC_DIR)/linked_list.c
	$(CC) -c ./$(FUNC_DIR)/linked_list.c
hash_table.o: ./$(HEAD_DIR)/hash_table.h ./$(FUNC_DIR)/hash_table.c
	$(CC) -c ./$(FUNC_DIR)/hash_table.c
binary_searching_tree.o: ./$(HEAD_DIR)/binary_searching_tree.h ./$(FUNC_DIR)/binary_searching_tree.c
	$(CC) -c ./$(FUNC_DIR)/binary_searching_tree.c
binary_heap.o: ./$(HEAD_DIR)/binary_heap.h ./$(FUNC_DIR)/binary_heap.c
	$(CC) -c ./$(FUNC_DIR)/binary_heap.c -lm


# Executables
linked_list: ./$(TEST_DIR)/linked_list_test.c linked_list.o
	$(CC) -o linked_list ./$(TEST_DIR)/linked_list_test.c linked_list.o
hash_table: ./$(TEST_DIR)/hash_table_test.c hash_table.o
	$(CC) -o hash_table ./$(TEST_DIR)/hash_table_test.c hash_table.o
binary_searching_tree: ./$(TEST_DIR)/binary_searching_tree_test.c binary_searching_tree.o
	$(CC) -o binary_searching_tree ./$(TEST_DIR)/binary_searching_tree_test.c binary_searching_tree.o
binary_heap: ./$(TEST_DIR)/binary_heap_test.c binary_heap.o
	$(CC) -o binary_heap ./$(TEST_DIR)/binary_heap_test.c binary_heap.o -lm


clean:
	rm -f *.o linked_list hash_table binary_searching_tree binary_heap
