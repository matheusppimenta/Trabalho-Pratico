#ifndef LISTAENCADEADA_H_
#define LISTAENCADEADA_H_

#include "CircuitoEletrico.cpp"


// **********  definição das estruturas ************************************
typedef struct info{
    //estrutura de Circuitos elétricos, do exercício avaliativo 3
    tCircuito valor;
}tInfo;

//estrutura nó da lista
typedef struct no{
    tInfo informacao;   //informação guardada pelo nó
    struct no *proximo;
}tNo;   //apelido

typedef struct lista{
    tNo *primeiro;
    tNo *ultimo;
    tNo *marcador;
    int tamanho;
}tLista;
// **********  definição das estruturas ************************************


tNo* criaNo(tInfo elemento);
int fim(tLista * lista);
int obterTam(tLista * lista);
int vazia(tLista * lista);
void incluirFim(tLista * lista, tCircuito elem);
void primeiro(tLista * lista);
void proximo(tLista * lista);
tInfo obterInfo(tLista * lista, int *erro);
void iniciaLista(tLista* lista);
void imprimeLista(tLista* lista);


#endif