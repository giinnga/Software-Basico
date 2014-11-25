#include <stdio.h>
#include <stdlib.h>
#include "compiler.h"

int main (void){
	int retorno;
	funcp f;

	FILE* arq_fonte = fopen("codigo.min", "r");
	if(arq_fonte == NULL){
		fprintf(stderr, "Ńao conseguiu abrir o arquivo de entrada\n");
		exit(1);
	}

	f = geracod(arq_fonte);

	retorno = (*f)(2,3,4,5,6);

	printf("\nCódigo:\nv0 := $0 + $0\nv1 := p0 - p2\nv2 := p2 * v1\nv3 := v2 + p2\nv4 := p3 - p3\nret v4\n");
	printf("\nO retorno do seu array foi : %d\n\n",retorno);

	return 0;

}