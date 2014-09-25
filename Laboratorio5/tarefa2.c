#include <stdio.h>
#include <stdlib.h>

struct X {
  int a;
  int b;
  short c;
  int d;
} x = {0xa1a2a3a4, 0xb1b2b3b4, 0xc1c2, 0xd1d2d3d4};

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int main (void) {
	printf ("x: \n");
	dump (&x, sizeof(x));
	return 0;
}