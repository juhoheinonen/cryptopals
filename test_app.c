#include <stdio.h>
#include <stdlib.h>
#include "lib/hex_to_base64.h"

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <hex_string>\n", argv[0]);
        return 1;
    }

    char* output = hex_to_base64(argv[1]);
    //printf("morjens");
    printf("%s\n", output);
    // free the memory allocated
    free(output);
}