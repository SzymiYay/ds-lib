CC = gcc
CFLAGS = -g -Wall
OBJECTS = src/main.o src/dynamic_array.o src/stack.o src/linked_list.o src/queue.o src/binary_search_tree.o

run: $(OBJECTS)
	$(CC) $(CFLAGS) -o run $(OBJECTS)

debug:
	make
	gdb run

clean:
	rm run
	rm -rf src/run
	rm -rf src/*.o