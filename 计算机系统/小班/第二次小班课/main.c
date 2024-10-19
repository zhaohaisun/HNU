#include <stdio.h>
#include <math.h>

int main()
{
  double a,b,c,disc,x1,x2,realpart,imagpart;
  printf("请输入方程系数并且以空格作为分隔符： ");
  scanf("%lf %lf %lf",&a,&b,&c);
  if(fabs(a)<=1e-6)
    printf("不是一元二次方程。\n");
  else
  {
    disc=b*b-4*a*c;   //定义判别式
    if(fabs(disc)<=1e-6)   //如果判别式小于0
      printf("有两个相同的实根:%8.4f\n",-b/(2*a));
    else
      if(disc>1e-6)
	  {
       x1=(-b+sqrt(disc))/(2*a);
       x2=(-b-sqrt(disc))/(2*a);
       printf("有两个不同的实根:%8.4f and %8.4f\n",x1,x2);
	  }
      else
	  {
       realpart=-b/(2*a);
       imagpart=sqrt(-disc)/(2*a);
       printf(" 有两个复根1:\n");
       printf("%8.4f+%8.4fi\n",realpart,imagpart);
       printf("%8.4f-%8.4fi\n",realpart,imagpart);
	  }
  }
  return 0;
}  
