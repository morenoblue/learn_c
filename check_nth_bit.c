#include <stdio.h>

int main() {
    int num, nth, check;
    printf("Input number: ");
    scanf("%d", &num);
    printf("Input nth bit number: ");
    scanf("%d", &nth);

    check = 1 << nth;

    if (num & check) {
        printf("%d bit of %d is set (1)", nth, num);
    } else {
        printf("%d bit of %d is not set (0)", nth, num);
    }
}
