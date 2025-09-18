CC     = gcc
CFLAGS = -Wall

all: main.o fast.o stack.o slow1.o
	$(CC) $(CFLAGS) -o ackermann main.o fast.o slow1.o stack.o
	chmod +x ackermann
	rm *.o

main.o: src/main.c include/stack.h
	$(CC) $(CFLAGS) -c src/main.c

fast.o: src/fast.c include/stack.h
	$(CC) $(CFLAGS) -c src/fast.c

slow1.o: src/slow1.c
	$(CC) $(CFLAGS) -c src/slow1.c

stack.o: src/stack.c include/stack.h
	$(CC) $(CFLAGS) -c src/stack.c

clean:
	rm -f *.o ackermann
