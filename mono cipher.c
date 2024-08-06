#include <stdio.h>
int main() {
    char plaintext[] = "XIBA";
    char key[] = "KEYWORDABCFGHIJLMNPQSTUVXZ"; 
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            plaintext[i] = key[plaintext[i] - 'A'];
    }
    printf("Encrypted text: %s\n", plaintext);
    return 0;
}

