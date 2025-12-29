#include <stdio.h>
#include <stdlib.h>

static long long multiply_digits(long long n)
{
    n = llabs(n);
    if (n == 0) return 0;
    long long prod = 1;
    while (n > 0) {
        prod *= (n % 10);
        n /= 10;
    }
    return prod;
}


int reduce_to_one_digit(long long n)
{
    n = llabs(n);
    if (n < 10) return (int)n;
    long long p = multiply_digits(n);
    while (p >= 10) p = multiply_digits(p);
    return (int)p;
}

int pers(long long n)
{
    n = llabs(n);
    if (n < 10) return 0;
    int count = 0;
    while (n >= 10) {
        n = multiply_digits(n);
        ++count;
    }
    return count;
}

int main(void)
{
    long long n;
    printf("Enter an integer: ");
    if (scanf("%lld", &n) != 1) return 1;

    int final_digit = reduce_to_one_digit(n);
    int p = pers(n);

    printf("Reduced single digit (by repeated digit-product): %d\n", final_digit);
    printf("Persistence: %d\n", p);
    return 0;
}