CC = /usr/bin/env gcc
CFLAGS = -Wall -Wextra -Werror -pedantic-errors -std=c23 -Iinclude
LFLAGS = -lraylib

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
LIBRARY_PATH = lib

TARGET = $(BIN_DIR)/nature-of-code

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: clean $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -L $(LIBRARY_PATH) $(LFLAGS) $(OBJS) $(LFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -L $(LIBRARY_PATH) $(LFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

run: all
	./$(TARGET)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean

