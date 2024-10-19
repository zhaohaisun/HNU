/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
	//ʹ��Ħ������ a&b=~(~a|~b)
	return ~(~x|~y);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
	//��0���ֽڴ������0x78...
	//n����3λ ����8��
	//x����3���ֽ� 8bit
	//��&0xff���룬����ʹǰ�����ֽ����㣬�����һ���ֽڱ��ֲ���
	return (x>>(n<<3)) & 0xFF;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
	/*
	1.C����Ĭ���õ����������ƣ����������Ƿ���λ(0/1)��λ������ĿҪ������߼����ƣ��߼�������0��λ��
	�ʿ����Ƚ����������ƣ�Ȼ�󽫲�λ������(ǰnλ)ȫ���滻��0;
	2.�滻����ʹ������(�ο�����2)��ʹ��ǰnλΪ0����(32-n)λΪ1��
	3.����Ĺ��췽����
		a. ��1����31λ��1<<31; 10000000��.
		b. ȡ����~(1<<31) 0111111��.
		c. ����nλ(����λ��0,0��λ)��(~(1<<31))>>n 0000011111... (ǰ����n+1��0)
		d. ����1λ��ע�⣺��ĿҪ�����ü������ʲ�ֱ��ʹ������n-1λ����
		((~(1<<31))>>n)<<1    00001111...110 (ǰ����n��0)
		e. ��1����Բ����ұߵ�0��(((~(1<<31))>>n)<<1) 00001111...111
	4.������nλ���x����������
	*/ 
	int mask_code=(((~(1<<31))>>n)<<1)|1;
	return (x>>n)&mask_code;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
	/*
	���÷��η�����
	��32λ�����������ж��ٸ�1��������2λ2λ�Ŀ�����4λ4λ�Ŀ�����8λ8λ�Ŀ�����16λ16λ�Ŀ������32λ��
	����˵����x=10110100��8λ��
	��һ����shift_2-1=(10|11|01|00)&01010101=00010100
	X����1λ��shift_2-2=(01|01|10|10)&01010101=01010000
	Sum_2=shift_2-1+shift_2-2=00010100+01010000=01|10|01|00
	
	�ڶ�����shift_4-1=��0110|0100��&00110011=0010|0000
	X����2λ��shift_4-2=��0001|1001��&00110011=0001|0001
	Sum_2=shift_4-1+shift_4-2=00100000+00010001=0011|0001
	
	��������shift_8-1=��00110001��&00001111=00000001
	X����4λ����00000011��&00001111=00000011
	Sum_2=shift_2-1+shift_2-2=00000001+00000011=00000100
	������4��1
	��Ϊʵ��Ҫ�������������ķ�Χ�ǣ�0-255��0x0-0xff��
	����Ҫ���������ת���������ͨ����λ�ͻ�����ʵ��
	*/
	
	//��������
	int m_1,m_2,m_4,m_8,m_16;
	m_1=0x55|(0x55<<8);//01010101=0x55
	m_1=m_1|(m_1<<16);//m_1=01010101 01010101 01010101 01010101
	m_2=0x33|(0x33<<8);//00110011=0x33
	m_2=m_2|(m_2<<16);//m_2=00110011 00110011 00110011 00110011
	m_4=0x0f|(0x0f<<8);//00001111=0x0f
	m_4=m_4|(m_4<<16);//m_4=00001111 00001111 00001111 00001111
	m_8=0xff|(0xff<<16);//11111111=0xff m_8=00000000 11111111 00000000 11111111
    m_16=0xff|(0xff<<8);//m_16=00000000 00000000 11111111 11111111
    
	x=(x&m_1)+((x>>1)&m_1);//m_1�����λ��0 ����������ƶԽ��Ҳ��Ӱ�� 
	x=(x&m_2)+((x>>2)&m_2);
	x=(x&m_4)+((x>>4)&m_4);
	x=(x&m_8)+((x>>8)&m_8);
	x=(x&m_16)+((x>>16)&m_16);
	return x;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
	//�󷴵Ĺ���ʵ�ʾ����ж�x�Ƿ�Ϊ0��x��Ϊ0����!xΪ1������Ϊ0��
    //ֻ��0��ԭ��Ͳ���Ļ�����λΪ0����ת��Ϊ�ж�ԭ��������������λ�Ƿ�Ϊ0�����⣬�������������31λ��&1���ж�
    //~�ͣ���ͬ��~�ǰ�λ�󷴣������߼��󷴣�����ֻ��0��1
	int com=~x+1;//����
	return ~((com|x)>>31)&1; //ֻ��0��ԭ����Ļ�����λΪ0 (com|x)>>31Ϊ32����Ľ�������λ 
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
	//��С�Ķ����Ʋ�����10000000 00000000 00000000 00000000��������
	return 1<<31;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
	/*
	1.��ĿҪ���ж�x�ܷ���nλ����������ʾ����x�϶�����32λ����������ʾ����ͨ����32λ������������(32-n)λ
	������(32-n)λ������Ƿ񻹺�ԭ��������ж�(���ڲ�λԭ���൱��ֻ������nλ��Ч��)
	2.��Ϊ��Ŀ��������-�ţ��ʿ�����+��n�ķ�����+1�ķ�ʽ���
	3.ͨ�����^���ж��Ƿ����
	*/
	int count=32+(~n)+1;
	return !(x^(x<<count>>count));
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
	//������ֱ������һλ
    //����������һ��ƫ��λ��������ȡ�������
    //���xΪ��������ֱ������nλ����ƫ����Ϊ0�����xΪ��������Ҫ��ƫ����2*n-1֮��������nλ
    //C����Ĭ��Ϊ�������� 
	int sign,bias;	
	sign=x>>31;   //����λ 
	bias=sign&((1<<n)+(~0));   //ƫ��λ ����ʱΪ0 ����~0Ϊ-1
	return (x+bias)>>n;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
	//��λȡ����ĩλ��1
	return (~x)+1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
	//1.�����ķ���λΪ0�������ķ���λΪ1��0�ķ���λΪ0
	//2.�ж�����������λΪ0
	//3.�жϣ�x ��!0=1 ��1=0 ��-1=1
	//4.x|0=x,x|1=1;
	//5.x==0ʱ��000...000|1!=0
	  //x>0ʱ��000...000|0==0
	  //x<0ʱ��111...111|0!=0 
	return !((x>>31)|(!x));
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	//Ҫ�ж�x<=yͨ�����Ƕ����뵽��y-x>=0���жϣ���ʱ���������һ�����⣬���x��y�����xΪ��ʱ�ᷢ�����
	//��˷�������ۣ����x��yͬ�ŵĻ�����y-x�ķ���λ�����з�����չ����31λ��
	//���x��y��ŵĻ���֮��Ҫ����x���жϣ���x�ķ���λΪ1��y>=x
	int signx=(x>>31) & 0x1;	//���x�ķ���λ
	int signy=(y>>31) & 0x1;	//���y�ķ���λ
	int is_notSame=(signx ^ signy);	//�ж�x��y�Ƿ���ţ�������������������Ϊ1����ţ�����ͬ��
	int tmp=((y+(~x)+1)>>31) &0x1;	//x��yͬ��ʱ���м�������֮��õ�����ķ���λ
	return (((!tmp) & (!is_notSame))|(is_notSame & signx));//ͬ����tmpΪ0(������>=0) �����signxΪ1 
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
	//Ҫ����2Ϊ�ף�x�Ķ�����ֻ��Ҫ֪����ߵ�1����һλ����
    //���ö��ַ�����һ������16λ���жϽ���Ƿ����0����������!! ��Ϊ0/1֮������4λ
   //�ڶ�������8+bitsNumberλ���жϽ���Ƿ�����㣬��������!! ��Ϊ0/1֮������3λ
   //���η���ȥ
   //!Ϊ��������� ���ؽ��Ϊ0��1 
   int bitsNumber;
   bitsNumber = (!!(x>>16)) << 4;
   bitsNumber = bitsNumber + ((!!(x >> (bitsNumber + 8))) << 3);
   bitsNumber = bitsNumber + ((!!(x >> (bitsNumber + 4))) << 2);
   bitsNumber = bitsNumber + ((!!(x >> (bitsNumber + 2))) << 1);
   bitsNumber = bitsNumber + ( !!(x >> (bitsNumber + 1)));
   return bitsNumber;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
	/*
	1.��Ŀ���룺��Ŀ��Ҫ����Ǹ���һ�¸������ķ���λ���ر���Ҫע����ǵ�����ΪNaN��ʱ�򷵻ز�������
	2.IEEE�����ʾ��32bits����
	|s (����λ��1λ) |exp�����룬8λ��| Frac��β�룬23λ��|
	3.ͨ���ж�exp�Ƿ�Ϊ11111111��frac�Ƿ񲻵���000�����жϲ����Ƿ�ΪNaN(����һ����)
	4.ͨ��^�ı����λ
	5.exp�ļ����������
	exp=00000000:����E=-Bias+1; β��M=0.xxx��
	exp=11111111,frac=000��0:s=1ʱ��ʾ������s=0ʱ��ʾ������
	exp=11111111,frac��=000��0:NaN һЩ�޷���ʾ���� 
	*/
	int exp=((uf<<1)>>24)&0xff;//����һλ��ȥ������λ
	if(exp==0xff)
	{
		if(uf<<1!=0xff000000) return uf;
	}
	return uf^(1<<31);//��0��򲻱� ��1���ȡ�� 
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
	/*
	1.��ĿҪ��������ʾΪ��������IEEE������Ҫ��Ϊ������������������λ�����롢β��
	2.�������Ϊ0��ֱ�ӷ���0
	3.�������Ϊ��������Ϊ�������ڴ������Բ�����ʽ����ģ������Ҫ�����޷�����������Ҫ��ת��Ϊ�����ֵ
	4.ʹ���޷�������ԭ���޷������������Ʋ�0
	5.����λ��ֱ�ӽ����λ&��1<<31��
	6.β�룺������ʹ�����λΪ1������¼��λ����shift_count���Դ˼�����룩,��������λ�������λ���������9λ��������ż������õ�β��
	7.���룺E=32-shift_count-1 EXP=127+E=159- shift_count
	*/
	unsigned sign,shift_count,tail,rank,flag,temp;
	if(!x) return 0; //����Ϊ0ֱ�ӷ���0
	sign=x&(1<<31);  //ȡ�÷���λ
	if(sign) x=-x; //����Ϊ������ת��Ϊ�����ֵ
	shift_count=0;
	tail=x;
	while(1)
	{
		temp=tail;
		tail<<=1;  //tail������һ�Σ����ձ������ȥ����λ1�����
		shift_count++;
		if(temp&0x80000000) break; //temp���ձ���������λΪ1����
	}
	
	if((tail&0x01ff)>0x0100) flag=1;//�����м�ʱ 
	else if((tail&0x03ff)==0x0300) flag=1;//�����м�ʱ�������� 
	else flag=0;
	tail=(tail>>9)+flag;//β��+���λ��ʶ��flag 
	rank=(127+32-shift_count)<<23;
	return sign+rank+tail;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
	//�������Ϊ0����ô���Ƿǹ������ֱ�ӽ�β������1λ���������ϣ��������伴��
    //���� 0 00000000 1000��001 ��� 0 00000001 000��0010
    //������������ԭ���������ڷǹ������ָ��E = 1 - bias��������-bias
    //����ʹ�ÿ���ƽ���شӷǹ�������ɵ�������� 
    //������벻Ϊ0�Ҳ���255����ôֱ�ӽ����1���ɡ� 
    //�������Ϊ255����ô��NaN���ޣ�-�ޣ�ֱ�ӷ��ء�
	if((uf & 0x7F800000)==0)//����ȫΪ0 
	uf = (uf<<1)|(uf & 0x80000000);//��֤����λ���� 
	else if((uf & 0x7F800000)!=0x7F800000)//���벻ȫΪ1 ֱ�ӽ����1
	uf = uf + 0x00800000;
	return uf;
}
