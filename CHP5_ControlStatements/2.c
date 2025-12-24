#include <stdio.h>
int main()
{
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  int reverse = 0;
  while(num>0)
  {
    int temp = num%10;
    reverse = reverse * 10 + temp;
    num /= 10;
  }
  printf("Reversed number: %d\n", reverse);
  return 0;
}