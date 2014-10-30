.text
.globl myread
myread:

	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx


	movl	8(%ebp),  %ebx
	movl	12(%ebp), %ecx
	movl	%edx, tamBufferAberto

	movl	$3, %eax
	int		$0x80

	popl	%ebx
	movl	%ebp, %esp
	popl	%ebp
	ret
