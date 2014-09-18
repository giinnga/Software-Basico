 .data
  nums: .int 3, -5, 7, 8, -2
  s1:   .string "%d\n"

  .text
  .globl main
  main:
  /* prologo */

     pushl %ebp
     movl  %esp, %ebp
      pushl %ebx 

  /* coloque seu codigo aqui */

    movl  $nums, %ebx
    movl  $0, %edx

  L1:
      movl (%ebx), %eax
      cmpl  $5, %edx
      jne L2
      popl %ebx
      movl %ebp, %esp
      popl %ebp

      ret

  L2:
      pushl %edx
      pushl $1
      pushl %eax
      call  filtro
      addl  $8, %esp
      popl  %edx

      pushl %edx
      pushl  %eax
      pushl  $s1
      call  printf
      addl  $8, %esp
      popl  %edx
     
      addl  $4, %ebx
      incl  %edx
      jmp   L1


  /* finalizacao */

