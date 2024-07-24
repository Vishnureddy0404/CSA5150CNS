#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to perform monoalphabetic substitution
void monoalphabeticCipher(char message[], char key[], int encrypt) {
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i;

    // Convert key to uppercase for consistency
    for (i = 0; key[i] != '\0'; i++) {
        key[i] = toupper(key[i]);
    }

    // Iterate through each character in the message
    for (i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        if (isalpha(ch)) {
            int is_upper = isupper(ch);
            ch = toupper(ch);
            char *pos;

            if (encrypt) {
                // Find the position of the character in the alphabet and map it to the key
                pos = strchr(alphabet, ch);
                if (pos != NULL) {
                    int index = pos - alphabet;
                    ch = key[index];
                }
            } else {
                // Find the position of the character in the key and map it to the alphabet
                pos = strchr(key, ch);
                if (pos != NULL) {
                    int index = pos - key;
                    ch = alphabet[index];
                }
            }

            // Restore the original case
            if (!is_upper) {
                ch = tolower(ch);
            }
        }

        // Print the encrypted or decrypted character
        printf("%c", ch);
    }
    printf("\n"); // Print a new line after the message
}

int main() {
    char message[100], key[27];
    int choice;

    printf("Enter message to encrypt or decrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';  // Remove newline character

    printf("Enter 26-letter key for substitution: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';  // Remove newline character

    // Validate the key length
    if (strlen(key) != 26) {
        printf("Invalid key! Key should be exactly 26 letters long.\n");
        return 1;
    }

    printf("Choose operation:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Consume newline character left by scanf
    while(getchar() != '\n');

    switch (choice) {
        case 1:
            printf("Encrypted message: ");
            monoalphabeticCipher(message, key, 1);
            break;
        case 2:
            printf("Decrypted message: ");
            monoalphabeticCipher(message, key, 0);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    return 0;
}
