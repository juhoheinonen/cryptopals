# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror -g -ansi -pedantic -std=c99

# Source files
SRC1 = hdist.c ../lib/*.c
SRC2 = breakrepkeyxor.c ../lib/*.c

# Output executables
OUT1 = hdist 
OUT2 = breakrepkeyxor 

# Default target
all: $(OUT1) $(OUT2)

test:
	@echo "Running tests"
	sh test.sh

# Compile the first binary
$(OUT1): $(SRC1)
	$(CC) $(CFLAGS) -o $(OUT1) $(SRC1) -lm -lb64

# Compile the second binary
$(OUT2): $(SRC2)
	$(CC) $(CFLAGS) -o $(OUT2) $(SRC2) -lm -lb64

# Clean target to remove compiled files
clean:
	rm -f $(OUT1)
	rm -f $(OUT2)
