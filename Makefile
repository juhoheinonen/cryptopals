# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g -Wall -Werror -g -ansi -pedantic -std=c99

# Source file
SRC = set1_6.c ./lib/*.c

# Output executable
OUT = set1_6 

# Default target
all: $(OUT)

# Compile the source file
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC) -lm

# Clean target to remove compiled files
clean:
	rm -f $(OUT)
