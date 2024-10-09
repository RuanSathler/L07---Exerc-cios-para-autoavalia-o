#include <stdio.h>

int LerInt(){
  int numLido;
  scanf("%d", &numLido);

  return numLido;
}

int main(){

  int menorPar, prox, encontrouPar;  

  encontrouPar = 1;
  menorPar = 1;
  
  while((prox = LerInt()), prox !=-1){
    
    if((prox%2)==0 && encontrouPar == 1){
      menorPar = prox;
      encontrouPar = 0;
    }    


    if((prox%2)==0 && prox<menorPar && encontrouPar==0){
      menorPar = prox;
    }
  }
  
  if((menorPar%2)==0) printf("%d\n", menorPar);
  else printf(":(\n");
  
  return 0;  
}
