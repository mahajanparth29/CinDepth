#include <stdio.h>
int main(void)
{
    int n;
    printf("Enter number of terms n: ");
    if (scanf("%d", &n) != 1) return 1;
    if (n <= 0) {
        printf("n must be positive\n");
        return 0;
    }

    double sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        sum += 1.0 / (i * i);
    }

    printf("Sum of series up to %d terms = %.10f\n", n, sum);
    return 0;
}