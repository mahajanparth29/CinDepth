#include <stdio.h>
#include <stdlib.h>

int cubesum(int n)
{
    int sum = 0;
    n = abs(n);
    if (n == 0) return 0;
    while (n > 0) {
        int d = n % 10;
        sum += d * d * d;
        n /= 10;
    }
    return sum;
}

int main(void)
{
    int low, high;
    printf("Enter lower and upper bounds (0 to 999999): ");
    if (scanf("%d %d", &low, &high) != 2) return 1;
    if (low > high) { int t = low; low = high; high = t; }
    if (low < 0) low = 0;

    int found = 0;
    printf("Armstrong numbers (sum of cubes of digits) in range %d to %d:\n", low, high);
    for (int i = low; i <= high; ++i) {
        if (i == cubesum(i)) {
            printf("%d\n", i);
            found = 1;
        }
    }
    if (!found) printf("None found\n");
    return 0;
}