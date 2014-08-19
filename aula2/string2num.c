#include <ctype.h>
#include <stdio.h>

int string2num (char *s,int base) {
	int a = 0;
	for (; *s; s++){ //*s -> *s!=0
		a = a*base + (*s - '0');
		printf("a: %d / s: %c\n",a, *s);
	}
	return a;
}

int main (void) {
	printf("%d\n", string2num("777", 8));
	printf("%d\n", string2num("777", 10));
	printf("%d\n", isdigit('1'));
	return 0;
}