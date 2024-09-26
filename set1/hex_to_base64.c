#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// convert hex to base64
// input:  49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d
// output: SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t
int main(int argc, char *argv[])
{
	// if argv length is not 2, print usage and exit. Usage should mention that the input is a hex string
	if (argc != 2) {
		printf("Usage: %s <hex_string>\n", argv[0]);
		exit(1);
	}

	int len = strlen(argv[1]);

	// if the length is not even, print an error message and exit
	if (len % 2 != 0) {
		printf("Error: hex string length must be even\n");
		exit(1);
	}

	unsigned char* bytes = (char*)malloc(len / 2);
	
	// go through argv[1] and parse two characters at a time to convert to a byte	
	for (int i = 0; i < len; i += 2) {
		char byte[3] = {argv[1][i], argv[1][i + 1], '\0'};
		bytes[i / 2] = strtol(byte, NULL, 16);
	}		

	// // loop through the bytes and print the value as integer and add dot between them
	// for (int i = 0; i < len / 2; i++) {
	// 	printf("%d", bytes[i]);
	// 	if (i < len / 2 - 1) {
	// 		printf(".");
	// 	}
	// }	

	// // loop through the bytes and print the value as character
	// for (int i = 0; i < len / 2; i++) {
	// 	printf("%c", bytes[i]);
	// }

	printf("loppu");
}
