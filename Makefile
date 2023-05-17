CC = gcc
CFLAGS = -O2 -g -Wall -Wextra -Iinc

.phony: all
all: ./bin/liballoc.so

.phony: check
check: ./bin/main
	./bin/main

./bin/alloc.o: ./src/alloc.c
	$(CC) -fpic $(CFLAGS) -o $@ -c $<

./bin/test.o: ./src/test.c
	$(CC) $(CFLAGS) -o $@ -c $<

./bin/liballoc.so: ./bin/alloc.o
	$(CC) -shared -o $@ $^

./bin/main.o: ./app/main.c
	$(CC) $(CFLAGS) -o $@ -c $<

./bin/main: ./bin/main.o ./bin/test.o ./bin/alloc.o
	$(CC) $(CFLAGS) -o $@ $^

.phony: clean
clean:
	rm -f ./bin/*
