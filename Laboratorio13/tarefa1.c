#include <math.h>
#include <stdio.h>

#define getsig(x)  ((x)>>31 & 1)
#define getexp(x)  ((x)>>23 & 0xff)
#define getmant(x) ((x) & 0x7fffff)
#define makefloat(s,e,m) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((m) & 0x7fffff))

typedef union {
	float f;
	unsigned int i;
} U;

float float2(float f) {
	U u;
	unsigned int s, e, m, ui;
	u.f = f;
	ui = u.i;
	s = getsig(ui);
	e = getexp(ui);
	m = getmant(ui);
	if(s == 0 && e == 0 && m == 0)
		
	e++;
	u.i = makefloat(s,e,m);
	return u.f;
}

int main (void) {
	float f = 1;
	f2 = float2(f);
	printf("%f\n",f2);
	return 0;
}