#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hex_to_base64.h"
#include "hex_string_to_byte_array.h"

unsigned char *hex_string_to_byte_array(const char *hex_string, int hex_string_length);
char *base64_encode(const unsigned char *data, int input_length);

// convert hex to base64
// input:  49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d
// output: SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t
// Function prototype for hex_to_bytes
char *hex_to_base64(const char *hex_string)
{
	int len = strlen(hex_string);

	// if the length is not even, tell it somehow to caller
	if (len % 2 != 0)
	{
		// printf("Hex string length is not even\n");
		return NULL;
	}

	unsigned char *chars = hex_string_to_byte_array(hex_string, len);
	
	for (int i = 0; i < len; i += 2)
	{
		char byte[3] = {hex_string[i], hex_string[i + 1], '\0'};
		chars[i / 2] = strtol(byte, NULL, 16);
	}

	// base64 encode the bytes
	char *encoded_data = base64_encode(chars, len / 2);

	return encoded_data;
}

static const char base64_chars[] =
	"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char *base64_encode(const unsigned char *data, int input_length)
{
	int output_length = 4 * ((input_length + 2) / 3);
	char *encoded_data = malloc(output_length + 1);
	if (encoded_data == NULL)
		return NULL;

	int i, j;
	for (i = 0, j = 0; i < input_length;)
	{
		unsigned int octet_a = i < input_length ? data[i++] : 0;
		unsigned int octet_b = i < input_length ? data[i++] : 0;
		unsigned int octet_c = i < input_length ? data[i++] : 0;

		unsigned int triple = (octet_a << 16) + (octet_b << 8) + octet_c;

		encoded_data[j++] = base64_chars[(triple >> 18) & 0x3F];
		encoded_data[j++] = base64_chars[(triple >> 12) & 0x3F];
		encoded_data[j++] = base64_chars[(triple >> 6) & 0x3F];
		encoded_data[j++] = base64_chars[triple & 0x3F];
	}

	// Padding
	for (i = 0; i < (3 - input_length % 3) % 3; i++)
	{
		encoded_data[output_length - 1 - i] = '=';
	}

	encoded_data[output_length] = '\0';
	return encoded_data;
}