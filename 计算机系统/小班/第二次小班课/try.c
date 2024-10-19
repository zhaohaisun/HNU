#include <stdio.h>
int main()
{
	int a[5]={85,116,36,116,121};
	printf("%d\n", sizeof(int));
	printf("%s%s%s%s%s\n",&a[0],&a[1],&a[2],&a[3],&a[4]);
	return 0;
}
