sources = main.c list_head.c queue.c
objects = $(patsubst %.c,%.o,$(sources))
CC = gcc
OPTS = -Wall

list_head: $(objects)
	$(CC) $(OPTS) -o $@ $(objects)

clean:
	rm list_head $(objects)

