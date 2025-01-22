# include <stdio.h>

int main(){
    int num, nth;
    printf("Input number: ");
    scanf("%d", &num);
    printf("Input nth bit to clear: ");
    scanf("%d", &nth);
    printf("Number after clearing nth bit: %d in decimal", ~(1 << nth) & num);
}
