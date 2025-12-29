#include <stdio.h>
#include <stdlib.h>

static void print_digit_word(int d)
{
    switch (d) {
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
}


void print_number_words(long long n)
{
    if (n < 0) {
        printf("minus ");
        n = llabs(n);
    }

    if (n == 0) {
        print_digit_word(0);
        return;
    }

    if (n / 10) {
        print_number_words(n / 10);
        printf(" ");
    }
    print_digit_word((int)(n % 10));
}

int main(void)
{
    long long n;
    printf("Enter an integer: ");
    if (scanf("%lld", &n) != 1) return 1;

    print_number_words(n);
    putchar('\n');
    return 0;
}