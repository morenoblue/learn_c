#include <stdio.h>

int main(){
    float length_centimeter, length_meter, length_kilometer;

    printf("Enter length in centimeter = ");
    scanf("%f", &length_centimeter);

    length_meter = length_centimeter / 100;
    length_kilometer = length_centimeter / 10000;

    printf("Length in meter = %.2f m\n", length_meter);
    printf("Length in kilometer = %.2f km", length_kilometer);
    
    return 0;
}
