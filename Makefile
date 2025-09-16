CC     = gcc
CFLAGS = -Wall

all: main.o fast.o stack.o slow1.o
	$(CC) $(CFLAGS) -o ackermann main.o fast.o slow1.o stack.o
	chmod +x ackermann

main.o: main.c stack.h
	$(CC) $(CFLAGS) -c main.c

fast.o: fast.c stack.h
	$(CC) $(CFLAGS) -c fast.c

slow1.o: slow1.c
	$(CC) $(CFLAGS) -c slow1.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

clean:
	rm -f *.o ackermann
