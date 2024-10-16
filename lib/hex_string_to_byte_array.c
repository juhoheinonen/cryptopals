#include <stdio.h>
#include <stdlib.h>
#include "hex_string_to_byte_array.h"

// Function to convert a hex string to an unsigned char array.
// The returned array contains the bytes represented by the hex string.
unsigned char *hex_string_to_byte_array(const char *hex_string, int hex_string_length)
{
    unsigned char *byte_array = (unsigned char *)malloc(hex_string_length / 2);
    if (byte_array == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < hex_string_length; i += 2)
    {
        char hex_byte[3] = {hex_string[i], hex_string[i + 1], '\0'};
        byte_array[i / 2] = strtol(hex_byte, NULL, 16);
    }

    return byte_array;
}