#include <stdio.h>
#include <string.h>
#include "lib/hex_string_to_byte_array.h"

// Function to convert a hex string to a base64 string
// Input: hex string, output: base64 string
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <hex string>\n", argv[0]);
        return 1;
    }

    char *hex_string = argv[1];
    int hex_string_length = strlen(hex_string);

    if (hex_string_length % 2 != 0)
    {
        printf("Hex string length must be even\n");
        return 1;
    }
    
    unsigned char *byte_array;

    byte_array = hex_string_to_byte_array(hex_string, hex_string_length);

    int byte_array_length = hex_string_length / 2;

    // print output as base64
    for (int i = 0; i < byte_array_length; i++)
    {
        printf("%c", byte_array[i]);
    }   

    return 0;
}