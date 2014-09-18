.globl add1
add1:
  /* prologo */
	pushl %ebp
	movl  %esp, %ebp
	pushl %ebx

  /* coloque seu codigo aqui */

	movl	$0, %edx /* edx = 0 */
	movl	$0, %ecx /* ecx = 0 */
	movl	8(%ebp), %ebx

L1:
	movl	(%ebx), %eax
	cmpl	%ecx, 12(%ebp)
	jne	L2
	popl %ebx
	movl %ebp, %esp
	popl %ebp
	ret


L2:
	addl	%eax, %edx
	addl	$4, %ebx
	incl	%ecx
	jmp	L1

