.globl add

add:
    /* prologo */
    pushl %ebp
    movl  %esp, %ebp
    pushl %ebx

    /* coloque seu codigo aqui */

    movl  8(%ebp),  %ebx /* ebx = struct X *x */
    movl  $0,   %eax /* eax = 0 */

L1:
    movl    (%ebx), %ecx
    cmpl    $0, 4(%ebx)
    jne     L2

    popl    %ebx
    movl    %ebp, %esp
    popl    %ebp
    ret

L2:
    addl    %ecx,   %eax
    addl    $8, %ebx
    jmp     L1


