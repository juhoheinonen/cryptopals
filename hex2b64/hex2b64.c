#include <stdio.h>
#include <string.h>
#include "../lib/hex_to_base64.h"

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
    
	char *base64 = hex_to_base64(hex_string); 

    int base64_str_length = strlen(base64); 

    // print output as base64
    for (int i = 0; i < base64_str_length; i++)
    {
        printf("%c", base64[i]);
    }   

    return 0;
}
