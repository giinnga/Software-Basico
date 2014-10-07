.globl	bemboba
bemboba:

	pushl	%ebp
	movl	%esp,	%ebp
	pushl	%ebx

	subl	$16,	%esp
	movl	-4(%ebp),	%ebx
	movl	(%ebx),		%ecx
	movl	-16(%ebp),	%ebx /* a = local[0] */
	movl	(%ebx),		%eax
	movl	$0,		%edx
	movl	4(%ebp),	%ecx /* ecx = num */

L1:
	movl	(%ebx),	%eax
	cmpl	$3,		%edx
	je		L2
	movl	%ecx,	%eax
	addl	$4,		%ebx
	incl	%edx
	jmp		L1

L2:
	pushl	$3
	pushl	%eax
	call	addl
	addl	$8,		%esp

	popl	%ebx
	movl	%ebp,	%esp
	popl	%ebp
	ret

