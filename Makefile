CC = gcc
CFLAGS = -O2 -g -Wall -Wextra
LDFLAGS = -shared
TARGET = liballoc.so

SRCS = $(shell find ./src -name '*.c' -or -name '*.s')
OBJS = $(SRCS:src/%.c=build/%.o)

.phony: all

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

build/%.o: src/%.c
	$(CC) $(CFLAGS) -o $@ -c $<
