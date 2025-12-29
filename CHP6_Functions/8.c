#include <stdio.h>
#include <stdlib.h>

long long sumd(long long n)
{
    if (n == 0) return 0;
    if (n < 0) n = -n;          /* handle negative input */
    return (n % 10) + sumd(n / 10);
}

int main(void)
{
    long long n;
    printf("Enter an integer: ");
    if (scanf("%lld", &n) != 1) return 1;
    printf("Sum of digits = %lld\n", sumd(n));
    return 0;
}