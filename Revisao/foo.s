.globl foo
foo:

	pushl	%ebp
	movl	%esp,	%ebp

	fildl	16(%ebp)
	fldl	8(%ebp)

	fmulp

	fchs

	movl	%ebp,	%esp
	popl	%ebp
	ret
