.data

	s1:		.string		"numero "
	s2:		.string		"%d"

.text
.globl novonum
novonum:

	pushl	%ebp
	movl	%esp,	%ebp
	pushl	%ebx

	subl	$4,		%esp
	movl	-4(%ebp),	%ebx

	pushl	$s1
	call	printf
	addl	$4,		%esp

	pushl	%ebx
	pushl	$s2
	call	scanf
	addl	$8,		%esp

	movl	(%ebx),	%eax

	popl	%ebx
	movl	%ebp,	%esp
	popl	%ebp
	ret

