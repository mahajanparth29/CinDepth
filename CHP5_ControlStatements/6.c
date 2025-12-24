#include<stdio.h>
int main()
{
  int num;
  printf("Enter a six digit number: ");
  scanf("%d", &num);
  int sum=0, mul=1;
  int count=1;
  while(num>0)
  {
    int temp = num%10;
    if(count==1)
    {
      sum=sum+temp;
      count=0;
    }
    else
    {
      count=1;
      mul=mul*temp;
    }
    num /= 10;
  }
  printf("Sum = %d, Product = %d\n", sum, mul);
  return 0;
}