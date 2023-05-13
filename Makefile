CC = gcc
CFLAGS = -O2 -g -Wall -Wextra -Iinc
LIBRARY = liballoc.so


APP_DIR = ./app
BIN_DIR = ./bin
SRC_DIR = ./src

.phony: all
all: $(BIN_DIR)/$(LIBRARY)

.phony: check
check: $(BIN_DIR)/main
	$(BIN_DIR)/main

$(BIN_DIR)/lib_%.o: $(SRC_DIR)/%.c
	$(CC) -fpic $(CFLAGS) -o $@ -c $<

$(BIN_DIR)/$(LIBRARY): $(BIN_DIR)/lib_*.o
	$(CC) -shared -o $@ $^

$(BIN_DIR)/app_%.o: $(APP_DIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(BIN_DIR)/%: $(BIN_DIR)/app_%.o $(BIN_DIR)/$(LIBRARY)
	$(CC) -L$(BIN_DIR) -lalloc $(CFLAGS) -o $@ $<

.phony: clean
clean:
	rm -f $(BIN_DIR)/*
