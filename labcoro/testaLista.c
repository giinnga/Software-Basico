#include <stdio.h>
#include <values.h>
#include "corotinas.h"
#include "listainteiros.h"

int main(void) {

  ListaInteiros *l1 = listaCria();
  ListaInteiros *l2 = listaCria();

  l1 = listaInsere(l1, 1);
  l1 = listaInsere(l1, 2);
  l1 = listaInsere(l1, 3);
  l1 = listaInsere(l1, 4);
  l1 = listaInsere(l1, 5);

  l2 = listaInsere(l2, 2);
  l2 = listaInsere(l2, 5);
  l2 = listaInsere(l2, 1);

  /* insira aqui o codigo novo */

  void *iterador1;
  void *iterador2;
  iterador1 = criaIterador(l1);
  iterador2 = criaIterador(l2);

  printf("Soma lista 1: %d\n",soma(iterador1, l1));
  printf("Soma lista 2: %d\n",soma(iterador2, l2));

  destroiIterador(iterador1);
  destroiIterador(iterador2);
  
  iterador1 = criaIterador(l1);
  iterador2 = criaIterador(l2);

  printf("Produto lista 1: %d\n",mult(iterador1));
  printf("Produto lista 2: %d\n",mult(iterador2));

  destroiIterador(iterador1);
  destroiIterador(iterador2);

  /*                           */

  listaLibera(l1);
  listaLibera(l2);

  return 0;
}

int soma(void *iterador, ListaInteiros *lista){
  int cont=0;
  int soma=0;
  
  soma = ativaIterador(iterador);
  while(soma != MININT){
    cont += soma;
    soma = ativaIterador(iterador);
  }
  return cont;
}

int mult(void *iterador){
  int produto = 1;
  int cont = 0;
  cont = ativaIterador(iterador);
  while(cont != MININT){
    produto = produto * cont;
    cont = ativaIterador(iterador);
  }
  return produto;
}