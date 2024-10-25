#include "encode_base64.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <b64/cencode.h>

char* encode_base64(const char *input) {
    base64_encodestate state;
    base64_init_encodestate(&state);
    
    size_t input_length = strlen(input);
    size_t output_length = input_length * 4 / 3;
    char *output = (char *)malloc(output_length + 1); // +1 for null terminator
    
    if (output == NULL) {
        return NULL;
    }
    
    int len = base64_encode_block(input, input_length, output, &state);
    len += base64_encode_blockend(&output[len], &state);
    output[len] = '\0'; // Null-terminate the output string
    
    return output;
}