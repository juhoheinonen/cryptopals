#include <stdlib.h>
#include "xor_unsigned_char_array_with_unsigned_char.h"

unsigned char *xor_unsigned_char_array_with_unsigned_char(unsigned char *arr, int len, unsigned char c)
{
    unsigned char *bytes = (unsigned char *)malloc(len);

    for (int i = 0; i < len; i++)
    {
        bytes[i] = arr[i] ^ c;
    }

    return bytes;
}