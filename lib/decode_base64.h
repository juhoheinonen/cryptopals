#include <stddef.h>

#ifndef DECODE_BASE64_H
#define DECODE_BASE64_H

char* decode_base64(const char* input, size_t input_length, size_t* decoded_length);

#endif
