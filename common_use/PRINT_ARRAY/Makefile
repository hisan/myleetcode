CC=gcc
INCLUDE = ./include
CFLAGS=-c -Wall -I$(INCLUDE)
OBJS = print_array.o

$(OBJS).o : *.c 
	$(CC) $(CFLAGS) $^
	
clean:
	rm -f *.o