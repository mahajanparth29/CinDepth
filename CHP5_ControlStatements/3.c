#include<stdio.h>
int main()
{
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);
  int digit;
  printf("Enter a Digit to search: ");
  scanf("%d", &digit);
  int found = 0;
  while(num>0)
  {
    int temp = num%10;
    if(temp == digit)
    {
      found++;
    }
    num /= 10;
  }
  if(found)
  {
    printf("Digit %d found %d times\n", digit, found);
  }
  else
  {
    printf("Digit %d not found\n", digit);
  }
  return 0;
}