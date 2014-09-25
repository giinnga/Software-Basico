.data
    sn: .string "\n"

.globl imprimir

imprimir:
    /* prologo */
    pushl %ebp
    movl  %esp, %ebp
    pushl %ebx

    /* coloque seu codigo aqui */

    movl  8(%ebp),  %ebx

L1:
    movsbl  (%ebx), %eax
    cmpl     $0, %eax
    jne     L2

    pushl   $sn
        call    printf
    add    $4, %esp

    popl    %ebx
    movl    %ebp, %esp
    popl    %ebp
    ret

L2:
    pushl   %eax
       call    putchar
    add    $4, %esp

    incl    %ebx
    jmp     L1


