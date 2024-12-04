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
#include "../lib/decode_base64.h"
#include "../lib/hex_string_to_byte_array.h"

unsigned char *decrypt_repeating_key_xor(unsigned char *ciphertext, char *key, int ciphertext_len, int key_len)
{
    unsigned char *plaintext = malloc(ciphertext_len + 1);
    if (plaintext == NULL)
    {
        printf("Error: malloc failed\n");
        return NULL;
    }

    for (int i = 0; i < ciphertext_len; i++)
    {
        plaintext[i] = ciphertext[i] ^ key[i % key_len];
    }

    plaintext[ciphertext_len] = '\0';

    return plaintext;
}

int main(int argc, char *argv[])
{
    char *hex_ciphertext;
    char *base64_hex_ciphertext;
    char *key;

    if (argc == 4 && strcmp(argv[1], "-b64") == 0)
    {
        base64_hex_ciphertext = argv[2];
        size_t decoded_length;
        hex_ciphertext = decode_base64(base64_hex_ciphertext, &decoded_length);
        key = argv[3];
    }
    else if (argc == 3)
    {
        hex_ciphertext = argv[1];
        key = argv[2];
    }
    else
    {
        printf("Usage: ./decrepxor hex_ciphertext key\n OR\nUsage: ./decrepxor -b64 base64_hex_ciphertext key\n");
        return 1;
    }

    int hex_ciphertext_len = strlen(hex_ciphertext);

    unsigned char *ciphertext = hex_string_to_byte_array(hex_ciphertext, hex_ciphertext_len);

    int ciphertext_len = hex_ciphertext_len / 2;

    unsigned char *plaintext = decrypt_repeating_key_xor(ciphertext, key, ciphertext_len, strlen(key));

    printf("%s\n", plaintext);

    return 0;
}
