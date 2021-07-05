#include <iostream>

using namespace std;

struct tCircuito{
  float R1;
  float R2;
  float V1;

  void imprime(){
    cout << "R1: "<< R1<< "  R2: "<< R2<< "  V1: "<< V1 << endl;
    
  }

  //soma das resistencias
  float calculaResistenciaEmSerie(){
    return R1 + R2; //ohms  
  }

  // 1/{(1/R1) + (1/R2) + ... +(1/Rn)}
  float calculaResistenciaEmParalelo(){
    return 1/((1/R1)+(1/R2));  //ohms    
  }
  
  //utilizado a formula para circuito em paralelo
  float calculaCorrenteTotal(){
    float IR1 = V1/R1; // Corrente do resistor R1 
    float IR2 = V1/R2; // Corrente do resistor R2
    float It = IR1 + IR2; // corrente total

    return It; //Amperes    
  }

//utilizando o calculo da corrente já implementado
//P=V.I
float calculaPotencia(){
  return V1 * calculaCorrenteTotal(); //Watts
}

};

