#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

void generate_cipher_sequence(char *keyword, char *cipher) {
    int used[ALPHABET_SIZE] = {0};
    int i = 0, j = 0;

    // Convert keyword to uppercase and copy to cipher array
    while (keyword[i] != '\0') {
        char ch = toupper(keyword[i]);
        if (!used[ch - 'A']) {
            cipher[j++] = ch;
            used[ch - 'A'] = 1;
        }
        i++;
    }

    // Add remaining letters to cipher array
    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (!used[i]) {
            cipher[j++] = 'A' + i;
        }
    }

    cipher[j] = '\0';
}

void encrypt(char *plaintext, char *cipher, char *ciphertext) {
    int i = 0;

    // Encrypt plaintext using the generated cipher sequence
    while (plaintext[i] != '\0') {
        if (isalpha(plaintext[i])) {
            int index = toupper(plaintext[i]) - 'A';
            ciphertext[i] = cipher[index];
        } else {
            ciphertext[i] = plaintext[i];
        }
        i++;
    }
    ciphertext[i] = '\0';
}

int main() {
    char keyword[] = "CIPHER";
    char cipher[ALPHABET_SIZE + 1];
    char plaintext[100], ciphertext[100];

    generate_cipher_sequence(keyword, cipher);

    printf("Keyword: %s\n", keyword);
    printf("Generated Cipher: %s\n", cipher);

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Remove newline character from plaintext
    plaintext[strcspn(plaintext, "\n")] = '\0';

    encrypt(plaintext, cipher, ciphertext);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
