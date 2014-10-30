.text
.globl myclose
myclose:

	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx


	movl	8(%ebp),  %ebx

	movl	$6, %eax
	int		$0x80

	popl	%ebx
	movl	%ebp, %esp
	popl	%ebp
	ret
