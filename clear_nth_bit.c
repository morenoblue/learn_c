#include <stdio.h>

int main() {
    int num, nth;
    printf("Input number: ");
    scanf("%d", &num);
    printf("Input nth bit to toggle: ");
    scanf("%d", &nth);
    printf("Number after toggling the nth bit: %d in decimal",
           (1 << nth) ^ num);
    // I think I can get used to this;
    return 0;
}

