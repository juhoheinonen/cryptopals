#include "read_file.h"
#include <stdio.h>
#include <stdlib.h>

char *read_file(const char *filename)
{
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error! Could not open file\n");
        return NULL;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Read the file into a buffer
    char *buffer = (char *)malloc(file_size + 1);
    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0';

    // Close the file
    fclose(file);

    return buffer;
}