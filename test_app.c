#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "lib/hex_to_base64.h"
#include "lib/hex_to_bytes.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <hex_string_1> <hex_string_2>\n", argv[0]);
        return 1;
    }

    int len1 = strlen(argv[1]);
    int len2 = strlen(argv[2]);

    unsigned char* bytes1 = hex_to_bytes(argv[1], len1);
    unsigned char* bytes2 = hex_to_bytes(argv[2], len2);

    // todo: XOR the two byte arrays
    
}