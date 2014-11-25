#include <stdio.h>
#include "corotinas.h"

int ping(int par) {
	int x = 0;
	while(1){
		printf("ping: %d\n", par);
		par += 2;
		coro_yield(par);
	}
	return -1;
}

int pong(int parametro) {
	int y = 0;
	while(1){
		printf("pong: %d\n",parametro);
		parametro += 2;
		coro_yield(parametro);
	}
	return -1;
}

int main(void){
	CoroP b = coro_create("ping", ping);
	CoroP c = coro_create("pong", pong);
	int i,j = 0;

	for(i=0; i<5; i++){
		coro_resume(b, j);
		j++;
		printf("main: %d\n", i);
		coro_resume(c, j);
		printf("main: %d\n", i);
	}

	j = coro_resume(b,0);
	j = coro_resume(c,0);
	return 0;
}