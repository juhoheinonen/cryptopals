#include <stdio.h>
#include <string.h>

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

    int edit_distance = 0;    

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        // XOR the two strings
        char c = argv[1][i] ^ argv[2][i];
        
        // count the number of 1s in the result
        while (c)
        {
            edit_distance += c & 1;
            c >>= 1;
        }
    }

    return edit_distance;
}