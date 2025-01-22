#include <stdio.h>
#define MSB_CHECK 1 << (sizeof(int)*8-1)

int main() {
    int num;
    printf("Input number: ");
    scanf("%d", &num);
    if (num & MSB_CHECK) {
        printf("Most Significant Bit of %d is set (1).", num);
    } else {
        printf("Most Significant Bit of %d is not set (0).", num);
    }
}

