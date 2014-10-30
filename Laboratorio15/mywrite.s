.text
.globl mywrite
mywrite:

	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx


	movl	8(%ebp),  %ebx
	movl	16(%ebp), %edx
	movl	12(%ebp), %ecx

	movl	$4, %eax
	int		$0x80

	popl	%ebx
	movl	%ebp, %esp
	popl	%ebp
	ret
