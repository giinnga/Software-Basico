.globl add1
add1:
  /* prologo */
	pushl %ebp
	movl  %esp, %ebp
	pushl %ebx

  /* coloque seu codigo aqui */

	movl	$0, %edx /* edx = 0 */
	movl	12(%ebp), %ecx /* ecx = int n */
	movl	8(%ebp), %ebx /* ebx = int *a */
	movl	$0, %eax /* eax = 0 */

L1:
	
	cmpl	%edx, %ecx /* if (edx == n) */
	jne		L2

	popl	%ebx
	movl	%ebp, %esp
	popl	%ebp
	ret


L2:
	addl	(%ebx), %eax /* eax += ecx++ */
	incl	%edx /* incrementa contador */
	incl	(%ebx)
	jmp	L1

