/*
Implement repeating-key XOR

Here is the opening stanza of an important work of the English language:

Burning 'em, if you ain't quick and nimble
I go crazy when I hear a cymbal

Encrypt it, under the key "ICE", using repeating-key XOR.

In repeating-key XOR, you'll sequentially apply each byte of the key; the first byte of plaintext will be XOR'd against I, the next C, the next E, then I again for the 4th byte, and so on.

It should come out to:

0b3637272a2b2e63622c2e69692a23693a2a3c6324202d623d63343c2a26226324272765272
a282b2f20430a652e2c652a3124333a653e2b2027630c692b20283165286326302e27282f

Encrypt a bunch of stuff using your repeating-key XOR function. Encrypt your mail. Encrypt your password file. Your .sig file. Get a feel for it. I promise, we aren't wasting your time with this.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/encode_base64.h"

char *encrypt_repeating_key_xor(char *plaintext, char *key, int plaintext_len, int key_len)
{
    char *ciphertext = malloc(plaintext_len + 1);
    if (ciphertext == NULL)
    {
        printf("Error: malloc failed\n");
        return NULL;
    }

    for (int i = 0; i < plaintext_len; i++)
    {
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
    }

    ciphertext[plaintext_len] = '\0';

    return ciphertext;
}

int main(int argc, char *argv[])
{
    int base64_output = 0;
    char *plaintext;
    char *key;

    if (argc == 4 && strcmp(argv[1], "-b64") == 0)
    {
        base64_output = 1;
        plaintext = argv[2];
        key = argv[3];
    }
    else if (argc == 3)
    {
        plaintext = argv[1];
        key = argv[2];
    }
    else
    {
        printf("Usage: ./encrepxor [-b64] plaintext key\n");
        return 1;
    }

    int plaintext_len = strlen(plaintext);
    int key_len = strlen(key);

    // call a function to encrypt the plaintext with the key
    char *ciphertext = encrypt_repeating_key_xor(plaintext, key, plaintext_len, key_len);

    if (base64_output)
    {
        // print the ciphertext as base64        
        char *base64_ciphertext = encode_base64(ciphertext);
        printf("%s\n", base64_ciphertext);
        free(base64_ciphertext);
    }
    else
    {
        // print the ciphertext as hexes
        for (int i = 0; i < plaintext_len; i++)
        {
            printf("%02x", ciphertext[i]);
        }
        printf("\n");
    }

    free(ciphertext);
    return 0;    
}