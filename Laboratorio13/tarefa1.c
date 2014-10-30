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
	if(s == 0 && e == 0xff && m == 0)
		return 0;
	if(e == 0xff)
		return NAN;
	e++;
	u.i = makefloat(s,e,m);
	return u.f;
}

int main (void) {
	float f;
	f = float2(2);
	printf("%f\n",f);
	return 0;
}