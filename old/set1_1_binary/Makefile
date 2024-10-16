# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g -Wall -Werror -g

# Source file
SRC = hex2b64.c lib/*.c

# Output executable
OUT = hex2b64

# Default target
all: $(OUT)

# Compile the source file
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC) -lm

# Clean target to remove compiled files
clean:
	rm -f $(OUT)
