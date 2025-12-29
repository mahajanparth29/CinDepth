#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, c;
    printf("Enter coefficients a b c: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return 1;

    if (fabs(a) < 1e-12) {
        /* Linear or degenerate */
        if (fabs(b) < 1e-12) {
            if (fabs(c) < 1e-12)
                printf("Infinite solutions (0 = 0)\n");
            else
                printf("No solution (inconsistent)\n");
        } else {
            printf("Linear solution: x = %.6f\n", -c / b);
        }
        return 0;
    }

    double disc = b*b - 4.0*a*c;
    double denom = 2.0*a;

    if (disc > 0.0) {
        double r1 = (-b + sqrt(disc)) / denom;
        double r2 = (-b - sqrt(disc)) / denom;
        printf("Two real roots: x1 = %.6f, x2 = %.6f\n", r1, r2);
    } else if (fabs(disc) <= 1e-12) {
        double r = -b / denom;
        printf("One real root: x = %.6f\n", r);
    } else {
        double real = -b / denom;
        double imag = sqrt(-disc) / denom;
        printf("Two complex roots: x1 = %.6f + %.6fi, x2 = %.6f - %.6fi\n",
               real, imag, real, imag);
    }

    return 0;
}