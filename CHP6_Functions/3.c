#include <stdio.h>

int sumdiv(int n)
{
    if (n <= 1) return 0;
    int sum = 1; /* 1 is a proper divisor for n>1 */
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            int j = n / i;
            if (j != i) sum += j;
        }
    }
    return sum;
}

int main(void)
{
    int low, high;
    printf("Enter lower and upper bounds: ");
    if (scanf("%d %d", &low, &high) != 2) return 1;
    if (low > high) { int t = low; low = high; high = t; }
    if (low < 2) low = 2;

    int found = 0;
    printf("Perfect numbers in range %d to %d:\n", low, high);
    for (int n = low; n <= high; ++n) {
        if (sumdiv(n) == n) {
            printf("%d\n", n);
            found = 1;
        }
    }
    if (!found) printf("None found\n");
    return 0;
}