#include <stdio.h>

int main(void)
{
    long long x, y;
    printf("Enter base x and exponent y: ");
    if (scanf("%lld %lld", &x, &y) != 2) return 1;

    if (y < 0) {
        printf("Exponent must be non-negative\n");
        return 0;
    }

    long long result = 1;
    for (long long i = 0; i < y; ++i) {
        result *= x;
    }

    printf("%lld^%lld = %lld\n", x, y, result);
    return 0;
}