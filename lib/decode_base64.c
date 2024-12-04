#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <b64/cdecode.h>

char* decode_base64(const char *input, size_t *decoded_length) {
	base64_decodestate state;
	base64_init_decodestate(&state);

	size_t input_length = strlen(input);
	size_t output_length = input_length * 3 / 4;
	char *output = (char *)malloc(output_length + 1); // +1 for null terminator

	if (output == NULL) {
		return NULL;
	}

	*decoded_length = base64_decode_block(input, input_length, output, &state);
	output[*decoded_length] = '\0';
	return output;
}
