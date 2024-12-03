#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "score_string_by_english_character_frequency.h"

// Function to score a string by its character frequency in English
// Skip non-letter characters.
float score_string_by_english_character_frequency(unsigned char *str, int len)
{
    // Character frequency in English
    // Source: https://en.wikipedia.org/wiki/Letter_frequency
    float frequencies[26] = {
        8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.966, 0.153,
        0.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 5.987, 6.327, 9.056,
        2.758, 0.978, 2.360, 0.150, 1.974, 0.074};

    float score = 0.0;
    int ascii_frequencies[256] = {0};

    // Count the frequency of each ASCII character in the input string
    for (int i = 0; i < len; i++)
    {
        ascii_frequencies[str[i]]++;
    }
    
    int ascii_chars_length = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            ascii_chars_length++;
        }
    }    

    int printable_special_chars = 0;

    // Calculate frequency of each character and compare with the English character frequency.
    for (int i = 0; i < 256; i++)
    {
        if (ascii_frequencies[i] > 0)
        {
            int ascii_char = 0;
            if (isupper(i))
            {
                ascii_char = i - 'A';                
            }
            else if (islower(i))
            {
                ascii_char = i - 'a';                
            } 
            else if (i < 32)
            {
                // Increase penalty for non-printable characters
                score -= 5;
            } 
            else 
            {
                printable_special_chars++;
            }           
            
            float calculated_frequency = (float)ascii_frequencies[i] / ascii_chars_length * 100;
            float expected_frequency = frequencies[ascii_char];

            float difference = fabs(expected_frequency - calculated_frequency);

            // Use logarithmic differences for better handling of variations
            score -= log(1 + difference);
        }
    }

    // calculate words by counting spaces
    int words = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            words++;
        }
    }

    // for each word, add 0.1 to the score
    score += words * 0.1;
    
    // Penalize for too many printable special characters
    if (printable_special_chars > 5) {
        score -= printable_special_chars * 2;
    }

    // Normalize the score
    score = score / ascii_chars_length;

    return score;
}
