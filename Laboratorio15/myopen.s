.text
.globl myopen
myopen:

	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx


	movl	8(%ebp),  %ebx
	movl	%edx, tamBufferAberto

	movl	16(%ebp), %edx
	movl	12(%ebp), %ecx

	movl	$5, %eax
	int		$0x80

	popl	%ebx
	movl	%ebp, %esp
	popl	%ebp
	ret
