#include <stdio.h>
#include <math.h>

int main(void)
{
    int choice;
    printf("Choose series to sum (enter number):\n");
    printf("1) 1 + 2 + 4 + 7 + 11 + 16 + ... (nth term increases by 1,2,3...)\n");
    printf("2) 1 + 11 + 111 + 1111 + ... (n terms of repeated '1')\n");
    printf("3) x + x + x + ... (x repeated n times)\n");
    printf("4) x - x^2 + x^3 - x^4 + ... (alternating powers up to n terms)\n");
    printf("5) 1/x - 1/x + 1/x - 1/x + ... (alternating constant 1/x)\n");
    printf("6) x + x^2 + x^3 + ... (plain powers up to n)\n");
    if (scanf("%d", &choice) != 1) return 1;

    long long n;
    long long x;
    double sumd;
    long long sumll;
    long long term;
    if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 6) {
        printf("Enter integer x (for choices that need x, otherwise enter 0): ");
        if (scanf("%lld", &x) != 1) return 1;
    } else {
        x = 0;
    }
    printf("Enter number of terms n: ");
    if (scanf("%lld", &n) != 1) return 1;
    if (n <= 0) {
        printf("n must be positive\n");
        return 0;
    }

    switch (choice) {
        case 1:
            /* 1,2,4,7,11,... : a1=1, for i>=2 ai = a_{i-1} + (i-1) */
            term = 1;
            sumll = term;
            for (long long i = 2; i <= n; ++i) {
                term += (i - 1);
                sumll += term;
            }
            printf("Sum of series 1,2,4,7,... up to %lld terms = %lld\n", n, sumll);
            break;

        case 2:
            /* 1 + 11 + 111 + ... */
            term = 0;
            sumll = 0;
            for (long long i = 1; i <= n; ++i) {
                term = term * 10 + 1; /* build next 111..1 */
                sumll += term;
            }
            printf("Sum of 1 + 11 + 111 + ... (n=%lld) = %lld\n", n, sumll);
            break;

        case 3:
            /* x repeated n times */
            sumll = x * n;
            printf("Sum of x repeated %lld times = %lld\n", n, sumll);
            break;

        case 4:
            /* x - x^2 + x^3 - x^4 + ... up to n terms (use double to avoid overflow) */
            sumd = 0.0;
            for (long long i = 1; i <= n; ++i) {
                double p = pow((double)x, (double)i);
                if (i % 2 == 1) sumd += p;
                else sumd -= p;
            }
            printf("Sum of alternating powers up to %lld terms = %.10g\n", n, sumd);
            break;

        case 5:
            /* 1/x - 1/x + 1/x - ... */
            if (x == 0) {
                printf("Division by zero (x must be non-zero for this series)\n");
                return 0;
            }
            if (n % 2 == 0) sumd = 0.0;
            else sumd = 1.0 / (double)x;
            printf("Sum of alternating 1/x terms (n=%lld) = %.10g\n", n, sumd);
            break;

        case 6:
            /* x + x^2 + x^3 + ... */
            sumd = 0.0;
            for (long long i = 1; i <= n; ++i) sumd += pow((double)x, (double)i);
            printf("Sum of x + x^2 + ... up to %lld terms = %.10g\n", n, sumd);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}