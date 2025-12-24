#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1) return 1;

    if (n < 1) {
        printf("No numbers from 1 to %d\n", n);
        return 0;
    }

    for (int i = 3; i <= n; i += 3) {
        long long cube = (long long)i * i * i;
        printf("%d^3 = %lld\n", i, cube);
    }

    return 0;
}