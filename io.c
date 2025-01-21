#include <stdio.h>

int main() {
    char char_value;
    short short_value;
    int int_value;
    long long_value;
    long long long_long_value;
    unsigned char unsigned_char_value;
    unsigned int unsigned_int_value;
    unsigned short unsigned_short_value;
    unsigned long unsigned_long_value;
    unsigned long long unsigned_long_long_value;
    float float_value;
    double double_value;
    long double long_double_value;

    printf("Enter a char value                -> ");
    scanf("%c", &char_value);
    printf("Enter a short value               -> ");
    scanf("%hi", &short_value);
    printf("Enter a short value               -> ");
    scanf("%d", &int_value);
    printf("Enter a long value                -> ");
    scanf("%ld", &long_value);
    printf("Enter a long long value           -> ");
    scanf("%lld", &long_long_value);
    printf("Enter a unsigned char value       -> ");
    scanf(" %c", &unsigned_char_value);
    printf("Enter a unsigned int value        -> ");
    scanf("%hu", &unsigned_short_value);
    printf("Enter a unsigned short value      -> ");
    scanf("%u", &unsigned_int_value);
    printf("Enter a unsigned long value       -> ");
    scanf("%lu", &unsigned_long_value);
    printf("Enter a unsigned long long value  -> ");
    scanf("%llu", &unsigned_long_long_value);
    printf("Enter float value                 -> ");
    scanf("%f", &float_value);
    printf("Enter a double value              -> ");
    scanf("%lf", &double_value);
    printf("Enter a long double value         -> ");
    scanf("%Lf", &long_double_value);

    printf("\nvalue -> %c\n", char_value);
    printf("value -> %hi\n", short_value);
    printf("value -> %d\n", int_value);
    printf("value -> %ld\n", long_value);
    printf("value -> %lld\n", long_long_value);
    printf("value -> %c\n", unsigned_char_value);
    printf("value -> %hu\n", unsigned_short_value);
    printf("value -> %u\n", unsigned_int_value);
    printf("value -> %lu\n", unsigned_long_value);
    printf("value -> %llu\n", unsigned_long_long_value);
    printf("value -> %f\n", float_value);
    printf("value -> %lf\n", double_value);
    printf("value -> %Lf\n", long_double_value);

    return 0;
}
