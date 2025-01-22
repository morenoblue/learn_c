# include <stdio.h>

int main(){
    int num, nth;
    printf("Input number: ");
    scanf("%d", &num);
    printf("Input nth bit to set: ");
    scanf("%d", &nth);
    printf("Number after setting nth bit: %d in decimal", (1 << nth) | num);
}
