# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -g

# Source file
SRC = set1_4.c lib/*.c

# Output executable
OUT = set1_4

# Default target
all: $(OUT)

# Compile the source file
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Clean target to remove compiled files
clean:
	rm -f $(OUT)
