# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -g -ansi -pedantic -std=c99

# Source file
SRC1 = set1_6.c ./lib/*.c
SRC2 = encrepxor.c ./lib/*.c

# Output executable
OUT1 = set1_6
OUT2 = encrepxor

# Default target
all: $(OUT1) $(OUT2)

# Compile the first binary
$(OUT1): $(SRC1)
	$(CC) $(CFLAGS) -o $(OUT1) $(SRC1) -lm -lb64

# Compile the second binary
$(OUT2): $(SRC2)
	$(CC) $(CFLAGS) -o $(OUT2) $(SRC2) -lm -lb64
    

# Clean target to remove compiled files
clean:
	rm -f $(OUT1) $(OUT2)
    