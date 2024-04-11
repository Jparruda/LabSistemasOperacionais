all: hello_world

hello_world: create_process.o hello_world.o
   ./create_process.o

create_process.o: create_process.c
    clang create_process.c -o create_process.o

hello_world.o: hello_world.c
    clang hello_world.c -o hello_world.o
clean:
    rm -f create_process hello_world
