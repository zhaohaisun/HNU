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
	//使用摩根定律 a&b=~(~a|~b)
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
	//第0个字节储存的是0x78...
	//n左移3位 扩大8倍
	//x右移3个字节 8bit
	//与&0xff相与，即可使前三个字节清零，而最后一个字节保持不变
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
	1.C语言默认用的是算术右移，算术右移是符号位(0/1)补位，而题目要求的是逻辑右移，逻辑右移是0补位。
	故可以先进行算术右移，然后将补位的数字(前n位)全部替换成0;
	2.替换可以使用掩码(参考函数2)。使其前n位为0，后(32-n)位为1；
	3.掩码的构造方法。
		a. 将1左移31位：1<<31; 10000000….
		b. 取反：~(1<<31) 0111111….
		c. 右移n位(符号位是0,0补位)：(~(1<<31))>>n 0000011111... (前面有n+1个0)
		d. 左移1位（注意：题目要求不能用减法，故不直接使用右移n-1位）：
		((~(1<<31))>>n)<<1    00001111...110 (前面有n个0)
		e. 和1相或以补最右边的0：(((~(1<<31))>>n)<<1) 00001111...111
	4.将右移n位后的x与掩码相与
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
	可用分治法来做
	求32位二进制数里有多少个1，可以先2位2位的看，再4位4位的看，再8位8位的看，再16位16位的看，最后看32位。
	举例说明：x=10110100（8位）
	第一步：shift_2-1=(10|11|01|00)&01010101=00010100
	X右移1位：shift_2-2=(01|01|10|10)&01010101=01010000
	Sum_2=shift_2-1+shift_2-2=00010100+01010000=01|10|01|00
	
	第二步：shift_4-1=（0110|0100）&00110011=0010|0000
	X右移2位：shift_4-2=（0001|1001）&00110011=0001|0001
	Sum_2=shift_4-1+shift_4-2=00100000+00010001=0011|0001
	
	第三步：shift_8-1=（00110001）&00001111=00000001
	X右移4位：（00000011）&00001111=00000011
	Sum_2=shift_2-1+shift_2-2=00000001+00000011=00000100
	即含有4个1
	因为实验要求中整数常数的范围是：0-255（0x0-0xff）
	故需要对掩码进行转换，这可以通过移位和或运算实现
	*/
	
	//构造掩码
	int m_1,m_2,m_4,m_8,m_16;
	m_1=0x55|(0x55<<8);//01010101=0x55
	m_1=m_1|(m_1<<16);//m_1=01010101 01010101 01010101 01010101
	m_2=0x33|(0x33<<8);//00110011=0x33
	m_2=m_2|(m_2<<16);//m_2=00110011 00110011 00110011 00110011
	m_4=0x0f|(0x0f<<8);//00001111=0x0f
	m_4=m_4|(m_4<<16);//m_4=00001111 00001111 00001111 00001111
	m_8=0xff|(0xff<<16);//11111111=0xff m_8=00000000 11111111 00000000 11111111
    m_16=0xff|(0xff<<8);//m_16=00000000 00000000 11111111 11111111
    
	x=(x&m_1)+((x>>1)&m_1);//m_1的最高位是0 因而算术右移对结果也无影响 
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
	//求反的过程实际就是判断x是否为0。x若为0，则!x为1，否则为0；
    //只有0的原码和补码的或的最高位为0，即转化为判断原补码或运算后的最高位是否为0的问题，而这可以用右移31位后&1来判断
    //~和！不同。~是按位求反；！是逻辑求反，其结果只有0或1
	int com=~x+1;//求补码
	return ~((com|x)>>31)&1; //只有0的原补码的或的最高位为0 (com|x)>>31为32个或的结果的最高位 
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
	//最小的二进制补码是10000000 00000000 00000000 00000000（负数）
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
	1.题目要求判断x能否用n位二进制数表示，而x肯定能用32位二进制数表示，可通过将32位二进制数左移(32-n)位
	再右移(32-n)位后的数是否还和原来相等来判断(由于补位原则，相当于只保留了n位有效数)
	2.因为题目不允许用-号，故可以用+上n的反码再+1的方式求差
	3.通过异或^来判断是否相等
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
	//正数：直接右移一位
    //负数：加上一个偏置位，避免向负取整的情况
    //如果x为正数，则直接右移n位，即偏移量为0；如果x为负数则需要加偏移量2*n-1之后再右移n位
    //C语言默认为算术右移 
	int sign,bias;	
	sign=x>>31;   //符号位 
	bias=sign&((1<<n)+(~0));   //偏置位 正数时为0 其中~0为-1
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
	//按位取反，末位加1
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
	//1.正数的符号位为0，负数的符号位为1，0的符号位为0
	//2.判断正数：符号位为0
	//3.判断！x ：!0=1 ！1=0 ！-1=1
	//4.x|0=x,x|1=1;
	//5.x==0时，000...000|1!=0
	  //x>0时，000...000|0==0
	  //x<0时，111...111|0!=0 
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
	//要判断x<=y通常我们都会想到用y-x>=0来判断，这时候就碰到了一个问题，如果x与y异号且x为负时会发生溢出
	//因此分情况讨论，如果x与y同号的话，看y-x的符号位（进行符号扩展右移31位）
	//如果x与y异号的话，之需要根据x来判断，若x的符号位为1则y>=x
	int signx=(x>>31) & 0x1;	//求得x的符号位
	int signy=(y>>31) & 0x1;	//求得y的符号位
	int is_notSame=(signx ^ signy);	//判断x、y是否异号，进行异或操作，如果结果为1则异号，否则同号
	int tmp=((y+(~x)+1)>>31) &0x1;	//x与y同号时进行减法操作之后得到结果的符号位
	return (((!tmp) & (!is_notSame))|(is_notSame & signx));//同号则tmp为0(相减结果>=0) 异号则signx为1 
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
	//要求以2为底，x的对数，只需要知道最高的1在哪一位即可
    //采用二分法，第一次右移16位，判断结果是否大于0，进行两次!! 变为0/1之后左移4位
   //第二次右移8+bitsNumber位，判断结果是否大于零，进行两次!! 变为0/1之后左移3位
   //依次分下去
   //!为算数运算符 返回结果为0或1 
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
	1.题目翻译：题目的要求就是更改一下浮点数的符号位，特别需要注意的是当参数为NaN的时候返回参数本身
	2.IEEE浮点表示（32bits）：
	|s (符号位，1位) |exp（阶码，8位）| Frac（尾码，23位）|
	3.通过判断exp是否为11111111，frac是否不等于000…来判断参数是否为NaN(不是一个数)
	4.通过^改变符号位
	5.exp的几种特殊情况
	exp=00000000:阶码E=-Bias+1; 尾数M=0.xxx…
	exp=11111111,frac=000…0:s=1时表示负无穷s=0时表示正无穷
	exp=11111111,frac！=000…0:NaN 一些无法表示的数 
	*/
	int exp=((uf<<1)>>24)&0xff;//左移一位以去除符号位
	if(exp==0xff)
	{
		if(uf<<1!=0xff000000) return uf;
	}
	return uf^(1<<31);//和0异或不变 和1异或取反 
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
	1.题目要求将整数表示为浮点数（IEEE），需要分为三个部分来处理：符号位、阶码、尾码
	2.如果参数为0，直接返回0
	3.如果参数为负数，因为负数在内存中是以补码形式保存的，而输出要求是无符号数，故需要先转换为其绝对值
	4.使用无符号数的原因：无符号数算术左移补0
	5.符号位：直接将最高位&（1<<31）
	6.尾码：先左移使其最高位为1，并记录移位个数shift_count（以此计算阶码）,再左移移位舍弃最高位，最后右移9位并采用向偶数舍入得到尾码
	7.阶码：E=32-shift_count-1 EXP=127+E=159- shift_count
	*/
	unsigned sign,shift_count,tail,rank,flag,temp;
	if(!x) return 0; //参数为0直接返回0
	sign=x&(1<<31);  //取得符号位
	if(sign) x=-x; //参数为负数则转化为其绝对值
	shift_count=0;
	tail=x;
	while(1)
	{
		temp=tail;
		tail<<=1;  //tail多左移一次，最终保存的是去除首位1后的数
		shift_count++;
		if(temp&0x80000000) break; //temp最终保存的是最高位为1的数
	}
	
	if((tail&0x01ff)>0x0100) flag=1;//大于中间时 
	else if((tail&0x03ff)==0x0300) flag=1;//等于中间时向零舍入 
	else flag=0;
	tail=(tail>>9)+flag;//尾数+向进位标识符flag 
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
	//如果阶码为0，那么就是非规格数，直接将尾数左移1位到阶码域上，其他不变即可
    //例如 0 00000000 1000…001 变成 0 00000001 000…0010
    //这样可以做的原因正是由于非规格化数的指数E = 1 - bias，而不是-bias
    //这样使得可以平滑地从非规格数过渡到规格化数。 
    //如果阶码不为0且不是255，那么直接阶码加1即可。 
    //如果阶码为255，那么是NaN，∞，-∞，直接返回。
	if((uf & 0x7F800000)==0)//阶码全为0 
	uf = (uf<<1)|(uf & 0x80000000);//保证符号位不变 
	else if((uf & 0x7F800000)!=0x7F800000)//阶码不全为1 直接阶码加1
	uf = uf + 0x00800000;
	return uf;
}
