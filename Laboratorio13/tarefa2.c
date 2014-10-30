#include <math.h>
#include <stdio.h>

#define makefloat(s,e,m) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((m) & 0x7fffff))

typedef union {
	float f;
	unsigned int i;
} U;

unsigned int getexp(int i){
	int valor = 0, cont = 0;
	unsigned int um = 0x80000000;
	while(valor == 0) {
		cont ++;
		valor = i & (um >> cont);
	}
	return 31-cont;
}

unsigned int getmant(int i, unsigned int e){
	unsigned int m, um = 0xffffffff;
	um = um >> (31 - e + 1);
	m = i & um;
	if(e > 23)
		return m >> (e-23);
	return m << (23-e);
}

float int2float(int i) {
	U u;
	unsigned int s, e, m;
	if (i == 0){
		s = 0;
		e = 0;
		m = 0;
	}
	else if(i > 0){
		s = 0;
		e = getexp(i);
		m = getmant(i, e);
	}
	else{
		s = 1;
		e = getexp(i);
		m = getmant(i, e);
	}
	e+=127;
	u.i = makefloat(s,e,m);
	return u.f;
}

int main (void) {
	float f;
	f = int2float(100);
	printf("100 = %f\n",f);
	return 0;
}