#include <stdio.h>
int main() {
    char text[] = "HELLO WORLD";
    int k = 3; 
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = 'A' + (text[i] - 'A' + k) % 26;
        else if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = 'a' + (text[i] - 'a' + k) % 26;
    }
    printf("Encrypted text: %s\n", text);
    return 0;
}

