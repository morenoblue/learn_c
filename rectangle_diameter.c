#include <stdio.h>

int main() {
    float radius, diameter, circumference, area;

    printf("Enter radius: ");
    scanf("%f", &radius);

    diameter = 2 * radius;
    circumference = 2 * 3.14 * radius;
    area = 3.14 * radius * radius;
    printf("diameter = %2.f units\n", diameter);
    printf("circumference = %2.f units\n", circumference);
    printf("area = %2.f sq. units\n", area);
    return 0;
}
