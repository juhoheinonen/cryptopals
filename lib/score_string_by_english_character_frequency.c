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
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) {
            ascii_chars_length++;
        }
    }    

    // go through ascii_frequencies. Calculate frequency of each character and compare with the English character frequency.
    // if the difference is less than 1.0, add the difference to the score
    for (int i = 0; i < 256; i++)
    {
        if (ascii_frequencies[i] > 0)
        {
            int ascii_char = 0;
            if (i >= 65 && i <= 90)
            {
                ascii_char = i - 65;
                //score += frequencies[i - 65] - ascii_frequencies[i];
            }
            else if (i >= 97 && i <= 122)
            {
                ascii_char = i - 97;
                //score += frequencies[i - 97] - ascii_frequencies[i];
            }
            float calculated_frequency = (float)ascii_frequencies[i] / ascii_chars_length * 100;
            float expected_frequency = frequencies[ascii_char];

            float difference = expected_frequency - calculated_frequency;

            if (difference < 0)
            {
                difference = -difference;
            }

            // if the difference is less than 1.0, add the difference to the score
            if (difference < 1.0)
            {
                score += difference;
            }            
        }
    }

    return score;
}