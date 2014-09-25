#include <stdio.h>
#include "utfconv.h"

int main (void) {
	FILE *arq_entrada, *arq_saida;
	arq_entrada = fopen("utf8.txt", "r");
	if(arq_entrada == NULL) {
		printf("Erro na abertura do arquivo!\n");
		exit(1);
	}
	arq_saida = fopen("utf32.txt", "w");
	if(arq_saida == NULL) {
		printf("Erro na abertura do arquivo!\n");
		exit(1);
	}
	conv8_32(arq_entrada, arq_saida, L);
	return 0;
}