subsets : subsets.o
	gcc -ggdb -o subsets subsets.o -L. -lprint_array
subsets.o : subsets.c
	gcc -ggdb -c subsets.c
clean:
	rm ./*.o
