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
#include "lib/hamming_distance.h"
#include "lib/hex_string_to_byte_array.h"
#include "lib/read_file.h"

int main(int argc, char *argv[])
{
    // usage, one arg, file name, is required
    if (argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }
    
    // Read the file contents to a buffer
    char *buffer = NULL;


    // for (int keysize = 2; keysize <= 40; keysize++)
    // {
    //     // Read the file
    //     FILE *file = fopen("set1_6.txt", "r");
    //     if (file == NULL)
    //     {
    //         printf("Error! Could not open file\n");
    //         return 1;
    //     }

    //     // Get the file size
    //     fseek(file, 0, SEEK_END);
    //     int file_size = ftell(file);
    //     fseek(file, 0, SEEK_SET);

    //     // Read the file into a buffer
    //     char *buffer = (char *)malloc(file_size + 1);
    //     fread(buffer, 1, file_size, file);
    //     buffer[file_size] = '\0';

    //     // Convert the base64 encoded string to a byte array
    //     unsigned char *byte_array = base64_string_to_byte_array(buffer, file_size);

    //     // Calculate the hamming distance between the first keysize bytes and the second keysize bytes
    //     int distance = hamming_distance(byte_array, byte_array + keysize, keysize);

    //     // Normalize the distance
    //     float normalized_distance = (float)distance / keysize;

    //     printf("Keysize: %d, Distance: %d, Normalized Distance: %f\n", keysize, distance, normalized_distance);

    //     // Free the memory
    //     free(buffer);
    //     free(byte_array);
    //     fclose(file);
    // }
}