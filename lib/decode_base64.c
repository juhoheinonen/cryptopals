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

/*	// Remove newlines and spaces from input
	char *clean_input = malloc(input_length + 1);
	if (clean_input == NULL) {
		free(output);
		return NULL;
	}

	size_t j = 0;
	for (size_t i = 0; i < input_length; i++) {
		if (input[i] != '\n' && input[i] != ' ' && input[i] != '\r' && input[i] != '\t') {
			clean_input[j++] = input[i];
		}
	}
	clean_input[j] = '\0';

	*decoded_length = base64_decode_block(clean_input, j, output, &state);
	printf("length: %zu\n", *decoded_length);
	//output[*decoded_length] = '\0'; // Null-terminate the output string
*/
	//printf("Output: %s\n", output);
	//
	*decoded_length = base64_decode_block(input, input_length, output, &state);
	output[*decoded_length] = '\0';
	return output;
}
