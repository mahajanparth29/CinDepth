#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter a number (0 to 999999): ");
    if (scanf("%d", &n) != 1) return 1;

    if (n < 0 || n > 999999) {
        printf("Number out of range\n");
        return 0;
    }

    if (n == 0) {
        printf("zero\n");
        return 0;
    }

    int digits[6];
    int len = 0;
    while (n > 0) {
        digits[len++] = n % 10;
        n /= 10;
    }

    for (int i = len - 1; i >= 0; --i) {
        switch (digits[i]) {
            case 0:  printf("zero");  break;
            case 1:  printf("one");   break;
            case 2:  printf("two");   break;
            case 3:  printf("three"); break;
            case 4:  printf("four");  break;
            case 5:  printf("five");  break;
            case 6:  printf("six");   break;
            case 7:  printf("seven"); break;
            case 8:  printf("eight"); break;
            case 9:  printf("nine");  break;
        }
        if (i > 0) putchar(' ');
    }
    putchar('\n');
    return 0;
}