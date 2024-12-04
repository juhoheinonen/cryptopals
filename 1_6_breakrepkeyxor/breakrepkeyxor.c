#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/hamming_distance.h"
#include "../lib/hex_string_to_byte_array.h"
#include "../lib/read_file.h"
#include "../lib/decode_base64.h"

typedef struct
{
	int keysize;
	double normalized_distance;
} keysize_distance_t;

keysize_distance_t get_probable_keysize(int min_keysize, int max_keysize, char *decoded, int decoded_length)
{
	keysize_distance_t kd = {0, 1000}; // Initialize with a large value for normalized_distance

	// Loop through key sizes from 2 to 40.
	for (int keysize = 2; keysize <= 40; keysize++)
	{
		if (keysize * 2 > decoded_length)
		{
			break;
		}

		// Calculate the hamming distance between the first and second keysize worth of bytes and the third and fourth keysize worth of bytes
		int distance = hamming_distance(decoded, decoded + keysize, keysize) + hamming_distance(decoded + keysize * 2, decoded + keysize * 3, keysize);
		// Calculate the normalized edit distance
		double normalized_distance = (double)distance / keysize / 2;

		if (normalized_distance < kd.normalized_distance)
		{
			kd.keysize = keysize;
			kd.normalized_distance = normalized_distance;
		}
	}

	return kd;
}

char **chunk_data(char *data, int data_length, int chunk_size, int *num_chunks)
{
	*num_chunks = (data_length + chunk_size - 1) / chunk_size; // Calculate the number of chunks
	char **chunks = malloc(*num_chunks * sizeof(char *));
	for (int i = 0; i < *num_chunks; i++)
	{
		chunks[i] = malloc(chunk_size + 1); // Allocate memory for each chunk
		strncpy(chunks[i], data + i * chunk_size, chunk_size);
		chunks[i][chunk_size] = '\0'; // Null-terminate the chunk
	}
	return chunks;
}

int main(int argc, char *argv[])
{
	// usage, one arg, file name, is required
	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return 1;
	}

	// Read the file contents to a buffer
	char *buffer = read_file(argv[1]);
	if (buffer == NULL)
	{
		return 1;
	}

	// Decode the base64 encoded buffer
	size_t decoded_length = 0;
	size_t input_length = strlen(buffer);
	char *decoded = decode_base64(buffer, input_length, &decoded_length);

	keysize_distance_t kd = get_probable_keysize(2, 40, decoded, decoded_length);	

	printf("Probable keysize: %d\n", kd.keysize);
	printf("Normalized distance: %f\n", kd.normalized_distance);

	// Chunk the decoded data
	int num_chunks;
	char **chunks = chunk_data(decoded, decoded_length, kd.keysize, &num_chunks);

	char **transposed_chunks = malloc(kd.keysize * sizeof(char *));
	for (int i = 0; i < kd.keysize; i++)
	{
		transposed_chunks[i] = malloc(num_chunks + 1 * sizeof(char));
		for (int j = 0; j < num_chunks; j++)
		{
			transposed_chunks[i][j] = chunks[j][i];
		}
		transposed_chunks[i][num_chunks] = '\0';
	}

	for (int i = 0; i < kd.keysize; i++)
	{
		printf("Chunk %d: %s\n", i, transposed_chunks[i]);
	}
	
	free(chunks); // Free the array of chunks

	free(decoded); // Free the decoded buffer
	free(buffer); // Free the original buffer

	return 0;
}
