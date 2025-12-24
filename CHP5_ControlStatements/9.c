#include <stdio.h>
#include <math.h>
#include <stdbool.h>

static bool is_perfect_square(long long x)
{
    if (x < 0) return false;
    long long s = (long long)(sqrt((long double)x) + 0.5L);
    return s * s == x;
}

int main(void)
{
    long long n;
    printf("Enter a non-negative integer: ");
    if (scanf("%lld", &n) != 1) return 1;

    if (n < 0) {
        printf("Negative numbers are not Fibonacci\n");
        return 0;
    }

    long long a = 0, b = 1;
    if (n == 0 || n == 1) {
        printf("%lld is a Fibonacci number\n", n);
        return 0;
    }

    while (b < n) {
        long long next = a + b;
        a = b;
        b = next;
    }

    if (b == n)
        printf("%lld is a Fibonacci number\n", n);
    else
        printf("%lld is not a Fibonacci number\n", n);

    return 0;
}