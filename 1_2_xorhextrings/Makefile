# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -g -ansi -pedantic -std=c99

# Source file
SRC1 = xorhexstrings.c ../lib/*.c

# Output executable
OUT1 = xorhexstrings 

# Default target
all: $(OUT1)

test:
	@echo "Running tests"
	sh test.sh

# Compile the first binary
$(OUT1): $(SRC1)
	$(CC) $(CFLAGS) -o $(OUT1) $(SRC1) -lm -lb64

# Clean target to remove compiled files
clean:
	rm -f $(OUT1)
    
