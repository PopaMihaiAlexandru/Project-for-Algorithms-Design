CC=gcc
CFLAGS=-c -Wall

all: toposort

toposort: main.o functions.o 
	$(CC) main.o functions.o -o toposort

main.o: main.c
	$(CC) $(CFLAGS) main.c

functions.o: functions.c
	$(CC) $(CFLAGS) functions.c


clean:
	rm *o toposort
