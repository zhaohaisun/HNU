#include <stdio.h>
#include <stdbool.h>

int A(int x) 
{
	return !(~x);
}


int B(int x) 
{
	return !x;
}

int C(int x) 
{
	return A(x | ~0xff); //��0xff ff ff 00λ���Ƿ�ȫ1
}

int D(int x) 
{
	return B((x>> ((sizeof(int) - 1) << 3))&0xff); //����24λ�۲��Ƿ�ȫ0
}

int main(){
	//test A
	int a0 = 0xffffffff;
	int a1 = 0xff;
	int a2 = 0xff002; 
	printf("x���κ�λ������1\n");
	printf("A(%#x):%d\n",a0, A(a0));   // %# �������ǰ׺ 
	printf("A(%#x):%d\n", a1, A(a1));
	printf("A(%#x):%d\n\n", a2, A(a2));
	//test B
	int b0 = 0x0;
	int b1 = 0x1;
	int b2 = 0xff;
	printf("x���κ�λ������0\n");
	printf("B(%#x):%d\n", b0, B(b0));
	printf("B(%#x):%d\n", b1, B(b1));
	printf("B(%#x):%d\n\n", b2, B(b2));
	//test C
	int c0 = 0x00ff;
	int c1 = 0x01234;
	int c2 = 0x012345ff;
	printf("x�������Ч�ֽ��е�λ������1\n");
	printf("C(%#x):%d\n", c0, C(c0));
	printf("C(%#x):%d\n", c1, C(c1));
	printf("C(%#x):%d\n\n", c2, C(c2));
	//test D
	int d0 = 0x00123456;
	int d1 = 0x12345678;
	int d2 = 0xff000000;
	printf("x�������Ч�ֽ��е�λ������0\n");
	printf("D(%#x):%d\n", d0, D(d0));
	printf("D(%#x):%d\n", d1, D(d1));
	printf("D(%#x):%d\n", d2, D(d2));
	return 0;
}
