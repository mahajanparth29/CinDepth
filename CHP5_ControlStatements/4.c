#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1) return 1;

    if (n <= 0) {
        printf("Sum of squares from 1 to %d = 0\n", n);
        return 0;
    }

    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += (long long)i * i;
    }

    printf("Sum of squares from 1 to %d = %lld\n", n, sum);
    return 0;
}