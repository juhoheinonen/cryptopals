 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/hex_to_chars.h"
#include "lib/xor_unsigned_char_arrays.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <hex_string_1> <hex_string_2>\n", argv[0]);
        return 1;
    }

    int len1 = strlen(argv[1]);
    int len2 = strlen(argv[2]);

    // if lengths are not equal, tell it and exit
    if (len1 != len2) {
        printf("Lengths of the two hex strings are not equal\n");
        return 1;
    }

    unsigned char* chars1 = hex_to_chars(argv[1], len1);
    unsigned char* chars2 = hex_to_chars(argv[2], len2);

    unsigned char* xorred = xor_unsigned_char_arrays(chars1, chars2, len1);

    // print the xorred data converted to hex
    for (int i = 0; i < len1 / 2; i++) {
        printf("%02x", xorred[i]);
    }
    printf("\n");

    free(chars1);
    free(chars2);

    return 0;
}