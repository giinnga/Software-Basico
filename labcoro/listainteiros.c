#include <stdlib.h>
#include <values.h>
#include "corotinas.h"
#include "listainteiros.h"

struct noLista {
  int info;
  struct noLista *prox;
};

ListaInteiros *listaCria(void) {
  return NULL;
}

ListaInteiros *listaInsere(ListaInteiros *l, int v) {
  ListaInteiros *n = (ListaInteiros *) malloc(sizeof(ListaInteiros));
  if (n != NULL) {
    n->info = v;
    n->prox = l;
  }
  return n;
}

void listaLibera(ListaInteiros *l) {
  ListaInteiros *prox, *n = l;
  while (n != NULL) {
    prox = n->prox;
    free(n);
    n = prox;
  }
}

/*
 * Corpo da corotina que implementa o iterador 
 */
static CoroParam iteraLista (CoroParam lista) {

  /* Guarda a lista que deve ser "iterada" */
  ListaInteiros *l = (ListaInteiros *) lista;

  /* Retorna o controle para quem a iniciou */
  coro_yield((CoroParam) 0);

  /* preencha o resto do código! */
  while(l != NULL){
    coro_yield((CoroParam) l->info);
    l = l->prox;
  }
  return MININT;
}

/*
 * Cria uma corotina com corpo iteraLista
 *  para percorrer a lista
 */
void *criaIterador (ListaInteiros *l) {
  /* preencha o resto do código! */
  CoroP iterador = coro_create("iter",(CoroBody)iteraLista);
  coro_resume(iterador,(int)l);
  return (void *)iterador; 
}

int ativaIterador (void *iterador) {
  /* preencha o resto do código! */
  return coro_resume(iterador,0);
}

void destroiIterador (void *iterador) {
  /* preencha o resto do código! */
  coro_free(iterador);
  return;
}
