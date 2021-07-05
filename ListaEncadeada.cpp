#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"


//função para criação dos nós
tNo* criaNo(tInfo elemento){
    tNo *no = (tNo *)malloc(sizeof(tNo));    
    no -> informacao = elemento;
    no -> proximo = NULL;    
    return no;
}

//verifica de o marcador aponta para o final
int fim(tLista * lista){
  return (lista -> marcador == NULL);
}

//retorna tamanho da lista
int obterTam(tLista * lista){
  return lista -> tamanho;
}

int vazia(tLista * lista){
  return (lista -> tamanho == 0);
}

//função para adicionar um novo "CircuitoEletrico" na lista
void incluirFim(tLista * lista, tCircuito elem){
  tNo *no;
  tInfo infoCircuito;    
  infoCircuito.valor = elem;    
  no = criaNo(infoCircuito);
  if(vazia(lista)){
    lista -> primeiro = no;
  }else{
    lista -> ultimo -> proximo = no;
  }
  lista ->ultimo = lista ->marcador = no;
  lista ->tamanho++;   
}

//posiciona o marcador no começo da lista
void primeiro(tLista * lista){
  lista ->marcador = lista ->primeiro;
}

//posiciona o marcado no proximo nó da lista
void proximo(tLista * lista){
  if(lista -> marcador != NULL){
    lista -> marcador = lista -> marcador ->proximo;
  }
}

//recupera a informação do nó que está no marcador
tInfo obterInfo(tLista * lista, int *erro){
  if(lista ->marcador == NULL){
    *erro = 1;   
  }
  *erro = 0;
  return lista -> marcador -> informacao;
}

void iniciaLista(tLista* lista){
    lista -> primeiro = NULL;
    lista -> ultimo = NULL;
    lista -> marcador = NULL;
    lista -> tamanho = 0;
}

void imprimeLista(tLista* lista){
  tInfo x;
  int erro = 0;
  primeiro(lista);
  while(!fim(lista)){
    x = obterInfo(lista , &erro);
    if(!erro){
      x.valor.imprime();
    }
    proximo(lista);
  }
}