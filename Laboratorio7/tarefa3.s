.data

	S2: .byte 65, 108, 111, 32, 123, 103, 97, 108, 101, 114, 97, 125, 33, 0
	Sf: .string "%d\n"
	Sn: .string "\n"

.text
.globl	main
main:
/****** nao mexa - prologo !!!! */
    push    %ebp
    movl    %esp, %ebp
	pushl	%ebx		/* salva ebx */
/*******/


	movl $S2, %ebx /*ebx = S2*/
	movl $0, %ecx


	L1:
		movsbl (%ebx), %eax
		cmpl $0, %eax
		jne 	L2
		pushl	%ecx
		pushl	$Sf
		call printf
		popl	%ebx		
		movl    %ebp, %esp
		popl    %ebp
		ret		

	L2:
		incl	%ebx
		incl	%ecx
		jne 	L1


/****** nao mexa - imprime o valor de %eax !!!! */
/* pode estragar o valor de %eax           ******/
/*	pushl   %ecx
	pushl   %edx
	pushl   %eax
	pushl   $Sf
 	call	printf	
	addl    $8, %esp
	popl   %edx
	popl   %ecx*/
/*******/

/****** nao mexa - finalizacao!!!! */
	/*popl	%ebx		
	movl    %ebp, %esp
	popl    %ebp
	ret	*/		
/*******/