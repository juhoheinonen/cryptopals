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

    // Calculate the score based on the frequency of each letter
    for (int i = 0; i < 256; i++)
    {
        if (i >= 'a' && i <= 'z')
        {
            score += ascii_frequencies[i] * frequencies[i - 'a'];
        }
        else if (i >= 'A' && i <= 'Z')
        {
            score += ascii_frequencies[i] * frequencies[i - 'A'];
        }
    }

    return score;
}