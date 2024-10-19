#include <stdio.h>
int compare(int a, int b)
{
   if(a>=b)return 1;
   else return 0;
}
int main()
{
  int x=1,y=1;
  int sum,sub,mul;
  int i=4;
  for(i=4;i>0;i--)
  {
     x=x+i;
     y=y*i;
  }
  sum=x+y;
  mul=x*y;
  if(compare(sum,mul))sub=sum-mul;
  else sub=mul-sum;
  printf("%d\n",sub);
  return 0;
}

