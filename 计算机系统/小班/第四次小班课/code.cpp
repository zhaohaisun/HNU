请参照汇编代码将如下的c语言程序补充完整：
#include "stdio.h"
#include "stdlib.h"

int main()
{
	int a[]={3,-5,6,7,2,-8,10,2,4};
	struct link
	{
		int i;
		struct link * next;
		struct link * pre;
	}head,*p1,*p2;
	head.i=a[0];
	head.next=NULL;
	head.pre=NULL;
	int j=0;
	p1=&head;
	for(j=1;j<=8;j++)
	{
		p2=(struct link*)malloc(sizeof(head));
		p2->i=j*a[j];
		p1->next=p2;
		p2->next=NULL;
		p2->pre=p1;
		p1=p2;
	}
	p1=&head;
	while(p1->next)
	{
		if()  
			p1->i+=p1->next->i;
		else
		  	p1->i-=p1->next->i;
		printf("%d\n",p1->i);
		p1=p1->next;	
	}
	return 0;
}

编译后的汇编代码如下：

main:
  	汇编代码                  实际操作              对应的C代码 
	pushl	%ebp              将old ebp入栈 
	movl	%esp, %ebp        ebp=esp 
	andl	$-16, %esp        将esp的最后4位清零 
	subl	$80, %esp         esp-=80 
	
	movl	$3, 20(%esp)      M(esp+20)=3=a[0]      int a[]={3,-5,6,7,2,-8,10,2,4};
	movl	$-5, 24(%esp)     M(esp+24)=-5=a[1]
	movl	$6, 28(%esp)      M(esp+28)=6=a[2]
	movl	$7, 32(%esp)      M(esp+32)=7=a[3]
	movl	$2, 36(%esp)      M(esp+36)=2=a[4]
	movl	$-8, 40(%esp)     M(esp+40)=-8=a[5]
	movl	$10, 44(%esp)     M(esp+44)=10=a[6]
	movl	$2, 48(%esp)      M(esp+48)=2=a[7]
	movl	$4, 52(%esp)      M(esp+52)=4=a[8]
	
  	汇编代码                  实际操作              对应的C代码 
	movl	20(%esp), %eax    eax=M(esp+20)=3=a[0]
	movl	%eax, 56(%esp)    M(esp+56)=eax=3=a[0]  head.i=a[0];
	
	movl	$0, 60(%esp)      M(esp+60)=0           head.next=NULL;
	movl	$0, 64(%esp)      M(esp+64)=0           head.pre=NULL;
	movl	$0, 72(%esp)      M(esp+72)=0=j         int j=0;
	
	leal	56(%esp), %eax    eax=esp+56 
	movl	%eax, 68(%esp)    M(esp+68)=esp+56      p1=&head;
	
	movl	$1, 72(%esp)      M(esp+72)=j=1         j=1
	
	jmp	.L2
.L3:
	movl	$12, (%esp)
	call	malloc
	movl	%eax, 76(%esp)
	movl	72(%esp), %eax
	movl	20(%esp,%eax,4), %eax
	movl	%eax, %edx
	imull	72(%esp), %edx
	movl	76(%esp), %eax
	movl	%edx, (%eax)
	movl	68(%esp), %eax
	movl	76(%esp), %edx
	movl	%edx, 4(%eax)
	movl	76(%esp), %eax
	movl	$0, 4(%eax)
	movl	76(%esp), %eax
	movl	68(%esp), %edx
	movl	%edx, 8(%eax)
	movl	76(%esp), %eax
	movl	%eax, 68(%esp)
	addl	$1, 72(%esp)
.L2:
	cmpl	$8, 72(%esp)
	jle	.L3
	leal	56(%esp), %eax
	movl	%eax, 68(%esp)
	jmp	.L4
.L7:
	movl	68(%esp), %eax
	movl	(%eax), %edx
	movl	68(%esp), %eax
	movl	4(%eax), %eax
	movl	(%eax), %eax
	leal	(%edx,%eax), %ecx
	movl	68(%esp), %eax
	movl	(%eax), %edx
	movl	68(%esp), %eax
	movl	4(%eax), %eax
	movl	(%eax), %eax
	imull	%edx, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	cmpl	%eax, %ecx
	jle	.L5
	movl	68(%esp), %eax
	movl	(%eax), %edx
	movl	68(%esp), %eax
	movl	4(%eax), %eax
	movl	(%eax), %eax
	addl	%eax, %edx
	movl	68(%esp), %eax
	movl	%edx, (%eax)
	jmp	.L6
.L5:
	movl	68(%esp), %eax
	movl	(%eax), %edx
	movl	68(%esp), %eax
	movl	4(%eax), %eax
	movl	(%eax), %eax
	subl	%eax, %edx
	movl	68(%esp), %eax
	movl	%edx, (%eax)
.L6:
	movl	68(%esp), %eax
	movl	(%eax), %edx
	movl	$.LC0, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	68(%esp), %eax
	movl	4(%eax), %eax
	movl	%eax, 68(%esp)
.L4:
	movl	68(%esp), %eax
	movl	4(%eax), %eax
	testl	%eax, %eax
	jne	.L7
	movl	$0, %eax
	leave
	ret

