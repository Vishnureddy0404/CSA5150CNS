#include <stdio.h>

// Function to compute the greatest common divisor
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to check if 'a' is valid
int isValidA(int a) {
    return gcd(a, 26) == 1;
}

// Function to encrypt using Affine Caesar Cipher
char encrypt(char p, int a, int b) {
    if (p >= 'A' && p <= 'Z') {
        return (char) ((((a * (p - 'A') + b) % 26) + 26) % 26 + 'A');
    } else if (p >= 'a' && p <= 'z') {
        return (char) ((((a * (p - 'a') + b) % 26) + 26) % 26 + 'a');
    }
    return p;
}

int main() {
    int a, b;
    char plaintext[1000], ciphertext[1000];

    printf("Enter value for a: ");
    scanf("%d", &a);
    printf("Enter value for b: ");
    scanf("%d", &b);

    // Check validity of 'a'
    if (!isValidA(a)) {
        printf("Invalid value for a. It must be coprime with 26.\n");
        return 1;
    }

    // Consume newline character left in buffer
    getchar();

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Encrypt the plaintext
    int i;
    for (i = 0; plaintext[i] != '\0' && plaintext[i] != '\n'; i++) {
        ciphertext[i] = encrypt(plaintext[i], a, b);
    }
    ciphertext[i] = '\0';

    printf("Encrypted text: %s\n", ciphertext);

    return 0;
}
