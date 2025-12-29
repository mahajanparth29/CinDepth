#include <stdio.h>


char to_upper(char c)
{
    if (c >= 'a' && c <= 'z') return (char)(c - ('a' - 'A'));
    return c;
}

int main(void)
{
    char ch;
    printf("Enter a character: ");
    if (scanf(" %c", &ch) != 1) return 1;
    printf("Uppercase: %c\n", to_upper(ch));
    return 0;
}
