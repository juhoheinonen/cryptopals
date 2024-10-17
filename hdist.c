#include <stdio.h>

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
}