#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to decrypt a single character using a simple substitution cipher
char decrypt(char ch) {
    switch(ch) {
        case '5':
            return 't';  // Assuming '5' corresponds to 't' based on common letter frequencies
        case '3':
            return 'h';  // Assuming '3' corresponds to 'h' based on common letter frequencies
        case '†':
            return 'e';  // Assuming '†' corresponds to 'e' based on common letter frequencies
        case '1':
            return 'a';  // Assuming '1' corresponds to 'a' based on common letter frequencies
        case '6':
            return 'o';  // Assuming '6' corresponds to 'o' based on common letter frequencies
        case '4':
            return 'r';  // Assuming '4' corresponds to 'r' based on common letter frequencies
        case '8':
            return 'i';  // Assuming '8' corresponds to 'i' based on common letter frequencies
        case ':':
            return 'n';  // Assuming ':' corresponds to 'n' based on common letter frequencies
        case '+':
            return 's';  // Assuming '+' corresponds to 's' based on common letter frequencies
        case ')':
            return 'y';  // Assuming ')' corresponds to 'y' based on common letter frequencies
        case '(':
            return 'u';  // Assuming '(' corresponds to 'u' based on common letter frequencies
        case ';':
            return 'l';  // Assuming ';' corresponds to 'l' based on common letter frequencies
        case ']':
            return 'm';  // Assuming ']' corresponds to 'm' based on common letter frequencies
        case '9':
            return 'g';  // Assuming '9' corresponds to 'g' based on common letter frequencies
        case '0':
            return 'f';  // Assuming '0' corresponds to 'f' based on common letter frequencies
        default:
            return ch;  // Return unchanged if not a recognized character
    }
}

int main() {
    char ciphertext[] = "53‡‡†305))6*:4826)4‡.)4‡);806*;48+860))85::]8*::8+83 (88)5†;46(;88*96*7:8)‡(;485);5†2:*‡(;4956*2(5*4)88*4069285);)6+8)4‡‡;1($9:48081:8:81:48+85;4)485†528806*81 ($9:48:(88;4(‡?34:48)41;161::188;‡?;";
    int i;

    // Decrypt the ciphertext
    printf("Decrypted plaintext:\n");
    for (i = 0; i < strlen(ciphertext); i++) {
        char decrypted_char = decrypt(ciphertext[i]);
        printf("%c", decrypted_char);
    }
    printf("\n");

    return 0;
}
