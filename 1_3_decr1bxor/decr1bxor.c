/*
Single-byte XOR cipher

The hex encoded string:

1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736

... has been XOR'd against a single character. Find the key, decrypt the message.
You can do this by hand. But don't: write code to do it for you.
How? Devise some method for "scoring" a piece of English plaintext. Character frequency is a good metric. Evaluate each output and choose the one with the best score.
*/

#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/hex_string_to_byte_array.h"
#include "../lib/xor_unsigned_char_array_with_unsigned_char.h"
#include "../lib/score_string_by_english_character_frequency.h"

int main(int argc, char **argv)
{
    // if the number of arguments is not 2, tell it and exit
    if (argc != 2)
    {
        printf("Usage: %s <hex_string>\n", argv[0]);
        return 1;
    }

    // get the length of the hex string
    int len = strlen(argv[1]);

    // if the length is not even, tell it and exit
    if (len % 2 != 0)
    {
        printf("Hex string length is not even\n");
        return 1;
    }

    unsigned char *chars1 = hex_string_to_byte_array(argv[1], len);

	// this initial value is arbitrary
    float max_score = -999999;
    unsigned char *current_best_score = NULL;
    int possible_cipher_key = 0;

    // loop through ascii characters from 0 to 255
    for (int i = 0; i < 256; i++)
    {
        unsigned char *xorred = xor_unsigned_char_array_with_unsigned_char(chars1, len, i);

        // score xorred by its character frequency
        float score = score_string_by_english_character_frequency(xorred, len / 2);

        if (score > 5) {
            // print xorred
            printf("Key: %c\n", i);
            // print score
            printf("Score: %f\n", score);
            for (int i = 0; i < len / 2; i++)
            {            
                printf("%c", xorred[i]);
            }
            printf("\n");
        }

        // if the score is greater than the max score, update the max score and the current best score
        if (score > max_score)
        {
            max_score = score;
            current_best_score = xorred;
            possible_cipher_key = i;
        }
        else
        {
            free(xorred);
        }
    }

    // print the possible cipher key
    printf("Possible cipher key: %c\n", possible_cipher_key);

    // print the decrypted message
    for (int i = 0; i < len / 2; i++)
    {
        printf("%c", current_best_score[i]);
    }

    printf("\n");

    // print the decrypted message in hex
    for (int i = 0; i < len / 2; i++)
    {
        printf("%02x", current_best_score[i]);
    }

    return 0;
}
