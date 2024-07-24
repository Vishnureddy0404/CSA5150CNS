#include <stdio.h>
#include <ctype.h>

// Function to encrypt or decrypt a message using Caesar cipher
void caesarCipher(char message[], int key, int encrypt) {
    char ch;
    int i;

    // Iterate through each character in the message
    for(i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        if(isalpha(ch)) {  // Check if the character is a letter
            // Determine the shift based on whether encrypting or decrypting
            int shift = (encrypt) ? key : -key;

            // Shift the character within the bounds of 'A'-'Z' or 'a'-'z'
            if(isupper(ch)) {
                ch = ((ch - 'A' + shift) % 26) + 'A';
            } else {
                ch = ((ch - 'a' + shift) % 26) + 'a';
            }
        }

        // Print the encrypted or decrypted character
        printf("%c", ch);
    }
}

int main() {
    char message[100];
    int key, choice;

    printf("Enter message to encrypt or decrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter key (1-25): ");
    scanf("%d", &key);

    // Validate the key within the range 1-25
    if(key < 1 || key > 25) {
        printf("Invalid key! Key should be between 1 and 25.\n");
        return 1;
    }

    printf("Choose operation:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Encrypted message: ");
            caesarCipher(message, key, 1);
            break;
        case 2:
            printf("Decrypted message: ");
            caesarCipher(message, key, 0);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    return 0;
}
