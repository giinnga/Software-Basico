#include <stdio.h>
#include <stdlib.h>
#include "compiler.h"
#define	NUMERO_BEM_GRANDE 1000
#define NUM_VAR_LOCAIS 5

typedef unsigned char * Code;

typedef union num
{
	int i;
	unsigned char b[4];
} N_union;

typedef struct line_if{

	int wanted_line;
	int index_to_change;

	struct line_if * ant;
	struct line_if * prox;

} Line;

Line * cria_no (Line * iterador_lista, int wanted_line, int index_to_change)
{
	Line * lista = (Line *) malloc(sizeof(Line));

	if(iterador_lista != NULL)
		iterador_lista->ant = lista;

	lista->wanted_line = wanted_line;
	lista->index_to_change = index_to_change;
	lista->prox = iterador_lista;

	return lista;
}

Line* destroi_no (Line * iterador_lista){

	Line * temp;

	if( iterador_lista->ant == NULL)
	{
		temp = iterador_lista->prox;
		temp->ant = NULL;
		free(iterador_lista);
	}
	else
	{
		temp = iterador_lista->ant;
		temp->prox = iterador_lista->prox;
		free(iterador_lista);
	}

	return temp;
}

int check_line (Line * iterador_lista, int line){

	int i;

	if(iterador_lista == NULL)
		return -1;

	if(iterador_lista->wanted_line == line)
	{	
		i = iterador_lista->index_to_change;
		iterador_lista = destroi_no(iterador_lista);
		return i;
	}

	return check_line(iterador_lista-> prox, line);
}


int main(void){
	int check;
	Line *lit = NULL;
	lit = cria_no(lit,2,3);
	lit = cria_no(lit,4,5);
	lit = cria_no(lit,6,7);
	check = check_line(lit,2);
	printf("\nIndex to change: %d\n\n",check);
	check = check_line(lit,2);
	printf("\nIndex to change: %d\n\n",check);
	return 0;
}