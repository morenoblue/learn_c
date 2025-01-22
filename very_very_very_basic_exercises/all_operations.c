#include <stdio.h>

int main() {
    int num1, num2, diference, sum, division, product, modulus;

    printf("First number: ");
    scanf("%d", &num1);
    printf("Second number: ");
    scanf("%d", &num2);

    sum = num1 + num2;
    diference = num1 - num2;
    division = (float)num1 / num2;
    product = num1 * num2;
    modulus = num1 % num2;

    printf("sum = %d\n", sum);
    printf("diference = %d\n", diference);
    printf("division = %d\n", division);
    printf("product = %d\n", product);
    printf("modulus = %d\n", modulus);

    return 0;
}
