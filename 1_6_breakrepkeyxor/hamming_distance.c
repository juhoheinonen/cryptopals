#include <stdio.h>
#include "hamming_distance.h"

int hamming_distance(const char *s1, const char *s2, int len) {
    int edit_distance = 0;

    for (int i = 0; i < len; i++) {
        char c = s1[i] ^ s2[i];

        while (c) {
            edit_distance += c & 1;
            c >>= 1;
        }
    }

    return edit_distance;
}
