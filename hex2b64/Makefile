# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -g -ansi -pedantic -std=c99

# Source file
SRC1 = hex2b64.c ../lib/*.c

# Output executable
OUT1 = hex2b64 

# Default target
all: $(OUT1)

# Compile the first binary
$(OUT1): $(SRC1)
	$(CC) $(CFLAGS) -o $(OUT1) $(SRC1) -lm -lb64

# Clean target to remove compiled files
clean:
	rm -f $(OUT1)
    
