# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g -Wall -Werror -g -ansi -pedantic -std=c99

# Source file
SRC = decrepxor.c lib/*.c

# Output executable
OUT = decrepxor 

# Default target
all: $(OUT)

# Compile the source file
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC) -lm

# Clean target to remove compiled files
clean:
	rm -f $(OUT)
