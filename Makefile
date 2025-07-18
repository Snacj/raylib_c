CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -lraylib -lm

all:
	$(CC) $(CFLAGS) main.c -o mygame $(LDFLAGS)

clean:
	rm -rf mygame
