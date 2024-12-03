#include <stdio.h>
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
    char *decoded = decode_base64(buffer);

    // Get length of the decoded buffer
    int decoded_length = strlen(decoded);
        
    keysize_distance_t kd = {0, 1000}; // Initialize with a large value for normalized_distance
    
    // Loop through key sizes from 2 to 40.
    for (int keysize = 2; keysize <= 10; keysize++)
    {
        if (keysize * 2 > decoded_length)
        {
            break;
        }        

        // Calculate the hamming distance between the first and second keysize worth of bytes and the third and fourth keysize worth of bytes
        int distance = hamming_distance(decoded, decoded + keysize, keysize) + hamming_distance(decoded + keysize * 2, decoded + keysize * 3, keysize);
        // Calculate the normalized edit distance
        double normalized_distance = (double)distance / keysize / 2;        
	
//		printf("keysize: %d\n", keysize);
//		printf("distanc: %d\n", distance);
//		printf("norm nd: %f\n", normalized_distance);

        if (normalized_distance < kd.normalized_distance)
        {
            kd.keysize = keysize;
            kd.normalized_distance = normalized_distance;
        }

        // // Calculate the hamming distance between the first and second keysize worth of bytes
        // int distance = hamming_distance(decoded, decoded + keysize, keysize);
        // // Calculate the normalized edit distance
        // double normalized_distance = (double)distance / keysize;

        // // NOTE: first just simple solution, take the smallest normalized distance. If it does not work, then try later more advanced.
        // if (normalized_distance < kd.normalized_distance)
        // {
        //     kd.keysize = keysize;
        //     kd.normalized_distance = normalized_distance;
        // }        
    }

    printf("Keysize: %d\n", kd.keysize);
    printf("Normalized distance: %f\n", kd.normalized_distance);    
}
