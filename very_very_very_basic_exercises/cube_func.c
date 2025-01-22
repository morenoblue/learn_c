#include <stdio.h>

int cube(int x) { return x * x * x; }

int main() {
    int num;
    printf("Input any number: ");
    scanf("%d", &num);
    printf("Cube of %d = %d", num, cube(num));
    return 0;
}
