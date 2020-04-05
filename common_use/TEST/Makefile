test : test.o
	gcc -o test test.o -L. -llist
test.o : test.c
	gcc -c test.c
clean:
	rm ./*.a ./*.o