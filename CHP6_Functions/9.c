#include <stdio.h>
#include <stdlib.h>

unsigned long long rcomb(int n, int r)
{
    if (r < 0 || n < 0 || r > n) return 0;
    if (r == 0 || r == n) return 1;
    /* use symmetry to reduce recursion depth */
    if (r > n - r) r = n - r;
    return rcomb(n - 1, r) + rcomb(n - 1, r - 1);
}

int main(void)
{
    int n, r;
    printf("Enter n and r: ");
    if (scanf("%d %d", &n, &r) != 2) return 1;
    if (n < 0 || r < 0) {
        printf("n and r must be non-negative\n");
        return 0;
    }
    unsigned long long c = rcomb(n, r);
    printf("C(%d, %d) = %llu\n", n, r, c);
    return 0;
}