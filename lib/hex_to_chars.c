#include <stdio.h>
#include <stdlib.h>
#include "hex_to_chars.h"

// Function to convert a hex string to unsigned char array.
// The returned array contains the bytes represented by the hex string.
unsigned char *hex_to_chars(const char *hex_string, int len)
{
    unsigned char *bytes = (unsigned char *)malloc(len / 2);
    if (bytes == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < len; i += 2)
    {
        char byte[3] = {hex_string[i], hex_string[i + 1], '\0'};
        bytes[i / 2] = strtol(byte, NULL, 16);
    }

    return bytes;
}