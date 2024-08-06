#include <stdio.h>
int main() {
    int p, a, b;
    int c;
    printf("Enter the value of p: ");
    scanf("%d", &p);
    printf("Enter the values of a and b: ");
    scanf("%d%d", &a, &b);
    c = (a * p);
    c = (c + b) % 26;
    printf("The encryption value is: %d\n", c);
    
    return 0;
}

