CC = gcc
CFLAGS = -Wall

all: create_processes hello_world

create_processes: create_processes.c
    $(CC) $(CFLAGS) -o $@ $^

hello_world: hello_world.c
    $(CC) $(CFLAGS) -o $@ $^

clean:
    rm -f create_processes hello_world
