#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

long long mult(long long a, long long b)
{
    int sign = ((a < 0) ^ (b < 0)) ? -1 : 1;
    unsigned long long ua = (a < 0) ? (unsigned long long)(-a) : (unsigned long long)a;
    unsigned long long ub = (b < 0) ? (unsigned long long)(-b) : (unsigned long long)b;

    unsigned long long res = 0ULL;
    while (ub) {
        if (ub & 1ULL) res += ua;
        ua <<= 1;
        ub >>= 1;
    }
    return sign == 1 ? (long long)res : -(long long)res;
}

long long quo(long long a, long long b)
{
    if (b == 0) {
        
        return 0;
    }

    int sign = ((a < 0) ^ (b < 0)) ? -1 : 1;
    unsigned long long ua = (a < 0) ? (unsigned long long)(-a) : (unsigned long long)a;
    unsigned long long ub = (b < 0) ? (unsigned long long)(-b) : (unsigned long long)b;

    unsigned long long q = 0ULL;
    if (ub != 0ULL) {
        for (int shift = 63; shift >= 0; --shift) {
            if (ub <= (ua >> shift)) {
                ua -= (ub << shift);
                q |= (1ULL << shift);
            }
        }
    }

    long long result = sign == 1 ? (long long)q : -(long long)q;
    return result;
}
long long rem(long long a, long long b)
{
    if (b == 0) {
        return 0;
    }

    int sign_a = (a < 0) ? -1 : 1;
    unsigned long long ua = (a < 0) ? (unsigned long long)(-a) : (unsigned long long)a;
    unsigned long long ub = (b < 0) ? (unsigned long long)(-b) : (unsigned long long)b;

    if (ub == 0ULL) return 0;

    for (int shift = 63; shift >= 0; --shift) {
        if (ub <= (ua >> shift)) {
            ua -= (ub << shift);
        }
    }

    long long r = sign_a == 1 ? (long long)ua : -(long long)ua;
    return r;
}

int main(void)
{
    long long a, b;
    printf("Enter two integers a b: ");
    if (scanf("%lld %lld", &a, &b) != 2) return 1;

    long long p = mult(a, b);
    if (b == 0) {
        printf("Product = %lld\n", p);
        printf("Division by zero: quotient and remainder undefined\n");
    } else {
        long long q = quo(a, b);
        long long r = rem(a, b);
        printf("Product = %lld\n", p);
        printf("Quotient = %lld\n", q);
        printf("Remainder = %lld\n", r);
    }
    return 0;
}