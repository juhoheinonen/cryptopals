#include <stdio.h>
#include <string.h>
#include "lib/hamming_distance.h"

/*
    Calculate the Hamming distance between two strings.
*/
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    // if the strings are not the same length, return an error    
    if (strlen(argv[1]) != strlen(argv[2]))
    {
        printf("Error: strings must be the same length\n");
        return 1;
    }

    int len = strlen(argv[1]);

    // call a function to calculate the Hamming distance between the two strings
    int edit_distance = hamming_distance(argv[1], argv[2], len);

    return edit_distance;
}