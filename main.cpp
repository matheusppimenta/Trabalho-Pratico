#include <iostream>
#include "ListaEncadeada.h"

using namespace std;

void gravarListaNoArquivo(tLista * lista){
  FILE *arq;
  int i;
  int result;

    
  // Cria um arquivo texto para gravação
  arq = fopen("bancoDeDados.txt", "a+");  
  
// Se não conseguiu criar arquivo
  if (arq == NULL) 
  {
     cout << "Problemas na CRIACAO do arquivo"<<endl;
     return;
  }

  tInfo x;
  int erro = 0;

  primeiro(lista);

  while(!fim(lista)){
    x = obterInfo(lista , &erro);
    if(!erro){
      result = fprintf(arq,"R1: %f\nR2: %f\nV1: %f\n",x.valor.R1,x.valor.R2,x.valor.V1);  	
      if (result == EOF)		    
	      cout<< "Erro na Gravacao"<<endl;
    }
    proximo(lista);
  }  
 fclose(arq);
}

void carregarListaDeArquivo(tLista * lista){
  FILE *arq;
  char Linha[100];
  char *result;

  // Abre um arquivo TEXTO para LEITURA
 arq = fopen("bancoDeDados.txt", "rt");
  if (arq == NULL)  
  {
     cout << "Problemas na abertura do arquivo"<<endl;
     return;
  }
    
  while (!feof(arq))
  {
    
    tCircuito circuito;
	  // Lê  linha de R1
    result = fgets(Linha, 100, arq);  
    if (result){ 
      string info = Linha;
      circuito.R1 = stof(info.substr(4, info.length()));        
    }

    // Lê  linha de R2
    result = fgets(Linha, 100, arq);  
    if (result){
      string info = Linha;
      circuito.R2 = stof(info.substr(4, info.length()));        
    }

    // Lê  linha de V1
    result = fgets(Linha, 100, arq);  
    if (result){
      string info = Linha;
      circuito.V1 = stof(info.substr(4, info.length()));   
      incluirFim(lista, circuito);     
    }  
  }
fclose(arq);
   

}


int main() {

  int opcao = 0;  
  
  do{
    cout << "---------------//---------------" << endl;
    cout << "Digite 1 para gravar no banco de dados."<< endl;
    cout << "Digite 2 para ler do banco de dados."<< endl;
    cout << "Digite 0 para encerrar."<< endl;
    cin >> opcao;

    if(opcao == 1){
      tLista lista;    
      iniciaLista(&lista);

      int qtd = 0;
      cout << "Digite a quantidade de Circuitos Eletricos deseja armazenar."<< endl;
      cin >>qtd;

      int i;
      for(i=0; i<qtd; i++){
        tCircuito circuito;
        cout << "Digite o valor de R1 do Circuito "<<i+1<<":"<< endl;
        cin >> circuito.R1;

        cout << "Digite o valor de R2 do Circuito "<<i+1<<":"<< endl;
        cin >> circuito.R2;

        cout << "Digite o valor de V1 do Circuito "<<i+1<<":"<< endl;
        cin >> circuito.V1;

        incluirFim(&lista, circuito);
      }
      gravarListaNoArquivo(&lista);
    }
    if(opcao == 2){
      tLista lista;    
      iniciaLista(&lista);
      carregarListaDeArquivo(&lista);
      imprimeLista(&lista);
    }


  }while(opcao !=0);
    
}