#include <stdio.h>
int main()
{
  for (int i = 2; i <= 99; i++)
  {
    int isPrime = 1;
    for (int j = 2; j * j <= i; j++)
    {
      if (i % j == 0)
      {
        isPrime = 0;
        break;
      }
    }
    if (isPrime)
    {
      printf("%d is prime\n", i);
    }
  }
  return 0;
}