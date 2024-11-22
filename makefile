$(info Using makefile)

CC = gcc
CFLAGS = -Wall -ansi -pedantic
TARGET = program
OBJS = main.o adjacency.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: main.c header.h
	$(CC) -c main.c $(CFLAGS)

adjacency.o: adjacency.c header.h
	$(CC) -c adjacency.c $(CFLAGS)

clean:
	rm -f $(TARGET) $(OBJS)