typedef unsigned packed_t;

/* extrai byte de palavra e retorna inteiro (32 bits) com
sinal */
int xbyte (packed_t word, int bytenum);

/*Use seus conhecimentos de aritmética de complemento a 2 e
shifts à direita para implementar essa função. Teste-a com o
programa abaixo (leia até o final da questão!):*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned packed_t;

int string2num (char *s, int base) {
  int a = 0;
  for (; *s; s++) {
    if(isdigit(*s))
      a = a*base + (*s - '0');
    else if((*s >= 'A') && (*s < (base-10+'A')))
      a = a*base + ((*s - 'A') + 10);
    else if((*s >= 'a') && (*s < (base-10+'a')))
      a = a*base + ((*s - 'a') + 10);
    else {
      printf("pane: numero invalido! \n");
      exit(1);
    }
  }
  return a;
}

int xbyte (packed_t word, int bytenum) {
  if(bytenum == 0){
    word = word & 0x000000FF;
    word = word << 12;
    word = word >> 12;
    return word;
  }
  else  if(bytenum == 1){
    word = word & 0x0000FF00;
    word = word << 8;
    word = word >> 12;
    return word;
  }
  else  if(bytenum == 2){
    word = word & 0x00FF0000;
    word = word << 4;
    word = word >> 12;
    return word;
  }
  else  if(bytenum == 3){
    word = word & 0xFF000000;
    word = word >> 12;
    return word;
  }
  return 1;
}

int main (int argc, char **argv) {
  int x;
  if (argc != 3) {
    printf("uso: %s <word (em hexadecimal)> <bytenum>\n", argv[0]);
    exit(1);
  }

  x = xbyte(string2num(argv[1], 16), atoi(argv[2]));
  printf ("%08x  %d\n", x, x);
  return 0;
}
