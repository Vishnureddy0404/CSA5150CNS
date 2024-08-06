#include<stdio.h>
int main() {
    int a = 3;
    int b = 5;
    if (a % 2 == 0 && a % 13 == 0) {
        printf("a is not coprime\n");
        return 1;
    }
    int p = 10;
    int C = ((a * p) + b) % 26;
    printf("%c", 'A' + C);
    return 0;
}

