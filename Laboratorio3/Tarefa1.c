#include <stdio.h>

unsigned int mul (unsigned int a, unsigned int b) {
	unsigned int p = 0;
	while (b) {
		if (b%2 == 1)
			p += a;
		a *= 2;
		b /= 2;
	}
	return p;
}

unsigned int multiplica_bitAbit (unsigned int a, unsigned int b) {
	unsigned int p = 0;
	while(b){
		if(b & 0x00000001)
			p += a;
		a = a << 1;
		b = b >> 1;
	}
	return p;
}

int main (void) {
	unsigned int c,d;
	c = mul(3,5);
	d = multiplica_bitAbit(3,5);
	printf("%d %d", c, d);
	return 0;
}