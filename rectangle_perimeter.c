#include <stdio.h>

int main() {
    float perimeter, lenght, width;

    printf("Enter length: ");
    scanf("%f", &lenght);
    printf("Enter width: ");
    scanf("%f", &width);

    perimeter = 2 * lenght + 2 * width;

    printf("Perimeter of rectangle = %.2f units", perimeter);

    return 0;
}
