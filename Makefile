# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror

# Source file
SRC = set1_3.c lib/*.c

# Output executable
OUT = set1_3

# Default target
all: $(OUT)

# Compile the source file
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Clean target to remove compiled files
clean:
	rm -f $(OUT)
