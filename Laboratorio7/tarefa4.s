.data

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

	movl $0, %ebx

	L1:
		cmpl $11, %ebx
		jne 	L2
		/*pushl	%ecx
		pushl	$Sn
		call printf*/
		popl	%ebx
		movl    %ebp, %esp
		popl    %ebp
		ret		

	L2:
		movl	%ebx, %eax
		imull	%eax
		pushl	%eax
		pushl	$Sf
		call printf
		addl $1, %ebx
		jmp 	L1


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