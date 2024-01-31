CC = gcc
CFLAGS = -Wall -g

all: gameOfLife

gameOfLife: main.o grid.o generation.o
		$(CC) $(CFLAGS) -o gameOfLife main.o grid.o generation.o

main.o: src/main.c src/grid.h src/generation.h
		$(CC) $(CFLAGS) -c src/main.c

grid.o: src/grid.c src/grid.h
		$(CC) $(CFLAGS) -c src/grid.c

generation.o: src/generation.c src/generation.h src/grid.h
		$(CC) $(CFLAGS) -c src/generation.c

clean:
		rm -f *.o gameOfLife
