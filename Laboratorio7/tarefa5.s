.data

	Si: .int 65, -105, 111, 34
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

	movl $Si, %ebx
	movl $0, %ecx
	movl $0, %edx

	L1:
		movl (%ebx), %eax
		cmpl $4, %edx
		jne 	L2
		pushl	%ecx
		pushl	$Sf
		call printf
		addl	$8, %esp
		/*pushl	%ecx
		pushl	$Sn
		call printf*/
		popl	%ebx
		movl    %ebp, %esp
		popl    %ebp
		ret		

	L2:
		addl	%eax, %ecx
		addl	$4, %ebx
		incl	%edx
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