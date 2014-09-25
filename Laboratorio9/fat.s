.globl fat
fat:
  /* prologo */
	pushl %ebp
	movl  %esp, %ebp
	pushl %ebx

  /* coloque seu codigo aqui */

  	movl	$0, %ecx
	movl	8(%ebp), %ebx
	movl	%ebx, %eax

L1:
	/*movl	(%ebx), %eax*/

	mul	%eax
	cmpl	$0, %eax
	jne	L2

	popl	%ebx
	movl	%ebp, %esp
	popl	%ebp
	ret


L2:
	movl	%eax, %ecx
	subl	$1, %eax
	mul		%eax
	jmp	L1

