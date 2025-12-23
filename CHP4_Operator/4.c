#include <stdio.h>

int main()
{
    int num, remainder;

    printf("Enter a five digit number: ");
    scanf("%d", &num);

    remainder = num % 3;

    printf("Remainder after dividing by 3 = %d", remainder);

    return 0;
}
