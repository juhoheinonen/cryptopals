# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror

# Source file
SRC = test_app.c lib/*.c

# Output executable
OUT = test_app

# Default target
all: $(OUT)

# Compile the source file
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Clean target to remove compiled files
clean:
	rm -f $(OUT)
