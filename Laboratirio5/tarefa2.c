#include <stdio.h>

typedef struct X {
  int a;
  int b;
  short c;
  int d;
} x;

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int main (void) {

	printf ("b: \n");
	dump (b, sizeof(b));
	printf ("a: \n");
	dump (a, sizeof(a));
	return 0;
}