.globl foo
foo:
  /* prologo */
	pushl %ebp
	movl  %esp, %ebp
	pushl %ebx

  /* coloque seu codigo aqui */

	movl	$0, %edx /* edx = 0 */
	movl	$0, %eax /* eax = 0 */
	movl	12(%ebp), %ecx /* ecx = int n */
	movl	8(%ebp), %ebx /* ebx = int a[] */

L1:
	
	cmpl	%edx, %ecx /* if (edx == n) */
	jne		L2

	popl	%ebx
	movl	%ebp, %esp
	popl	%ebp
	ret


L2:
	addl	(%ebx), %eax /* eax += ecx++ */
	cmpl	$0, (%ebx)
	je 		L3
	incl	%edx /* incrementa contador */
	addl	$4, (%ebx)
	jmp	L1

L3:
	movl	%eax, (%ebx)
	movl	$0, %eax
	incl	%edx /* incrementa contador */
	addl	$4, (%ebx)
	jmp		L1

