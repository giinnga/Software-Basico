#include <stdio.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %x\n", p1, *p1);
    p1++;
  }
}

int main (void) {
  char c = 150; // signed = 1001 0110 -> unsigned 0110 1010 = 0x6A
  short s = -3; // 2¹⁶-3 = 65533 -> 0x0FFFD
  int i = -151; // 2³²-151 = 4294967145 -> 0xFFFFFF69
  printf("dump de c: \n");
  dump(&c, sizeof(c));
  printf("dump de s: \n");
  dump(&s, sizeof(s));
  printf("dump de i: \n");
  dump(&i, sizeof(i));
  return 0;
}