#include <stdio.h>

int main() {
    float area, lenght, width;

    printf("Enter length: ");
    scanf("%f", &lenght);
    printf("Enter width: ");
    scanf("%f", &width);

    area = lenght * width;

    printf("Area of rectangle = %.2f sq. units", area);

    return 0;
}
