#include <stdio.h>

double foo(double a, int b);

int main(void)
{
	double a = 3;
	int b = 2;
	double c = foo(a,b);
	printf("\n%f\n",c);
	return 0;
}