/*

Break repeating-key XOR
It is officially on, now.

This challenge isn't conceptually hard, but it involves actual error-prone coding. The other challenges in this set are there to bring you up to speed. This one is there to qualify you. If you can do this one, you're probably just fine up to Set 6.

There's a file here. It's been base64'd after being encrypted with repeating-key XOR.

Decrypt it.

Here's how:

    1. Let KEYSIZE be the guessed length of the key; try values from 2 to (say) 40.

    2. Write a function to compute the edit distance/Hamming distance between two strings. The Hamming distance is just the number of differing bits. The distance between:

    this is a test

    and

    wokka wokka!!!

    is 37. Make sure your code agrees before you proceed.

    3. For each KEYSIZE, take the first KEYSIZE worth of bytes, and the second KEYSIZE worth of bytes, and find the edit distance between them.
       Normalize this result by dividing by KEYSIZE.

    4. The KEYSIZE with the smallest normalized edit distance is probably the key. You could proceed perhaps with the smallest 2-3 KEYSIZE values. Or take 4 KEYSIZE blocks instead of 2 and average the distances.

    5. Now that you probably know the KEYSIZE: break the ciphertext into blocks of KEYSIZE length.

    6. Now transpose the blocks: make a block that is the first byte of every block, and a block that is the second byte of every block, and so on.

    7. Solve each block as if it was single-character XOR. You already have code to do this.

    8. For each block, the single-byte XOR key that produces the best looking histogram is the repeating-key XOR key byte for that block. Put them together and you have the key.

This code is going to turn out to be surprisingly useful later on. Breaking repeating-key XOR ("Vigenere") statistically is obviously an academic exercise, a "Crypto 101" thing. But more people "know how" to break it than can actually break it, and a similar technique breaks something much more important.
No, that's not a mistake.

We get more tech support questions for this challenge than any of the other ones. We promise, there aren't any blatant errors in this text. In particular: the "wokka wokka!!!" edit distance really is 37.

*/

#include <stdio.h>
#include <string.h>
#include "lib/hamming_distance.h"
#include "lib/hex_string_to_byte_array.h"
#include "lib/read_file.h"
#include "lib/decode_base64.h"

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
