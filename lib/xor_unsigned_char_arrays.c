#include <stdio.h>
#include <stdlib.h>
#include "xor_unsigned_char_arrays.h"

// Function to convert a hex string to unsigned char array.
// The returned array contains the bytes represented by the hex string.
unsigned char *xor_unsigned_char_arrays(unsigned char *arr1, unsigned char *arr2, int len)
{
    unsigned char *bytes = (unsigned char *)malloc(len);

    for (int i = 0; i < len; i++)
    {
        bytes[i] = arr1[i] ^ arr2[i];
    }

    return bytes;
}