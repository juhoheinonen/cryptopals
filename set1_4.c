//  One of the 60-character strings in this file has been encrypted by single-character XOR.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/hex_to_chars.h"
#include "lib/xor_unsigned_char_array_with_unsigned_char.h"
#include "lib/score_string_by_english_character_frequency.h"

#define MAX_LINE_LENGTH 1024

int main(int argc, char **argv)
{
    // if the number of arguments is not 2, tell it and exit
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    char line[MAX_LINE_LENGTH];

    float max_score = 0;
    unsigned char *current_best_score_text = NULL;
    int possible_cipher_key = 0;

    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        line[strcspn(line, "\n")] = '\0';

        // Process each line here
        int len = strlen(line);
        if (len % 2 != 0)
        {
            printf("Hex string length is not even\n");
            return 1;
        }

        unsigned char *chars1 = hex_to_chars(line, len);

        // loop through ascii characters from 0 to 255
        for (int i = 0; i < 256; i++)
        {
            unsigned char *xorred = xor_unsigned_char_array_with_unsigned_char(chars1, len, i);

            // score xorred by its character frequency
            float score = score_string_by_english_character_frequency(xorred, len / 2);

            // if the score is greater than the max score, update the max score and the current best score
            if (score > max_score)
            {
                max_score = score;
                current_best_score_text = xorred;
                current_best_score_text[len / 2] = '\0';
                possible_cipher_key = i;
            }
            else
            {
                free(xorred);
            }
        }
    }

    // Loop through each line in the file. Line length is according to exercise.
    // char line[80];
    // while (fgets(line, sizeof(line), file))
    // {
    //     // reset max_score
    //     max_score = 0;
    //     // reset current_best_score_text
    //     current_best_score_text = NULL;

    //     // Remove the trailing newline character if present
    //     line[strcspn(line, "\n")] = '\0';

    //     // Process each line here
    //     int len = strlen(line);
    //     if (len % 2 != 0)
    //     {
    //         printf("Hex string length is not even\n");
    //         return 1;
    //     }

    //     unsigned char *chars1 = hex_to_chars(line, len);

    //     // loop through ascii characters from 0 to 255
    //     for (int i = 0; i < 256; i++)
    //     {
    //         unsigned char *xorred = xor_unsigned_char_array_with_unsigned_char(chars1, len, i);

    //         // score xorred by its character frequency
    //         float score = score_string_by_english_character_frequency(xorred, len / 2);

    //         // if the score is greater than the max score, update the max score and the current best score
    //         if (score > max_score)
    //         {
    //             max_score = score;
    //             current_best_score_text = xorred;
    //             possible_cipher_key = i;
    //         }
    //         else
    //         {
    //             free(xorred);
    //         }
    //     }
    printf("Possible cipher key: %c\n", possible_cipher_key);

    // print the decrypted message
    printf("Decrypted message: %s\n", current_best_score_text);

    // print score of the decrypted message
    printf("Score: %f\n", max_score);

    printf("\n");
    // }

    return 0;
}