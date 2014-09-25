#include <stdio.h>

void dump (void *p, int n) {
  unsigned char *p1 = p;
  while (n--) {
    printf("%p - %02x\n", p1, *p1);
    p1++;
  }
}

int main (void) {
	int i;
	int j;
	char c;
	scanf(" %d", &i);
	dump(&i, sizeof(i));
	//printf("Inteiro: %d\n", i);
	scanf(" %x", &j);
	dump(&j, sizeof(j));
	//printf("Hexadecimal: %x\n", j);
	scanf(" %c", &c);
	dump(&c, sizeof(c));
	//printf("Char: %c\n", c);
	return 0;
}