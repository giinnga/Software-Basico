.data
    s1: .string "%c"
    sn: .string "\n"

.globl putchar

putchar:
    /* prologo */
    pushl %ebp
    movl  %esp, %ebp
    pushl %ebx

    /* coloque seu codigo aqui */

    movl  8(%ebp),  %ebx

L1:
    movl  %ebx, %eax
    cmp   $0, %eax
    jne   L2

    popl %ebx
    movl %ebp, %esp
    popl %ebp
    ret

L2:
    pushl %eax
    pushl $s1
    call  printf
    incl  (%ebx)

