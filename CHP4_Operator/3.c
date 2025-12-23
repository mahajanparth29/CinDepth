#include <stdio.h>

int main()
{
    int num;

    printf("Enter a decimal number: ");
    scanf("%d", &num);

    printf("Octal value = %o\n", num);
    printf("Hexadecimal value = %X", num);

    return 0;
}
