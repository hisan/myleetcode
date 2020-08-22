test : test.o
	gcc -ggdb -o test test.o -L. -llist
test.o : test.c
	gcc -ggdb -c test.c
clean:
	rm ./*.a ./*.o