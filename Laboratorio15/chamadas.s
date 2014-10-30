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
